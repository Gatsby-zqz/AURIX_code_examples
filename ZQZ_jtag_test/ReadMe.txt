#V0.1  2024-0201
| Version | Author | comment|
|------|--------|--------|
|0.1|Gao jianzheng| Initial Version|
||Lou Jue| 更新readme|
| Gao jianzheng| add profpga, hex op change arg in form file ,other fixed|
   设计libusb/V-COM的windows平台工作。沿用当前编程器协议 68(格式头) xx(功能码)  mmnn(数据长度) (长度下数据) Sum(加和验证码） ~sum(取反的校验码） 16（格式尾) 
   使用环境  python
   安装库    python -m pip install pyserial pyusb libusb intelhex   
   
## 如果内网的话在FTP下载python lib 解压
*	安装python
*	安装库（在ftp /comm/soft/FPGA/20210115/python_libs.zip）
```
pip install -r requirements.txt --no-index --find-links=<解压包的路径>
```

   设计命令驱动 JTAG
	y  退出
	source filename  逐行解析命令与执行,支持空行，#起始作为注释行标识
	retry  重复上一个命令
	delay N 延时函数Nms
	shell  执行外部程序
	部分命令具有参数，参数可以直接写数值，也可以自定别名，如 power=50，按顺序传递，名支持的被忽略

# 链接关系

| Name		| FPGA（zynq）	| PCB（zynq）	| FPGA(uv19)		| PCB(IO)	| KungFu Jtag（蓝色临时）	|
|------		|--------------	|-------------	|-----			|-----		|----------------------		|    
| TCK		| V5		| J4.1		| 283(FMC1 H4)		| CN6.10	| CLK				| 
| TDI		| U5		| J4.3		| 295(FMC H16)		| CN6.6		| DAT				| 
| TDO		| V7		| J4.5		| 292(FMC1 H13)		|CN6.14		| Rx				| 
| TDO_OE	| W8		| J4.7		| --			|--		| --				|  
| TMS		| U10		| J4.11		| 293(FMC1 H14)		|CN6.8		| Tx				|
| TRST		| W6		| J4.13		| 290(FMC1 H11)		| CN6.4		| Mode				| 
| 		| 3.3V		| 		| 			| 		| VDD				| 

## 自定义
	cumstom xxxx
	自定义数据帧报文，用于特定下位机命令的处理，如68e400004cb316（获取设备信息)

## 启动激活调试
	enter mode=x version=0x01 power=50 chipcode=4 feature=0x00 N X
		#按顺序，=前后不能有空格，参数量不能少  
		#1 模式，bit7 是否恢复idle.
			 bit6 默认RST引脚控制

			 bit5 若供电前是否预放电 32ms
			 bit4 工作态RST引脚结果
			 bit3  是否序列解锁
			 bit2  是否DMI接口控制复位和更新state_dmi
			 bit1  是否密钥解锁
			 bit0  rev
			   
		#2 版本，默认0x01
		#3 电压，单位100mV ，暂固定5V
		#4 芯片，默认4，工具对内核的编码
		#5 特性，默认0x00,具体根据后续具有差异是的用于区分
		#6 秘钥长度，最大32bits
		#7 秘钥值，32位序列值
		#8 序列码  16
		#9 序列值  128
	如：enter Mode=0x3C Version=0x01 Power=50 Chip=4 Feature=0x00 SerNum=32 SerCode=0x55AAAA66
	如：enter Mode=0x3F Version=0x01 Power=33 Chip=4 Feature=0x40 SerNum=32 SerCode=0x55AAAA66 KeyCount=8 KeyValue=01020304F1F2F3F4112233445566778811020304F1F2F3F41122334455667789
    enter Mode=0x30 Version=0x01 Power=33 Chip=4 Feature=0x40 SerNum=32 SerCode=0x55AAAA66 KeyCount=8 KeyValue=0000000000000000000000000000000000000000000000000000000000000000

## 退出调试
	abort  feature=x
		断点有应用清理，这里仅一般动作控制，包括内核选择等也应用管理
		
		bit7  配置是否拉取复位脚的复位
		bit6  若编程器供电时，是否不不做任何变动的静默退出
		bit5  退出时持续拉低复位引脚
		bit4  是否释放ck do di引脚
		bit3  rev
		bit2  rev
		bit1  rev
		bit0  rev
		如 abort 0xD0
