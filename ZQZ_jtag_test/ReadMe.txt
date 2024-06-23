#V0.1  2024-0201
| Version | Author | comment|
|------|--------|--------|
|0.1|Gao jianzheng| Initial Version|
||Lou Jue| ����readme|
| Gao jianzheng| add profpga, hex op change arg in form file ,other fixed|
   ���libusb/V-COM��windowsƽ̨���������õ�ǰ�����Э�� 68(��ʽͷ) xx(������)  mmnn(���ݳ���) (����������) Sum(�Ӻ���֤�룩 ~sum(ȡ����У���룩 16����ʽβ) 
   ʹ�û���  python
   ��װ��    python -m pip install pyserial pyusb libusb intelhex   
   
## ��������Ļ���FTP����python lib ��ѹ
*	��װpython
*	��װ�⣨��ftp /comm/soft/FPGA/20210115/python_libs.zip��
```
pip install -r requirements.txt --no-index --find-links=<��ѹ����·��>
```

   ����������� JTAG
	y  �˳�
	source filename  ���н���������ִ��,֧�ֿ��У�#��ʼ��Ϊע���б�ʶ
	retry  �ظ���һ������
	delay N ��ʱ����Nms
	shell  ִ���ⲿ����
	����������в�������������ֱ��д��ֵ��Ҳ�����Զ��������� power=50����˳�򴫵ݣ���֧�ֵı�����

# ���ӹ�ϵ

| Name		| FPGA��zynq��	| PCB��zynq��	| FPGA(uv19)		| PCB(IO)	| KungFu Jtag����ɫ��ʱ��	|
|------		|--------------	|-------------	|-----			|-----		|----------------------		|    
| TCK		| V5		| J4.1		| 283(FMC1 H4)		| CN6.10	| CLK				| 
| TDI		| U5		| J4.3		| 295(FMC H16)		| CN6.6		| DAT				| 
| TDO		| V7		| J4.5		| 292(FMC1 H13)		|CN6.14		| Rx				| 
| TDO_OE	| W8		| J4.7		| --			|--		| --				|  
| TMS		| U10		| J4.11		| 293(FMC1 H14)		|CN6.8		| Tx				|
| TRST		| W6		| J4.13		| 290(FMC1 H11)		| CN6.4		| Mode				| 
| 		| 3.3V		| 		| 			| 		| VDD				| 

## �Զ���
	cumstom xxxx
	�Զ�������֡���ģ������ض���λ������Ĵ�����68e400004cb316����ȡ�豸��Ϣ)

## �����������
	enter mode=x version=0x01 power=50 chipcode=4 feature=0x00 N X
		#��˳��=ǰ�����пո񣬲�����������  
		#1 ģʽ��bit7 �Ƿ�ָ�idle.
			 bit6 Ĭ��RST���ſ���

			 bit5 ������ǰ�Ƿ�Ԥ�ŵ� 32ms
			 bit4 ����̬RST���Ž��
			 bit3  �Ƿ����н���
			 bit2  �Ƿ�DMI�ӿڿ��Ƹ�λ�͸���state_dmi
			 bit1  �Ƿ���Կ����
			 bit0  rev
			   
		#2 �汾��Ĭ��0x01
		#3 ��ѹ����λ100mV ���ݹ̶�5V
		#4 оƬ��Ĭ��4�����߶��ں˵ı���
		#5 ���ԣ�Ĭ��0x00,������ݺ������в����ǵ���������
		#6 ��Կ���ȣ����32bits
		#7 ��Կֵ��32λ����ֵ
		#8 ������  16
		#9 ����ֵ  128
	�磺enter Mode=0x3C Version=0x01 Power=50 Chip=4 Feature=0x00 SerNum=32 SerCode=0x55AAAA66
	�磺enter Mode=0x3F Version=0x01 Power=33 Chip=4 Feature=0x40 SerNum=32 SerCode=0x55AAAA66 KeyCount=8 KeyValue=01020304F1F2F3F4112233445566778811020304F1F2F3F41122334455667789
    enter Mode=0x30 Version=0x01 Power=33 Chip=4 Feature=0x40 SerNum=32 SerCode=0x55AAAA66 KeyCount=8 KeyValue=0000000000000000000000000000000000000000000000000000000000000000

## �˳�����
	abort  feature=x
		�ϵ���Ӧ�����������һ�㶯�����ƣ������ں�ѡ���ҲӦ�ù���
		
		bit7  �����Ƿ���ȡ��λ�ŵĸ�λ
		bit6  �����������ʱ���Ƿ񲻲����κα䶯�ľ�Ĭ�˳�
		bit5  �˳�ʱ�������͸�λ����
		bit4  �Ƿ��ͷ�ck do di����
		bit3  rev
		bit2  rev
		bit1  rev
		bit0  rev
		�� abort 0xD0
