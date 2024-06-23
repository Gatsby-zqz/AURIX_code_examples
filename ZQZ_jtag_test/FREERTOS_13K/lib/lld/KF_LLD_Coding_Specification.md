# <p style="text-align:center;">ChipON 代码规范(试用)</p>
<div style="text-align:center; margin-top:30%">
<div style="display:inline-block">
<p style="text-align:left">版本:0.1</p>
<p style="text-align:left">作者:翟宇</p>
<p style="text-align:left">日期:2023.09.28</p>
</div>
</div>
<!-- pagebreak -->
[<p style="text-align:center;">ChipON 代码规范(试用)</p>](#chipon-kf32-代码规范试用)
- [一.推荐工具](#一推荐工具)
- [二.注释规范](#二注释规范)
- [三.命名规范](#三命名规范)
- [四.LLD规范](#四LLD规范)
- [五.测试规范](#五测试规范)
- [六.参考文档](#六参考文档)

---
<!-- pagebreak -->

| 版本  |    日期    | 作者  |    描述     |
| :---: | :--------: | :---: | :---------: |
|  0.1  | 2023/9/28  | 翟宇  |    初版     |
|  0.2  | 2023/12/06 | 尉星  | 添加LLD要求 |


---
<!-- pagebreak -->

## 一.推荐工具 {#一推荐工具}
- 开发工具  
    推荐使用最新版本的vscode作为统一的代码编辑工具。方便自动补全、颜色高亮、格式对齐、以及定义查询。可以有效的避免当前IDE编辑中容易出现的变量名写错，函数引用忘记声明等操作失误。推荐安装以下几个vscode插件:
    - C/C++
    - Todo Tree
    - Doxygen Documentation Generator
    - Markdown Preview Enhanced

- git  
    借助git版本控制工具，可以方便追溯开发过程。建议开发人员创建个人git仓库，从服务器分支fork后进行开发。合并前提交pull request并进行不少于三人的内容评审。一致同意后合并入主仓库。Git的本地提交推荐细粒化，独立性，一次更改提交只限定在有限的逻辑关联的范围内，便于文件的更改回溯查询。
- 编码   
    - **所有文件编码格式均必须使用UTF-8格式**（待定）
    - 代码编辑器中的字体推荐使用等宽字体，避免混淆`1`和`l`，`2`和`Z`，`5`和`S`，`0`和`O` ，`n`和`h`等等。如“Titillium Web”，“Open Sans”等免费可商用的字体。
- .clang-format
  **使用统一的格式工具，避免协同开放时因格式导致的大量合并冲突**
---
<!-- pagebreak -->

## 二.注释规范 {#二注释规范}
- 源文件和头文件的注释方式参考Doxygen注释规范中的`@`格式
    ```c
        /**
          * @brief Get Current Item Count base on itemsize
          * 
          * @param queue pointer to Queue Struct
          * @return size_t Total num of Item in Queue
          * @retval size_t Total num of Item in Queue
          */
    ```
- 行注释建议使用，行注释建议放于注释对象的上方，减少行的长度。 
    ```c
        /** ...... */ 
        /*…... */
    ```
- Doxygen常用注释命令，具体可查阅[Doxygen命令手册](https://www.doxygen.nl/manual/commands.html)
    ```
        @warning    注意事项
        @bug    缺陷
        @see    引用注释及链接
        @pre    代码项的前提条件
        @post   代码项之后的使用条件
        @brief  概要信息
        @detail 详细描述
        @param  表示参数类型及意义
        @return 返回类型及意义
        @retval 返回值的意义
        @implements 实现的需求编号
    ```
- 源程序注释内容需简洁，易懂，无歧义。
- **注释中不得出现源码** (MISRA C 2004 Rule 2.4)，建议使用条件编译#if 0来注释掉无用的代码。
- 注释不允许出现嵌套 (MISRA C 2004 Rule 2.3)。
- 注释应尽量放在对应代码的上方
- 所有enum和struct类型中的变量均需要在上方提供注释说明，以及位置偏移。
- 对于switch中的case语句，如果需要处理连续的case选择，则必须在case之间加上明确的注释。
- 避免在表达式中间，或者宏定义换行中插入注释。
- 变量及函数的注释在头文件及源文件中都必须体现出来，并且内容和格式保持一致。这样做在源码不便于交付时仍可为用户提供注释帮助。
- **所有函数的声明和定义前都必须要有函数注释**
- **寄存器描述需添加地址偏移+寄存器功能注释**
  - 示例
    ```c
    /* offset  : 0x001C.    SYSTICK 访问控制使能寄存器. */
    SYSTICK_ACES1_T SYSTICK_ACES1;
    ```
- **寄存器位域描述需添加位域偏移**
   - 示例
        ```c
        ...
        struct
        {
            __IO uint32_t RST      :1;  /*!< [0:0] 模块复位请求位，与 RST1 寄存器RST 位一起使用 */
            __I uint32_t  RSTSTA   :1;  /*!< [1:1] 复位状态 */
            __I           uint32_t :30; /*!< [31:2] 预留，读为0 */
        } bits;
        ...

        ```


---
<!-- pagebreak -->

## 三.命名规范 {#三命名规范}
- 规范中使用到的宏，枚举定义方式如下，宏和枚举的内容均使用大写，前缀为模块简称
    ```c
        // <MODULE>_E_<SN>
        #define GPT_E_BUSY          ((uint8)0x0BU)
        // <MODULE>_<SN>
        #define GPT_INIT_ID                 ((uint8)0x01U)
        // <MODULE>_<CONTENT1>_<CONTENT2>...
        typedef enum
        {
            GPT_MODE_NORMAL,
            GPT_MODE_SLEEP
        } Gpt_ModeType;
    ```
- **Drv和Reg**中的结构体，枚举，联合体的定义以`_t`作为后缀
    ```c
        typedef struct 
        {
            /* content */
        } example_struct_t;
    
        typedef enum 
        {
            /* content */
        } example_enum_t;
    
        typedef union 
        {
            /* content */
        } example_union_t;
    ```
- `char`和`char*`关键字仅限于使用在操作字符或字符串上。
- 不得直接使用`short`或`long`以及`float`关键字。
- 建议函数的命名使用下划线命名法，并除首字母外全部使用小写。
- 建议变量的命名使用驼峰命名法。首字母使用小写。
- 建议LLD库中共享使用的静态变量，全局变量前加入`kv`前缀
- 建议LLD库中共享使用的指针变量前加入`kp`前缀
- 建议回调函数的后缀统一为`CallBack`
    ```c
        /* User Callback for Uart Rx Completed */
        void Uart_RxPacketCallback(uint8_t index, uint8_t* data, uint16_t length)
        {
            /* Code */
        }
    ```
- 为避免中断处理函数被误用，不得进行函数声明。且中断处理函数应位于源文件的最尾端。
- 宏定义应全部使用大写
- 标识符命名需清晰明了，尽量使用完整的或常用的缩写，避免误解
- 除局部循环常用的i，j，k变量外，不得在其他地方使用单字符标识符命名
- 用正确的反义词组命名具有互斥意义的变量或表示动作的函数。  
    ```
        add/remove|delete  begin/end   create/destroy  insert/delete   first/last  get/set  inc/dec  push/pop    
        lock/unlock open/close  min/max next/prev   start/stop  src/des send/receive   init/deinit  read/write
    ```
- 应尽量避免局部变量命名与全局变量命名重复
- 命名长度不超过31个字符 (MISRA C)
- typedef，struct或union的tag名称必须保持唯一，不能重复使用
- *无论作用域如何，系统中的任何源文件都尽量不要重复使用具有static属性的标识符。这包括具有外部链接的对象或函数，以及具有静态存储类说明符的任何对象或函数。(MISRA C 2004 Rule 5.5)*
- 位字段只能定义为`unsigned int`。(MISRA C 2004 Rule 6.4)使用其他类型时需进行测试并注释，因为该行为与具体编译器有关，C标准未定义。芯片驱动不建议使用`signed int`。
- **函数应具有原型声明，且原型应在函数定义和调用时可见。函数原型的使用使编译器能够检查函数定义和调用的完整性。(MISRA C 2004 Rule 8.1)**
- 中断中会共享使用到的变量，访问外设寄存器的指针，以及局部循环变量。需要添加`volatile`限定符。
- 所有编程相关的命名严禁使用拼音与英文混合的方式，更不允许直接使用中文的方式。
- 尽可能减少头文件中对其他头文件的引用，可在源文件中引入需要的头文件。降低头文件之间的耦合度。
- **`#include`语句中不得出现绝对路径或相对路径的文件引用。**
- 如果仅操作一个标志位，则建议使用一个bool参数做形参，用于该位的赋值操作(0/1)
+ **标准库函数命名规范**
  - Low Level层函数命名应由**模块名+LL+具体动作**三部分组成，之间用下划线间隔。
    ```c
    void Adc_LL_SetClockSource(Adc_RegisterMap_t* const Adcx, const Adc_Source_t ClockSource)
    ```
  - 标准库的Hardware层函数命名应由**模块名+Hw+具体动作**三部分组成，之间用下划线间隔。
    ```c
    void Adc_Hw_Enable(Adc_RegisterMap_t* Adcx, bool Enabled);
    ```
  - 模块名称首字母大写，具体动作若由多个词汇组成，则其每个单词首字母也应采用大写字母形式。
  - 示例如下:
     ```c
        /* 标准库 */
        Spi_Init() -> Spi_Hw_Init() - > {Spi_LL_SetDataWidth(), Spi_LL_SetBaudRate().....}
    ```
- 建议在LLD底层驱动代码中使用更具有表意的原语，如Set, Get, Config, Enable, Disable等。



---
<!-- pagebreak -->
## 四.LLD规范 {#四LLD规范}
### dev_assert.h
- 该头文件包含断言检查全局宏开关
- 该头文件包含断言检查函数定义 KF_DEV_ASSERT(x)
- KF_DEV_ASSERT(x) 传入x为检查条件，当x == false时触发断言
- 各模块应当包含dev_assert.h，并在内部通过模块宏开关的方式实现内部断言检查：
    ```c
        #ifdef KF_DRV_OSC_ASSERT
        #include "dev_assert.h"
        #define KF_OSC_ASSERT(x) KF_DEV_ASSERT(x)
        #else
        #define KF_OSC_ASSERT(x) ((void)0U)
        #endif
    ```
- 检查条件应以宏定义方式实现，注意宏内括号使用
    ```c
        #define CHECK_EOUTCLK0_DIVIDERMODE(MODE) ((MODE >> 4U) == 0U)

        KF_INLINE void Osc_LL_SetOUTCLK0DividerMode(const Osc_OUTCLK0DivMode_t Mode)
        {
            KF_OSC_ASSERT(CHECK_EOUTCLK0_DIVIDERMODE(Mode));
            CLK_PTR->EXTCLKFD_CTL.bits.DMOD = Mode;
        }
    ```  
### kf_types.h
- 该头文件包含所需基本类型及寄存器操作定义
- 寄存器操作需使用位域及该文件提供的寄存器操作方式，以提高代码效率+防止误操作
- ```cREG_BIT_SET(reg, mask)``` 按掩码置位寄存器相应位
- ```REG_BIT_CLR(reg, mask)``` 按掩码清零寄存器相应位
- ```REG_BITS_WRITE(reg, mask, value)``` 按掩码写入寄存器相应位
- ```REG_BITS_READ(reg, mask, pos)``` 按掩码获取指定位域状态
- ```REG_WRITE(reg, value) ``` 寄存器整字写入
- ```REG_READ(reg) ``` 寄存器整字读取
- 统一使用**STD_ON/STD_OFF**表示功能开/关状态

    ```c
        __IO uint32_t reg;
    ```  
#### xxx_reg_xxx.h
- 该头文件定义相应模块的寄存器描述
- 需对外提供寄存器地址、寄存器指针、寄存器描述，供xxx_drv_xxx.h及上层接口访问
     ```c
        #define CLK_ADDR ((uint32_t)0xF000F400U)
        #define CLK_PTR  ((Clk_RegisterMap_t *)CLK_ADDR)
        #define CLK_RM   (*(Clk_RegisterMap_t *)CLK_ADDR)
    ```   
- 寄存器描述采用结构体/联合体+位域方式
- 使用```__I```修饰只读寄存器结构体/联合体或只读位域
- 使用```__O```修饰只写寄存器结构体/联合体或只写位域
- 使用```__IO```修饰读写寄存器结构体/联合体或读写位域
- 寄存器描述结构体**必须**使用**volatile**修饰，以实现寄存器整字访问时强制从寄存器地址获取数据
     ```c
        typedef volatile struct
        {
            union
            {
                struct
                {
                    __IO         uint32_t  :1;  /*!< [0:0] 预留，读为0 */
                    __I uint32_t PSSTA     :1;  /*!< [1:1] 系统 PLL 节能模式标志位 */
                    __I uint32_t LOCKSTA   :1;  /*!< [2:2] 系统 PLL 锁定状态 */
                    __IO         uint32_t  :2;  /*!< [4:3] 预留，读为0 */
                    __I uint32_t K2RDYSTA  :1;  /*!< [5:5] K2 分频器就绪状态位 */
                    __IO         uint32_t  :1;  /*!< [6:6] 预留，读为0 */
                    __I uint32_t MODRUNSTA :1;  /*!< [7:7] 调制运行标志位 */
                    __IO         uint32_t  :24; /*!< [31:8] 预留，读为0 */
                } bits;
                __IO uint32_t reg;
            };
        } SYSPLL_STA_T;
    ```
- 寄存器描述中预留位需要以位域方式填充
- 寄存名称及位域名称大写
- 寄存器需要以联合体方式提供整字访问和位域访问方式
- 模块所有寄存器以结构体方式组织，预留空间按字节/字方式填充
     ```c
        typedef volatile struct
        {
            /* offset  : 0x0000.    OSC 振荡器控制寄存器 0. */
            OSC_CTL0_T OSC_CTL0;

            /* offset  : 0x0004.    振荡器控制寄存器 1. */
            OSC_CTL1_T OSC_CTL1;

            ... ...

            /* offset  : 0x006C.    外部输出时钟控制寄存器 1. */
            EXTCLK_CTL1_T EXTCLK_CTL1;

            /* offset  : 0x0070.    外部输出时钟分数分频器控制寄存器. */
            EXTCLKFD_CTL_T EXTCLKFD_CTL;
        } Clk_RegisterMap_t;
    ```
- 模块包含寄存器数量较少时，可以直接以结构体+联合体方式描述所有寄存器
     ```c
        typedef volatile struct
        {
            union
            {
                struct
                {
                    __IO uint32_t PDRST    :1; 
                    __I           uint32_t :1;
                    __IO uint32_t M :14; 
                    __IO uint32_t N :4;  
                    __IO uint32_t OD       :2; 
                    __I           uint32_t :10;
                } bits;
                __IO uint32_t reg;
            } PLL0CTRL;
            /* offset  : 0x04. */
            union
            {
                struct
                {
                    __IO uint32_t PDRST    :1; 
                    __I           uint32_t :1;
                    __IO uint32_t M :14; 
                    __IO uint32_t N :4;  
                    __IO uint32_t OD       :2; 
                    __I           uint32_t :10;
                } bits;
                __IO uint32_t reg;
            } PLL1CTRL;
        } Pll_RegisterMap_t;
    ```
- 寄存器注释需要指明寄存器偏移量和名称，如```/* offset  : 0x0000.    OSC 振荡器控制寄存器 0. */```
- 位域注释需要位域范围及名称，如```/*!< [5:5] K2 分频器就绪状态位 */```

#### xxx_reg_alias_xxx.h(待定)
- 该文件以宏定义方式定义模块内各个寄存器指针，向上层提供不使用模块基地址而直接通过宏访问寄存器的方式
  ```c
  #define ADCS_CLKC0 (*(ADCS_CLKC_T*)0xF0003000U)
  #define ADCS_CLKC1 (*(ADCS_CLKC_T*)0xF0003004U)
  #define ADCS_CLKC2 (*(ADCS_CLKC_T*)0xF0003008U)
  #define ADCS_CLKC3 (*(ADCS_CLKC_T*)0xF000300CU)
  ```

#### xxx_drv_xxx.h
- 该文件包含LLD驱动函数接口
- LLD接口函数应当通过寄存器的读写操作实现模块的基本操作，不应当包含复杂逻辑
- LLD接口函数需要实现对传参断言检查
- 简单逻辑的LLD接口函数应当以```KF_INLINE```修饰，实现为内联函数，减少调用时压栈出栈操作
- LLD接口函数内应当谨慎使用直接操作通用寄存器和栈空间的代码，避免修改上层函数参数或栈空间
- LLD接口函数参数应当以枚举类型列出所有可配置参数
- 接口函数的非指针实参必须使用const修饰
- **接口函数的指针实参必须使用const修饰指针(指针常量)**
- 入参需要断言检查
- 示例0：
     ```c
        typedef enum
        {
            OSC_OUTCLK0_DIVIDER_RST,
            OSC_OUTCLK0_DIVIDER_NORMAL,
            OSC_OUTCLK0_DIVIDER_FRACTIONAL,
            OSC_OUTCLK0_DIVIDER_OFF,
        } Osc_OUTCLK0DivMode_t;  

        KF_INLINE void Osc_LL_SetOUTCLK0DividerMode(const Osc_OUTCLK0DivMode_t Mode)
        {
            KF_OSC_ASSERT(CHECK_EOUTCLK0_DIVIDERMODE(Mode));
            CLK_PTR->EXTCLKFD_CTL.bits.DMOD = Mode;
        }
    ```
- 示例1：
    ```c
        KF_INLINE void Spi_LL_SelectI2SStandard(Spi_RegisterMap_t *const Module, const I2S_StandardSelection_t Sel)
        {
            KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH(Module));
            KF_SPI_ASSERT(CHECK_I2S_STANDARD_SELECTION(Sel));

            Module->CTLR.bits.I2SSS = Sel;
        }
    ```
+ **访问寄存器确定的位时，应当以位域方式访问：**
  ```c
  CLK_PTR->EXTCLKFD_CTL.bits.DMOD = Mode;
  ```
+ **根据传入参数不同需要访问寄存器中不同位时，以掩码方式整字访问：**
  ```c
  REG_BITS_WRITE(CLK_PTR->CLKSYS_CTL0.reg, (1U << (uint32_t)Index), ((uint32_t)1 << (uint32_t)Index));
  ```
- 需要寄存器多个位同时写入时，应当以掩码方式整字访问；或新建相应寄存器类型的临时变量，修改完成后整字写入（与编译器相关）
- LLD接口函数命名规则：参考本文档命名规范
- 参数枚举类型过多时，可分文件**xxx_types_xxx.h**写入类型定义(待定)

#### xxx_drv_xxx.c
- 包含复杂逻辑(多条件语句+循环语句)、全局变量使用、复杂数据结构参数的LLD接口函数应当在该文件中实现
- 内部使用的全局变量应当用**static**修饰，仅限本文档访问
- 允许调用xxx_drv_xxx.h文件中实现的LLD接口函数
- xxx_drv_xxx.c内实现的LLD接口函数需要在xxx_drv_xxx.h中声明

---
<!-- pagebreak -->
## 五.测试规范 {#五测试规范}
- 不少于三人的代码Review过程，制定人工Review的内容条例。
- 单元测试要求达到所有语句的覆盖度。
- 测试包括所有编译器优化级别。
- 编译后不得出现`warning`报警，如该处符合设计要求，则需要使用显示的关闭告警编译器语法。
- 使用QAC工具进行代码审查，按要求对代码做改进或显式的告警抑制。
- **代码自身需保证逻辑自洽验证**
- 检查头文件的`#define`互斥包含是否正确



<!-- pagebreak -->

## 六.参考文档 {#六参考文档}
- [《华为软件编程规范和范例》](https://soapbubble.cn/pdf/华为软件编程规范和范例.pdf)
- [《MISRA-C:2004 Guidelines for the use of the C language in critical systems》](https://soapbubble.cn/pdf/misra%20c2004.pdf)
- [《Doxygen Manual》](https://soapbubble.cn/pdf/doxygen_manual-1.9.3.pdf)
- [《Netrino Embeded C Coding Standard》](https://soapbubble.cn/pdf/Code_Rules.pdf)

<!-- pagebreak -->

