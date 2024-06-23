//****************************************************************************************
//*
//* File Name: Cpu_Intrinsics.h
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//*
//****************************************************************************************/
// #include <KF32DA2218SQVWS.h>

// asm(".include		\"KF32DA2218SQVWS.inc\"	");

/*
 * Cpu_Intrinsics.h
 * Lld_Cpu_Intrinsics Intrinsics
 *  Created on: 2024-3-29
 *      Author: chipon
 */

#ifndef CPU_INTRINSICS_H_
#define CPU_INTRINSICS_H_

/******************************************************************************/
#ifndef _WEAK
#define _WEAK __attribute__((weak))
#endif

#ifndef _ISR
#define _ISR __attribute__((interrupt))
#endif

#ifndef _INTERRUPT
#define _INTERRUPT __attribute__((interrupt))
#endif

#ifndef _PORTECT_FPU
#define _PORTECT_FPU __attribute__((interrupt))
#endif

#if defined __GNUC__ && defined __Clang__
#ifndef _KF_INLINE
#define _KF_INLINE __attribute__((always_inline))
#endif
#else
#ifndef _KF_INLINE
#define _KF_INLINE static inline
#endif
#endif
/******************************************************************************/
/** Function call without return
 */
#define __non_return_call(fun) __asm__ volatile("jmp %0" ::"g"(fun))

/** Jump and link
 */
_KF_INLINE void __jump_and_link(void (*fun)(void))
{
    __asm__ volatile("PUSH      R5" ::: "memory");
    /** @attention "MOV  R5, %0" : : "r"(fun)操作在O0优化下编译器行为不可预测 */
    __asm__ volatile("MOV  R5, %0" : : "r"(fun) : "R5");
    // __asm__ volatile("MOV R5, R0");
    __asm__ volatile("LJMP       R5");
    __asm__ volatile("POP       R5" ::: "memory");
}

_KF_INLINE void __jumpToFunction(const void *fun)
{
    __asm__ volatile("jmp %0" ::"g"(fun));
}

_KF_INLINE void __jumpToFunctionWithLink(const void *fun)
{
    __jump_and_link((void (*)(void))fun);
}

/******************************************************************************/
_KF_INLINE void __jumpBackToLink(void)
{
    __asm__ volatile("jmp lr");
}

_KF_INLINE void __isrjumpBackToLink(void)
{
    __asm__ volatile("mret");
}

/******************************************************************************/
_KF_INLINE void __Loop(void)
{
    __asm__ volatile("sjmp $+0");
}

/** Disable interrupts.
 */
#define __disable() __asm__ volatile("xxx_wait_adj" : : : "memory")

/** Enable interrupts immediately at function entry.
 */
#define __enable() __asm__ volatile("xxx_wait_adj" : : : "memory")

/******************************************************************************/
/**  Write back and invalidate cache address "p". Generates CACHEA.WI [Ab].
 */
_KF_INLINE void __cachea_wi(unsigned char *p)
{
    __asm__ volatile("cachea.wi [%0]0" ::"a"(p));
}
/**  Write back and invalidate cache index "p". Generates CACHEI.WI [Ab].
 */
_KF_INLINE void __cachei_wi(unsigned char *p)
{
    __asm__ volatile("cachei.wi [%0]0" ::"a"(p));
}

/******************************************************************************/
/**  Count leading ones in int
 */
_KF_INLINE signed int __clo(signed int a)
{
    signed int res;
    __asm__ volatile("clo %0,%1" : "=r"(res) : "r"(a));
    return res;
}

/**  Count number of redundant sign bits (all consecutive bits with the same value as bit 31
 */
_KF_INLINE signed int __cls(signed int a)
{
    signed int res;
    __asm__ volatile("cls %0,%1" : "=r"(res) : "r"(a));
    return res;
}

/**  Count leading zeros in int
 */
#define __clz(a) __builtin_clz(a)

/** Insert DEBUG instruction
 */
_KF_INLINE void __debug(void)
{
    __asm__ volatile("break" : : : "memory");
}
/******************************************************************************/
/** Insert DSYNC instruction
 */
_KF_INLINE void __dsync(void)
{
    __asm__ volatile("dsync" : : : "memory");
}

/** Insert ISYNC instruction
 */
_KF_INLINE void __isync(void)
{
    __asm__ volatile("sync" : : : "memory");
}

/** Insert NOP instruction
 */
_KF_INLINE void __nop(void)
{
    __asm__ volatile("nop" : : : "memory");
}
/******************************************************************************/
/** Insert SWAP instruction. Note that all operands must be word-aligned.
 */
_KF_INLINE unsigned int __swap(void *place, unsigned int value)
{
    unsigned int res;
    __asm__ volatile("swap.w %0,[%1], %2" : "=r"(res) : "r"(place), "r"(value));
    return res;
}
/******************************************************************************/
_KF_INLINE void __setStackPointer(void *stackAddr)
{
    __asm__ volatile("mov sp, %0" : : "r"(stackAddr) : "sp");
}

_KF_INLINE signed int __popcnt(signed int a)
{
    signed int res;
    __asm__ volatile("popcnt %0,%1" : "=r"(res) : "r"(a));
    return res;
}

/**  Invalidate cache address "p". Generates CACHEA.I [Ab].
 */
_KF_INLINE void __cacheai(unsigned char *p)
{
    __asm__ volatile("cachea.i %0" ::"r"(p));
}

/******************************************************************************/

#define __mfcr(regaddr)                                                                                                \
    ({                                                                                                                 \
        sint32 res;                                                                                                    \
        __asm__ volatile("CSRR %0,#%1\n\tsync" : "=d"(res) : "g"(regaddr) : "memory");                                 \
        res;                                                                                                           \
    })

#define __mtcr(regaddr, val) __asm__ volatile("CSRW %0,#%1\n\tsync" ::"r"(val), "g"(regaddr), : "memory")

/******************************************************************************/

/******************************************************************************/

#define Kfx_ALIGN_8   (1)  // Align on 8 bit Boundary
#define Kfx_ALIGN_16  (2)  // Align on 16 bit Boundary
#define Kfx_ALIGN_32  (4)  // Align on 32 bit Boundary
#define Kfx_ALIGN_64  (8)  // Align on 64 bit Boundary
#define Kfx_ALIGN_128 (16) // Align on 128 bit Boundary
#define Kfx_ALIGN_256 (32) // Align on 256 bit Boundary

#define KfX_AlignOn256(Size) ((((Size) + (Kfx_ALIGN_256 - 1)) & (~(Kfx_ALIGN_256 - 1))))
#define Kfx_AlignOn128(Size) ((((Size) + (Kfx_ALIGN_128 - 1)) & (~(Kfx_ALIGN_128 - 1))))
#define Kfx_AlignOn64(Size)  ((((Size) + (Kfx_ALIGN_64 - 1)) & (~(Kfx_ALIGN_64 - 1))))
#define Kfx_AlignOn32(Size)  ((((Size) + (Kfx_ALIGN_32 - 1)) & (~(Kfx_ALIGN_32 - 1))))
#define Kfx_AlignOn16(Size)  ((((Size) + (Kfx_ALIGN_16 - 1)) & (~(Kfx_ALIGN_16 - 1))))
#define Kfx_AlignOn8(Size)   ((((Size) + (Kfx_ALIGN_8 - 1)) & (~(Kfx_ALIGN_8 - 1))))

#define Kfx_COUNTOF(x) (sizeof(x) / sizeof(x[0]))

/******************************************************************************/

/******************************************************************************/
#endif /* CPU_INTRINSICS_H_ */
