/**
<limits.h> provides macros for integer type limits (INT_MAX, SCHAR_MIN).
<float.h> provides macros for floating-point type limits (FLT_MAX).

C program that determines the ranges of various data types,
both by using standard headers and by direct computation.
This program will cover: `char`, `short`, `int`, `long`,
`float`, `double`, and `long double`.

The direct computation of the range of signed types is based on the idea that the maximum value is half of the bit patterns of the type (shifted right by one) and the minimum value is the negative of this maximum value minus one. For unsigned types, the maximum value is simply the bitwise NOT of zero.
 */
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // Using standard headers to determine ranges
    printf("Ranges using standard headers:\n");

    // Char
    printf("Signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0 to %u\n", UCHAR_MAX);

    // Short
    printf("Signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short: 0 to %u\n", USHRT_MAX);

    // Int
    printf("Signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int: 0 to %u\n", UINT_MAX);

    // Long
    printf("Signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: 0 to %lu\n", ULONG_MAX);

    // Long Long
    printf("Signed long long: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Unsigned long long: 0 to %llu\n", ULLONG_MAX);

    // Floating-point types
    printf("Float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);

    // Direct computation
    printf("\nRanges using direct computation:\n");

    // Char
    printf("Signed char: %d to %d\n", -(char)((unsigned char)~0 >> 1) - 1, (char)((unsigned char)~0 >> 1));
    printf("Unsigned char: 0 to %u\n", (unsigned char)~0);

    // Short
    printf("Signed short: %d to %d\n", -(short)((unsigned short)~0 >> 1) - 1, (short)((unsigned short)~0 >> 1));
    printf("Unsigned short: 0 to %u\n", (unsigned short)~0);

    // Int
    printf("Signed int: %d to %d\n", -(int)((unsigned int)~0 >> 1) - 1, (int)((unsigned int)~0 >> 1));
    printf("Unsigned int: 0 to %u\n", (unsigned int)~0);

    // Long
    printf("Signed long: %ld to %ld\n", -(long)((unsigned long)~0L >> 1) - 1, (long)((unsigned long)~0L >> 1));
    printf("Unsigned long: 0 to %lu\n", (unsigned long)~0L);

    // Long Long
    printf("Signed long long: %lld to %lld\n", -(long long)((unsigned long long)~0LL >> 1) - 1, (long long)((unsigned long long)~0LL >> 1));
    printf("Unsigned long long: 0 to %llu\n", (unsigned long long)~0LL);

    // Floating-point types - Direct computation is more complex and usually not done manually
    // due to platform and representation specifics. Therefore, we stick to standard headers for accuracy.

    // Heights in inches
    printf("\nHeights in inches:\n");
    double heightOfEverestInFeet = 29031.7;
    double heightOfEverestInInches = heightOfEverestInFeet * 12.0;

    // Banana length (FLT_MAX, DBL_MAX, and LDBL_MAX are all approximately 1E+37)
    double banayanLength = 1E+37;

    // Calculate the number of bananas needed
    double numBanayan = heightOfEverestInInches / banayanLength;

    printf("Height of Mount Everest: %.2lf feet\n", heightOfEverestInFeet);
    printf("Length of a magical banayan: %.2lf inches\n", banayanLength);
    printf("Number of bananas needed to reach the summit: %.2e banayan\n", numBanayan);

    // Get the value of FLT_RADIX
    printf("\nGet the value of FLT_RADIX:\n");
    int radix = FLT_RADIX;
    printf("The base (radix) of the exponent representation: %d\n", radix);

    printf("The maximum value of float = %.10e\n", FLT_MAX);
    printf("The minimum value of float = %.10e\n", FLT_MIN);

    printf("The number of digits in the number = %.10d\n", FLT_MANT_DIG);

    // Integer Data Types
    printf("\nInteger Data Types:\n");
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);

    printf("\nFloating - Point Data Types:\n");
    printf("Storage size for float : %zu \n", sizeof(float));
    printf("FLT_MAX     :   %g\n", (float)FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float)FLT_MIN);
    printf("-FLT_MAX    :   %g\n", (float)-FLT_MAX);
    printf("-FLT_MIN    :   %g\n", (float)-FLT_MIN);
    printf("DBL_MAX     :   %g\n", (double)DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double)DBL_MIN);
    printf("-DBL_MAX     :  %g\n", (double)-DBL_MAX);
    printf("Precision value: %d\n", FLT_DIG);

    return 0;
}
