/*
 * Flag Initialization:

 * FLAG_ALIVE is initialized as 1 << 3, which is 8 (0x08).
 * FLAG_BROKEN is initialized as 1 << 4, which is 16 (0x10).
 *

 * Setting Attributes:
 * To set ON, TRANSPARENT, and BROKEN, the bitwise OR (|) is used to combine these flags.

 * Modifying Attributes:
 * To remove specific flags (TRANSPARENT and BROKEN), we use the bitwise AND (&)
 * with the negation  (~) of the flags to clear them. To set the ALIVE flag,
 * the bitwise OR (|) is used. Checking Flags:

 * To check if a flag is set, we use bitwise AND (&) and verify the result is non-zero.
 * To check if a flag is not set, we ensure the result of bitwise AND (&) is zero.
 * Final Modification:

 * To set only the EDIBLE flag, we directly assign attributes to FLAG_EDIBLE.
 * This code manipulates the flags using bitwise operations
 * and passes all the assertions, ensuring the correct behavior.
 */
#include <assert.h>
#include <stdio.h>

/* Initialize the flags */

const short FLAG_ON = 1 << 0;           // 1  (0x01)
const short FLAG_MOVEMENT = 1 << 1;     // 2  (0x02)
const short FLAG_TRANSPARENT = 1 << 2;  // 4  (0x04)
const short FLAG_ALIVE = 1 << 3;        // 8  (0x08)
const short FLAG_BROKEN = 1 << 4;       // 16 (0x10)
const short FLAG_EDIBLE = 1 << 5;       // 32 (0x20)

int main(void) {
    short attributes = 0;

    /* Set the attributes ON, TRANSPARENT, and BROKEN */
    attributes |= FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN;
    assert(attributes == (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN));

    /* Modify (set/clear/toggle) so the only attributes are ON and ALIVE */
    attributes &= ~(FLAG_TRANSPARENT | FLAG_BROKEN);  // Clear TRANSPARENT and BROKEN
    attributes |= FLAG_ALIVE;                         // Set ALIVE
    assert(attributes == (FLAG_ON | FLAG_ALIVE));

    /* Check if the ALIVE flag is set */
    assert((attributes & FLAG_ALIVE) != 0);

    /* Check if the BROKEN flag is not set */
    assert((attributes & FLAG_BROKEN) == 0);

    /* Modify so only the EDIBLE attribute is set */
    attributes = FLAG_EDIBLE;
    assert(attributes == FLAG_EDIBLE);
    
    printf("Done!");
    printf("\n");

    // a = 5 (00000101 in 8-bit binary), b = 9 (00001001 in
    // 8-bit binary)
    unsigned int a = 5, b = 9;

    // The result is 00000001
    printf("a = %u, b = %u\n", a, b);
    printf("a&b = %u\n", a & b);

    // The result is 00001101
    printf("a|b = %u\n", a | b);

    // The result is 00001100
    printf("a^b = %u\n", a ^ b);

    // The result is 11111111111111111111111111111010
    // (assuming 32-bit unsigned int)
    printf("~a = %u\n", a = ~a);

    // The result is 00010010
    printf("b<<1 = %u\n", b << 1);

    // The result is 00000100
    printf("b>>1 = %u\n", b >> 1);

    return 0;
}