## 多核cpu选择
	setCPU  XXXXYYYY
	其中Y和X对于16bits的short，分别对应高与低的选择码值.如setCPU 0x00010011
## 运行
	run  
	无参，有参被忽略的执行，如run   或 run  0
	其结合setCPU选择的处理器的执行
## 暂停
	halt
	无参，有参被忽略的执行，如halt   或 halt  0
	其结合setCPU选择的处理器的执行
## 单步
	step [N]
	无参，有参的单步的次数，如step 1
	其结合setCPU选择的处理器的执行
## 复位与运行
	reset
	无参，有参被忽略的执行，如reset   或reset  0
## 复位与暂停
	hreset
	无参，有参被忽略的执行，如hreset   或hreset  0
	
## 读取资源
	read addr  length interface mode
	读取内存，包括Flash Ram SFR，其中addr与length要求4字节对齐
	interface: 0 内存   1 编程  2 系统纵向
	mode: 0单次循环   1 块模式循环
	注：编程模式需要最终实现的暂未支持

## 写入资源
	wirte addr  length interface mode [数据]
	写入内存，包括 Ram SFR，其中addr与length要求4字节对齐
	interface: 0 内存   1 编程  2 系统纵向
	mode: 0单次循环   1 块模式循环
	datalist: 安装无空格和前缀的16进制连写，如“12345678” 对于0x12345678
	注：编程模式需要最终实现的暂未支持
## 断点配置
	point num=0 typecode=2  address=0x200 endaddress=0x204 feature=0x00
	断点分 指令断点与监控断点，而基于riscv的为一组机制，即2对可构成范围断点，可配置为地址或load或store的匹配
	这里使用起始号和类型的接口，考虑范围的设定尾地址直接写入芯片的，起始和长度计算尾有上位机实施
	num:  0  1  2  3 4 5 6 7 
	typdecode: 0xXY 
	X	bit7	chain
		bit6	pc point ,execute
		bit5	load as watch
		bit4	stroe as watch
	Y	bit3-bit0
			0   单个资源的关闭断点
			1   范围资源的关闭断点
			2   一般意义地址断点
			3   地址范围断点
			4  一般监控点
			5  范围监控点
	feature
		bit7    address or isrordata. 0 means execute under == or with > < and address
		bit6-bit4	size sel : 0  8 16 32 64
		bit3-bit0       match      0  2  3

## 断点信息
	info num=x

## JTAG空闲
	idel
	tms=1,n次循环到空闲状态
## 状态
	state 
	注：应该显示调试状态，包括是否具有内核停机信息，待定，即接口最终为准
	
## 手动DMI
	senddmi N op_V  addr_V Value_V
	编程器支持N为多个的  o a v序列对，这里脚本仅支持单个，如senddmi 1 0 0x7F 0x12345678
	按 OP addr Value 的对于命令的结果值返回

## 手动命令
	sendisa  N  onelength onevalue
	编程器支持N为多个的  L V序列对，这里脚本仅支持单个，如sendisa  1 0x07 0x11
## 手动数据
	senddata Value_V  [len]
	默认长度为32bit
	用于和命令结合的直接32位和以下的控制或返回的数据驱动
	如senddata 	0xFF001234  32
## 内核寄存器写
	corewrite reg_num value#imm32
	corewrite reg_num value#imm32	X64 value#imm32
## 内核寄存器读
	coreread  reg_num  
	coreread  reg_num  X64
	控制台显示值

## 加载代码到模拟器
	profpga1
	加载解析的代码，按写入资源的循环下发到设备，即代码到fpga的模拟ram资源
	
# 实例命令

custom 68e400004cb316
enter Mode=0x3C Version=0x01 Power=50 Chip=4 Feature=0x00 SerNum=32 SerCode=0x55AAAA66
run 0
halt 0
step 1
reset 0
hreset 0
read addr=4 length=4 interfacet=0 mode=1
write addr=4 length=4 interfacet=0 mode=1 value="12345678"

point num=0 typecode=2  address=0x200 endaddress=0x204 feature=0x00

idle
state
setCPU 0x01
senddmi 1 0 0x7F 0x12345678

sendisa  1 0x07 0x11

corewrite 0x1010 0x12345678
coreread 0x1010



abort 0xD0