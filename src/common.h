
#ifndef GAMENAMEPLACEHOLDER_COMMON_H
#define GAMENAMEPLACEHOLDER_COMMON_H

#if __STDC_VERSION__ >= 199901L
#define C99
#else
#endif

#include <stdint.h>

#ifdef C99
  #include <stdbool.h>
#else
  typedef unsigned char bool;
  #define true 1
  #define false 0
#endif

typedef unsigned char u8;
typedef uint32_t u32;
typedef uint16_t u16;

#endif /* GAMENAMEPLACEHOLDER_COMMON_H */
