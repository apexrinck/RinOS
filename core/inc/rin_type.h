/*
 * MIT License
 * 
 * Copyright (c) [2018] [CSU Yangyang]
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef RIN_TYPE_H
#define RIN_TYPE_H


/*
 * If stdint.h cannot be located, then:
 *  1. If using GCC, ensure the -nostdint opitions is not being used;
 *  2. Ensure the project's include path includes the directory in which
 *     your compiler stores stdint.h
 *  3. Set the compiler opitions necessary for it to support C99, as technically
 *     stdint.h is only mandatory with C99 (RinOS does not require C99 in any
 * other way)
 *  4. The RinOS download includes a simple stdint.h defintion that can be used
 * in cases where none is provided by compiler. The files only contains the
 * typedefs required to build RinOS.
 */
#include <stdint.h> /* READ COMMENT ABOVE */


// RinOS's data type.
typedef int8_t      S8;
typedef int16_t     S16;
typedef int32_t     S32;
typedef uint8_t     U8;
typedef uint16_t    U16;
typedef uint32_t    U32;

typedef volatile int8_t     VS8;
typedef volatile int16_t    VS16;
typedef volatile int32_t    VS32;
typedef volatile uint8_t    VU8;
typedef volatile uint16_t   VU16;
typedef volatile uint32_t   VU32;


// RinOS's bool type.
typedef enum _bool
{
    FALSE = 0,
    TRUE  = 1
} bool;

// RinOS's NULL.
#ifndef NULL
#define NULL ((void *)0)
#endif

// The usage typedef used for RinOS's kernel.
typedef enum _usage_t
{
    enable = 0,
    disable = 1,
} usage_t;


// RinOS's size_t.
// #ifndef size_t
// // typedef unsigned int size_t;
// typedef unsigned long long size_t;
// #endif

// Support to RinOS's kernel or task.
#ifndef OFFSET_OF
#undef  OFFSET_OF
#endif
#define OFFSET_OF(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

// Support to RinOS's kernel or task.
#ifndef CONTAINER_OF
#undef CONTAINER_OF
#endif
#define CONTAINER_OF(ptr, type, member) \
    ((type *)((U8 *)(ptr)-OFFSET_OF(type, member)))

// Support to RinOS's kernel or task.
#define CAT(a, b) CAT0(a, b)
#define CAT0(a, b) a##b

// Function templates of RinOS.
typedef void *(*void4fp)(void *, void *, void *, void *);
typedef void *(*void3fp)(void *, void *, void *);
typedef void *(*void2fp)(void *, void *);
typedef void *(*void1fp)(void *);
typedef void *(*void0fp)(void);
typedef void  (*void4f)(void *, void *, void *, void *);
typedef void  (*void3f)(void *, void *, void *);
typedef void  (*void2f)(void *, void *);
typedef void  (*void1f)(void *);
typedef void  (*void0f)(void);

// Compiler's set opition.
#define SI __attribute__((always_inline)) static __inline

// The union decided by variable's type which is 8 Bits.
typedef union _rt8 {
    char c;
    U8 u8;
    S8 s8;
} rt8, *rt8_p;

// The union decided by variable's type which is 16 Bits.
typedef union _rt16 {
    char c[2];
    U8 u8;
    S8 s8;
    U16 u16;
    S16 s16;
} rt16, *rt16_p;

// The union decided by variable's type which is 32 Bits.
typedef union _rt32 {
    char c[4];
    U8 u8;
    S8 s8;
    U16 u16;
    S16 s16;
    U32 u32;
    S32 s32;
    float f;
} rt32, rt32_p;

// Data type tranform.
#define RT8(data, type)     ((*((rt8_p)(&(data)))).type)
#define RT16(data, type)    ((*((rt16_p)(&(data)))).type)
#define RT32(data, type)    ((*((rt32_p)(&(data)))).type)

#define RT8inC(data)        RT8(data, c)
#define RT8inU(data)        RT16(data, u8)
#define RT8inS(data)        RT32(data, s8)

#define RT16inC(data)       RT16(data, c)
#define RT16inU(data)       RT16(data, u16)
#define RT16inS(data)       RT16(data, s16)

#define RT32inC(data)       RT32(data, c)
#define RT32inU(data)       RT32(data, u32)
#define RT32inS(Data)       RT32(data, s32)
#define RT32inF(data)       RT32(data, f)

#define RT2C(data)          ((char)(data))
#define RT2U8(data)         ((U8)(data))
#define RT2U16(data)        ((U16)(data))
#define RT2U32(data)        ((U32)(data))
#define RT2S8(data)         ((S8)(data))
#define RT2S16(data)        ((S16)(data))
#define RT2S32(data)        ((S32)(data))
#define RT2F(data)          ((float)(data))

#define RTU82U16(data)      RT2U16(RT2U8(data))
#define RTU82U32(data)      RT2U32(RT2U8(data))
#define RTU162U32(data)     RT2U32(RT2U16(data))

#define RTS82S16(data)      RT2S16(RT2S8(data))
#define RTS82S32(data)      RT2S32(RT2S8(data))
#define RTS162S32(data)     RT2S32(RT2S16(data))

#define RTS82F(data)        RT2F((RT2S32(MT2S8(data))))
#define RTS162F(data)       RT2F((RT2S32(MT2S16(data))))
#define RTS322F(data)       RT2F((RT2S32(data)))

#define RTF2S32(data)       RT2S32(RT2F(data))

// RinOS support simple math tools.
#define LIMIT(data, max, min)    \
    do                           \
    {                            \
        if ((data) > (max))      \
        {                        \
            (data) = (max);      \
        }                        \
        else if ((data) < (min)) \
        {                        \
            (data) = (min);      \
        }                        \
    } while (0)

#define LIMIT_SYM(data, max)     \
    do                           \
    {                            \
        if ((data) > (max))      \
        {                        \
            (data) = (max);      \
        }                        \
        else if ((data < (-max)) \
        {                        \
            (data) = -(max);     \
        }                        \
    } while (0)

#define IN_RANGE(data, limit)    \
    (((data) > (limit)) ? 0 : (((data) < (-(limit))) ? 0 : 1))


#endif /* RIN_TYPE */
