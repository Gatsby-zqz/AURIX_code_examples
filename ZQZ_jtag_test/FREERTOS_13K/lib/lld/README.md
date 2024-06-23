# 13K LLD (Low Level Driver) 驱动库

芯旺微电子13K芯片驱动库，用于13K芯片底层驱动、向上层提供各模块寄存器操作接口。 LLD驱动对芯片的寄存器进行了抽象，实现了模块底层驱动。

---

## 模块
Osc、Systick、Bpt、Apt、Epwm、Canfd、Spi、QSpi、UTLin、I2C、Sent、PSI5、PSI5-S、MSC、GPIO、IOM、QEI、HRCAP、DMA、CRC、SACU、SCU、EWDT、ECCP、INT、CSCB、DAC、PMC、PMS

## 文档结构
- **drv**: 该文件夹包含各个模块的驱动代码。
- **reg**:  该文件夹包含了寄存器描述，根据脚本自动生成，也可根据**drv**的需要修改。
  
## 注意事项
- 使用 **.clang-format**文件进行文件格式化