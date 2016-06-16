#ifndef ALGEBRAIC_COMMON_COMPILERS_H
#define ALGEBRAIC_COMMON_COMPILERS_H

#if   defined(__clang__)
#define ALGEBRAIC_COMPILER_CLANG
#elif defined(_MSC_VER)
#define ALGEBRAIC_COMPILER_MSVC
#elif defined(__GNUC__) || defined(__GNUG__) && !(defined(__clang__))
#define ALGEBRAIC_COMPILER_GNU_GCC
#elif defined(__INTEL_COMPILER)
#define ALGEBRAIC_COMPILER_INTEL
#endif

#endif
