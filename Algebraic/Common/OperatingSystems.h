#ifndef ALGEBRAIC_COMMON_OPERATINGSYSTEMS_H
#define ALGEBRAIC_COMMON_OPERATINGSYSTEMS_H

#if defined(_WIN32) || defined (_WIN64) || defined (__WIN32) || defined (__WIN64) || defined (WIN32) || defined (WIN64)
#define ALGEBRAIC_SYSTEM_WINDOWS
#elif defined (__APPLE__) && defined(__MACH__)
#define ALGEBRAIC_SYSTEM_OSX
#define ALGEBRAIC_SYSTEM_UNIX
#elif defined (__unix__)
#define ALGEBRAIC_SYSTEM_UNIX
#if defined (__linux__)
#define ALGEBRAIC_SYSTEM_LINUX
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#define ALGEBRAIC_SYSTEM_FREEBSD
#else
#define ALGEBRAIC_SYSTEM_OTHER_UNIX
#endif
#else
#endif

#endif
