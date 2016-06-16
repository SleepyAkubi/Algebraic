#ifndef ALGEBRAIC_COMMON_BASICDEFINITIONS_H
#define ALGEBRAIC_COMMON_BASICDEFINITIONS_H

#include <Algaebraic/Common/Compilers.h>

#ifndef NULL
#define NULL 0
#endif

#ifdef ALGEBRAIC_STEAM
#define STEAM(x) x
#else
#define STEAM(x)
#endif


#if defined( ALGEBRAICEXPORTS )
#define ALGEBRAIC_EXPORT __declspec(dllexport)
#else
#define ALGEBRAIC_EXPORT __declspec(dllimport)
#endif

#ifdef _DEBUG
#define DEBUG_EXPORT __declspec(dllexport)
#else
#define DEBUG_EXPORT
#endif

#ifdef ALGEBRAIC_COMPILER_MSVC
#define forceinline __forceinline
#else
#define forceinline __attribute__ ((__always_inline__))
#endif

#define maybeinline inline
#define false 0
#define true 1

#define LOCK_MUTEX(x) \
	while (heapMutex == true) \
	{} \
	heapMutex = true

#define UNLOCK_MUTEX(x) \
	heapMutex = false

int BlankFunction(void);

#define FULFIL_INTERFACE_FUNCTION(name, returnType, ...) \
	__declspec(dllexport) returnType name##( ##__VA_ARGS__## )

#define DEFINE_EXTERNAL_INTERFACE_FUNCTION(name, returnType, ...) \
	const char* ALGEBRAICFUNCTIONINTERFACE_##name##_NAME = #name; \
	typedef returnType (*name##Function)( ##__VA_ARGS__## ) \

#define DEFINE_INTERFACE_FUNCTION(name, returnType, ...) \
	__declspec(dllexport) returnType name##( ##__VA_ARGS__## ); \
	const char* ALGEBRAICFUNCTIONINTERFACE_##name##_NAME = #name; \
	typedef returnType (*name##Function)( ##__VA_ARGS__## )

#define GET_INTERFACE_TYPE(name) \
	name##Function

#define GET_INTERFACE_NAME(name) \
	ALGEBRAICFUNCTIONINTERFACE_##name##_NAME

#undef DEBUG

#ifdef _DEBUG
#define DEBUG(x) x
#else
#define DEBUG(x)
#endif

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define KILOBYTES(x) ((x) * 1024LL)
#define MEGABYTES(x) ((KILOBYTES(x) * 1024LL)
#define GIGABYTES(x) ((MEGABYTES(x) * 1024LL)
#define TERABYTES(x) ((GIGABYTES(x) * 1024LL)
#define PETABYTES(x) ((TERABYTES(x) * 1024LL)
#define EXABYTES(x) ((PETABYTES(x) * 1024LL)
#define ZETTABYTES(x) ((EXABYTES(x) * 1024LL)
#define YOTTABYTES(x) ((ZETTABYTES(x) * 1024LL)

#ifdef ALGEBRAIC_COMPILER_MSVC
#pragma section(".CRT$XCU",read)
#define INITIALIZER2_(f,p) \
        static void f(void); \
        __declspec(allocate(".CRT$XCU")) void (*f##_)(void) = f; \
        __pragma(comment(linker,"/include:" p #f "_")) \
        static void f(void)
#ifdef _WIN64
#define INITIALIZER(f) INITIALIZER2_(f,"")
#else
#define INITIALIZER(f) INITIALIZER2_(f,"_")
#endif
#else
#define INITIALIZER(f) \
        static void f(void) __attribute__((constructor)); \
        static void f(void)
#endif

#ifdef ALGEBRAIC_COMPILER_MSVC
#define dontinline __declspec(noinline)
#else
#define dontinline __attribute__((noinline))
#endif

#define WORDSWAP(w)		(((w) >> 8) | \
						(((w) << 8) & 0xFF00))

#define DWORDSWAP(dw)	(((dw) >> 24) | \
						(((dw) >> 8) & 0x0000FF00) | \
						(((dw) << 8) & 0x00FF0000) | \
						(((dw) << 24) & 0xFF000000))

#ifdef ALGEBRAIC_COMPILER_MSVC
#define ALIGNOF(x) __alignof(x)
#define TYPEOF(x) __typeof(x)
#else
#define ALIGNOF(x) alignof(x)
#define TYPEOF(x) typeof(x)
#endif


#endif