## ���cpuѡ��
	setCPU  XXXXYYYY
	����Y��X����16bits��short���ֱ��Ӧ����͵�ѡ����ֵ.��setCPU 0x00010011
## ����
	run  
	�޲Σ��вα����Ե�ִ�У���run   �� run  0
	����setCPUѡ��Ĵ�������ִ��
## ��ͣ
	halt
	�޲Σ��вα����Ե�ִ�У���halt   �� halt  0
	����setCPUѡ��Ĵ�������ִ��
## ����
	step [N]
	�޲Σ��вεĵ����Ĵ�������step 1
	����setCPUѡ��Ĵ�������ִ��
## ��λ������
	reset
	�޲Σ��вα����Ե�ִ�У���reset   ��reset  0
## ��λ����ͣ
	hreset
	�޲Σ��вα����Ե�ִ�У���hreset   ��hreset  0
	
## ��ȡ��Դ
	read addr  length interface mode
	��ȡ�ڴ棬����Flash Ram SFR������addr��lengthҪ��4�ֽڶ���
	interface: 0 �ڴ�   1 ���  2 ϵͳ����
	mode: 0����ѭ��   1 ��ģʽѭ��
	ע�����ģʽ��Ҫ����ʵ�ֵ���δ֧��

## д����Դ
	wirte addr  length interface mode [����]
	д���ڴ棬���� Ram SFR������addr��lengthҪ��4�ֽڶ���
	interface: 0 �ڴ�   1 ���  2 ϵͳ����
	mode: 0����ѭ��   1 ��ģʽѭ��
	datalist: ��װ�޿ո��ǰ׺��16������д���硰12345678�� ����0x12345678
	ע�����ģʽ��Ҫ����ʵ�ֵ���δ֧��
## �ϵ�����
	point num=0 typecode=2  address=0x200 endaddress=0x204 feature=0x00
	�ϵ�� ָ��ϵ����ضϵ㣬������riscv��Ϊһ����ƣ���2�Կɹ��ɷ�Χ�ϵ㣬������Ϊ��ַ��load��store��ƥ��
	����ʹ����ʼ�ź����͵Ľӿڣ����Ƿ�Χ���趨β��ֱַ��д��оƬ�ģ���ʼ�ͳ��ȼ���β����λ��ʵʩ
	num:  0  1  2  3 4 5 6 7 
	typdecode: 0xXY 
	X	bit7	chain
		bit6	pc point ,execute
		bit5	load as watch
		bit4	stroe as watch
	Y	bit3-bit0
			0   ������Դ�Ĺرնϵ�
			1   ��Χ��Դ�Ĺرնϵ�
			2   һ�������ַ�ϵ�
			3   ��ַ��Χ�ϵ�
			4  һ���ص�
			5  ��Χ��ص�
	feature
		bit7    address or isrordata. 0 means execute under == or with > < and address
		bit6-bit4	size sel : 0  8 16 32 64
		bit3-bit0       match      0  2  3

## �ϵ���Ϣ
	info num=x

## JTAG����
	idel
	tms=1,n��ѭ��������״̬
## ״̬
	state 
	ע��Ӧ����ʾ����״̬�������Ƿ�����ں�ͣ����Ϣ�����������ӿ�����Ϊ׼
	
## �ֶ�DMI
	senddmi N op_V  addr_V Value_V
	�����֧��NΪ�����  o a v���жԣ�����ű���֧�ֵ�������senddmi 1 0 0x7F 0x12345678
	�� OP addr Value �Ķ�������Ľ��ֵ����

## �ֶ�����
	sendisa  N  onelength onevalue
	�����֧��NΪ�����  L V���жԣ�����ű���֧�ֵ�������sendisa  1 0x07 0x11
## �ֶ�����
	senddata Value_V  [len]
	Ĭ�ϳ���Ϊ32bit
	���ں������ϵ�ֱ��32λ�����µĿ��ƻ򷵻ص���������
	��senddata 	0xFF001234  32
## �ں˼Ĵ���д
	corewrite reg_num value#imm32
	corewrite reg_num value#imm32	X64 value#imm32
## �ں˼Ĵ�����
	coreread  reg_num  
	coreread  reg_num  X64
	����̨��ʾֵ

## ���ش��뵽ģ����
	profpga1
	���ؽ����Ĵ��룬��д����Դ��ѭ���·����豸�������뵽fpga��ģ��ram��Դ
	
# ʵ������

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