/*
 * Bitmasks
 * To implement the described bit manipulation functionalities (setting, clearing, flipping,
 * and checking a bit) in C, you can define functions for each operation.
 * Below is the implementation of these functionalities in C:

 * 1. Setting bit n:
 *  - void set_bit(unsigned char *storage, int n):
 *  This function sets the nth bit by performing a bitwise OR operation with `1 << n`.

 *  2. Clearing bit n:
 *   - `void clear_bit(unsigned char *storage, int n)`:
 *   This function clears the nth bit by performing a bitwise AND operation with the bitwise NOT of `1 << n`.
 *
 *  3. Flipping bit n:
 *   - `void flip_bit(unsigned char *storage, int n)`:
 *    This function flips the nth bit by performing a bitwise XOR operation with `1 << n`.
 *
 *  4. Checking bit n:
 *   - `bool check_bit(unsigned char storage, int n)`:
 *    This function checks if the nth bit is set by performing a bitwise AND operation with `1 << n`.
 *   It returns `true` if the bit is set, otherwise it returns `false`.

 * Output:

 * The program initializes `storage` with the binary value `01000010` (0x42 in hexadecimal).
 * It performs the following operations:
 * 1. Sets the 3rd bit.
 * 2. Clears the 3rd bit.
 * 3. Flips the 3rd bit.
 * 4. Checks the 3rd bit.

 * The `printf` statements display the storage value after each operation
 * and indicate whether the bit is set or not.
 */

#include <stdbool.h>
#include <stdio.h>

// Function to set bit n
void set_bit(unsigned char *storage, int n);

// Function to clear bit n
void clear_bit(unsigned char *storage, int n);

// Function to flip bit n
void flip_bit(unsigned char *storage, int n);

// Function to check bit n
bool check_bit(unsigned char storage, int n);

int main(void) {
    unsigned char storage = 0x42;  // 01000010 in binary
    int n = 3;

    printf("Original storage: 0x%02X\n", storage);

    // Set bit n
    set_bit(&storage, n);
    printf("After setting bit %d: 0x%02X\n", n, storage);

    // Clear bit n
    clear_bit(&storage, n);
    printf("After clearing bit %d: 0x%02X\n", n, storage);

    // Flip bit n
    flip_bit(&storage, n);
    printf("After flipping bit %d: 0x%02X\n", n, storage);

    // Check bit n
    bool bit = check_bit(storage, n);
    printf("Bit %d is %s\n", n, bit ? "set" : "not set");

    return 0;
}
// Function to set bit n
void set_bit(unsigned char *storage, int n) { *storage |= 1 << n; }

// Function to clear bit n
void clear_bit(unsigned char *storage, int n) { *storage &= ~(1 << n); }

// Function to flip bit n
void flip_bit(unsigned char *storage, int n) { *storage ^= 1 << n; }

// Function to check bit n
bool check_bit(unsigned char storage, int n) { return storage & (1 << n); }
