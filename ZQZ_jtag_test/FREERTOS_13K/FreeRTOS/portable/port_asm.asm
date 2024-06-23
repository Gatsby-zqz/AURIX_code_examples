	.extern pxCurrentTCB
	.extern vTaskSwitchContext
    
    .section .text$interruptSwGp0Sr0
    .align	1
    .export interruptSwGp0Sr0
    .type interruptSwGp0Sr0,@function
    .func interruptSwGp0Sr0
interruptSwGp0Sr0:    
    /* DISABLE_INTERRUPT() */
    PUSH R0
    MOV R0,#0x00008000
    SYNC
    CSRCLR R0, R0, #0x187
    SYNC
    POP R0
    /*=====================使用任务栈=======================*/
    /** @note 任务A栈空间
     * 中断自动压栈 XPSR, R0-R4,LR(任务返回地址)
     * 中断引导代码压栈R5
     * 手动压栈LR(中断引导代码返回地址)
     */
    /** @attention 若PSW.IS=1，硬件中断压栈也使用SP */
    /** @attention
     * 若PSW.IS=0，硬件中断压栈固定使用ISP，将R0-R4,LR,XPSR压入ISP中；中断服务程序中由软件选择使用之前的任务栈SP或ISP(若选择使用ISP，需要手动修改SP=ISP，中断返回时恢复之前的SP)
     */
    PUSH LR
    /* 手动压栈SP, 保存当前任务的上下文 */
    PUSH {R16-R31}
    PUSH {R6-R12}
    /** @note 任务A栈空间
     * 中断自动压栈 XPSR, R0-R4,LR(任务返回地址)
     * 中断引导程序压栈R5(用来中断引导程序跳转中断服务函数)
     * 中断引导程序压栈LR(中断引导程序MRET的返回地址,即任务A的中断位置)
     * 编译器压栈LR(中断服务程序的返回地址，即中断引导程序的跳转位置+4)
     * 手动压栈 R16-R31
     * 手动压栈 R6-R12
     */
    /* 修改 pxCurrentTCB->pxTopOfStack为新的SP */
    /** @brief R2 = &pxCurrentTCB */
    LD R2, #pxCurrentTCB
    /** @brief R1 = pxCurrentTCB = &CurrentTCB = &CurrentTCB.pxTopOfStack */
    LD.W R1, [R2]
    /** @brief R0 = task A SP with context stored */
    MOV R0, SP
    /** @brief CurrentTCB.pxTopOfStack = SP */
    ST.W [R1], R0

    /* 中断内将栈指针手动切换为ISP */
    /* 读取ISP, 在R3内保存当前ISP */
    CSRR R3, #0x189
    SYNC
    MOV SP, R3
    SYNC
    DSYNC

    /** @note 中断栈空间
     * 压栈LR(vTaskSwitchContext返回地址,即interruptSwGp0Sr0+4)
    */
    PUSH LR
    /** @attention 汇编内调用函数，编译器不会自动保存调用者使用的寄存器 */
    PUSH R3
    LD R2, #vTaskSwitchContext
    LJMP R2
    POP R3
    POP LR
    /* 恢复ISP */
    DSYNC
    SYNC
    CSRW R3, #0x189
    SYNC
    /** @attention 没有必要将当前使用栈切换回任务A的SP */
    /* 将SP赋值为新任务的栈顶pxCurrentTCB->pxTopOfStack */
    /** @brief R2 = &pxCurrentTCB */
    /** @attention 重新读取pxCurrentTCB地址至R2, 避免vTaskSwitchContext()内使用了R2寄存器*/
    LD R2, #pxCurrentTCB
    /** @brief R1 = pxCurrentTCB = &CurrentTCB = &CurrentTCB.pxTopOfStack */
    LD.W R1, [R2]
    /** @brief R1 = (unsigned int)CurrentTCB.pxTopOfStack */
    LD.W R1, [R1]
    /** @brief SP = (unsigned int)CurrentTCB.pxTopOfStack */
    MOV SP, R1
    SYNC
    /** @note 任务B栈空间
     * 中断自动压栈 XPSR, R0-R4,LR(任务返回地址)
     * 中断引导程序压栈R5(用来中断引导程序跳转中断服务函数)
     * 中断引导程序压栈LR(中断引导程序MRET的返回地址,即任务A的中断位置)
     * 编译器压栈LR(中断服务程序的返回地址，即中断引导程序的跳转位置+4)
     * 手动压栈 R16-R31
     * 手动压栈 R6-R12
     */
    /* 从新任务栈中弹出新任务使用的全局寄存器 */
    POP {R6-R12}
    POP {R16-R31}
    /* 手动添加LR (中断服务程序的返回地址) PUSH/POP，需要在此恢复 */
    POP LR
    /* __iVecEntry执行LR(任务中断地址) PUSH/POP，不需要在此恢复 */
    /* __iVecEntry执行R5 PUSH/POP，不需要在此恢复 */
    /* 中断引导程序返回时MRET自动出栈: LR(任务返回地址) R4 R3 R2 R1 R0 XPSR */
    /** @attention MRET指令出栈的同时并行JMP LR, 该LR为任务中断地址，而非MRET自动出栈的LR*/
    PUSH R0                                                                                                
    MOV R0,#0x00008000                                                                                     
    SYNC                                                                                                   
    CSRSET R0, R0, #0x187                                                                                 
    SYNC                                                                                                   
    POP R0 

    JMP LR
.size interruptSwGp0Sr0, .-interruptSwGp0Sr0
.endfunc
