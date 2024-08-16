/**
The `stdint.h` header file is part of the C standard library and is used to define a set of integer types with specified
widths. This header was introduced in the C99 standard and provides a consistent and portable way to use integer types
across different platforms and compilers. Here are the main features of `stdint.h`:

Fixed-width Integer Types
These types have an exact width, ensuring portability and predictability across different systems:

- `int8_t`, `uint8_t`: Signed and unsigned 8-bit integers
- `int16_t`, `uint16_t`: Signed and unsigned 16-bit integers
- `int32_t`, `uint32_t`: Signed and unsigned 32-bit integers

In this updated code, I've added variables of the types int_least8_t, uint_least8_t, int_least16_t, uint_least16_t,
int_least32_t, uint_least32_t, int_least64_t, uint_least64_t, int_fast8_t, uint_fast8_t, int_fast16_t, uint_fast16_t,
int_fast32_t, uint_fast32_t, int_fast64_t, uint_fast64_t, intptr_t, uintptr_t, intmax_t, and uintmax_t. Each variable is
printed using the appropriate format specifier.

Note: When printing intptr_t and uintptr_t values, they are cast to void* for compatibility with the %p format
specifier. Additionally, format specifiers for intmax_t and uintmax_t use %jd and %ju respectively.
*/
#include <stdint.h>
#include <stdio.h>

int main(void) {
    printf("\n");
    printf("--------------------------------------------------------\n");
    int8_t a = 100;
    uint16_t b = 50000;
    int32_t c = -123456789;
    uint64_t d = 1234567890123456789ULL;

    int_least8_t e = 127;
    uint_least8_t f = 255;
    int_least16_t g = -32768;
    uint_least16_t h = 65535;
    int_least32_t i = -2147483647;
    uint_least32_t j = 4294967295U;
    int_least64_t k = -9223372036854775807LL;
    uint_least64_t l = 18446744073709551615ULL;

    int_fast8_t m = 127;
    uint_fast8_t n = 255;
    int_fast16_t o = -32768;
    uint_fast16_t p = 65535;
    int_fast32_t q = -2147483647;
    uint_fast32_t r = 4294967295U;
    int_fast64_t s = -9223372036854775807LL;
    uint_fast64_t t = 18446744073709551615ULL;

    intptr_t u = (intptr_t)&a;
    uintptr_t v = (uintptr_t)&b;

    intmax_t w = INTMAX_MAX;
    uintmax_t x = UINTMAX_MAX;

    printf("a = %d\n", a);
    printf("b = %u\n", b);
    printf("c = %d\n", c);
    printf("d = %llu\n", d);

    printf("e = %d\n", e);
    printf("f = %u\n", f);
    printf("g = %d\n", g);
    printf("h = %u\n", h);
    printf("i = %d\n", i);
    printf("j = %u\n", j);
    printf("k = %lld\n", k);
    printf("l = %llu\n", l);

    printf("m = %d\n", m);
    printf("n = %u\n", n);
    printf("o = %d\n", o);
    printf("p = %u\n", p);
    printf("q = %d\n", q);
    printf("r = %u\n", r);
    printf("s = %lld\n", s);
    printf("t = %llu\n", t);

    printf("u = %p\n", (void*)u);
    printf("v = %p\n", (void*)v);

    printf("w = %jd\n", w);
    printf("x = %ju\n", x);
    printf("\n");
    printf("--------------------------------------------------------\n");

    return 0;
}
