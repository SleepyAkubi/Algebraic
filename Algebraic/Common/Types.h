#ifndef ALGEBRAIC_COMMON_TYPES_H
#define ALGEBRAIC_COMMON_TYPES_H

#include <Algaebraic/Common/BasicDefinitions.h>
#include <Algaebraic/Common/Architectures.h>
#include <stdio.h>

typedef char a8;
typedef short a16;
typedef long a32;
typedef long long a64;

typedef signed char i8;
typedef signed short i16;
typedef signed long i32;
typedef signed long long i64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef float f32;
typedef double f64;
typedef long double f128;

#if !ALGEBRAIC_MAXINT_BITS
#elif ALGEBRAIC_MAXINT_BITS == 64
typedef u64 usize;
typedef i64 isize;
#elif ALGEBRAIC_MAXINT_BITS == 32
typedef u32 usize;
typedef i32 isize;
#elif ALGEBRAIC_MAXINT_BITS == 16
typedef u16 usize;
typedef i16 isize;
#elif ALGEBRAIC_MAXINT_BITS == 8
typedef u8 usize;
typedef i8 isize;
#endif

typedef isize iptr;
typedef usize uptr;

typedef i8 b8;
#ifndef __cplusplus
typedef b8 bool;
#endif

#if defined(UNICODE)
#define ALGEBRAIC_CHARSET_UNICODE
#else
#define ALGEBRAIC_CHARSET_ANSI
#endif

#define _W(string) L ## string
#define W(string) _W(string)

#ifdef ALGEBRAIC_CHARSET_UNICODE
typedef u16 vchar;
#define _V(string) L ## string
#define V(string) _V(string)
#define Vsprintfu swprintf
#define Vsprintf swprintf_s
#define Vstrcmp wcscmp
#define Vstrcat wcscat_s
#define Vstrtok(x, y) wcstok(x, y, NULL)
#define Vstrdup wcsdup
#define Vstrstr wcsstr
#define Vtolower towlower
#define Vfopen _wfopen
//#define Vstrsep wcstok_r
#else
typedef u8 vchar;
#define V(string) string
#define Vsprintfu sprintf
#define Vsprintf sprintf_s
#define Vstrcmp strcmp
#define Vstrcat strcat_s
#define Vstrtok strtok
#define Vstrdup strdup_s
#define Vstrstr strstr
//#define Vstrsep strsep
#define Vtolower tolower
#define Vfopen fopen
#endif

#define Vconstcopy(x) \
  usize strSize = (Vstrlen( x ) + 1) * sizeof(vchar); \
  vchar* x##Owned = (vchar*) conjure(strSize); \
  copyMemory( args, x##Owned, strSize);


forceinline usize Vstrlen(const vchar* a)
{
	usize length = 0;
	while ((*a) != V('\0'))
	{
		length++;
		a++;
	}

	return(length);
}

forceinline b8 Vstrequal(const vchar* a, const vchar* b)
{
	vchar* ourA = (vchar*)a;
	vchar* ourB = (vchar*)b;
	do
	{
		if ((*ourA) != (*ourB))
			return(false);
		ourA++;
		ourB++;
	} while ((*ourA) != V('\0'));

	return(false);
}

#endif
