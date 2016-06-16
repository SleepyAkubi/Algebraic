#ifndef ALGEBRAIC_COMMON_ARCHITECTURES_H
#define ALGEBRAIC_COMMON_ARCHITECTURES_H

#if defined(_WIN64) || defined (__x86_64__) || defined(__ppc64__) || defined(__WIN64) ||  defined(WIN64)
#define ALGEBRAIC_ARCHITECTURE_X64
#define ALGEBRAIC_BITSTRING "bin64"
#define ALGEBRAIC_MAXINT_BITS 64
#define ALGEBRAIC_MAXINT_BYTES 8
#elif __arm__
#define ALGEBRAIC_ARCHITECTURE_ARM
#define ALGEBRAIC_BITSTRING "binarm"
#define ALGEBRAIC_MAXINT_BITS 32
#define ALGEBRAIC_MAXINT_BYTES 4
	#warning Algaebraic may not work on this platform, no tests have been performed.
#else
#define ALGEBRAIC_ARCHITECTURE_X32
#define ALGEBRAIC_BITSTRING "bin32"
#define ALGEBRAIC_MAXINT_BITS 32
#define ALGEBRAIC_MAXINT_BYTES 4
#endif

#endif
