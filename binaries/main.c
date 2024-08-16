#include <stdio.h>

/*
 *  128  64  32  16   8   4   2   1   <-- starting 8 columns for 8 digits
 *    0   0   0   0   0   0   1   1   <-- multiply each columns by binary digits
 *  --- --- --- --- --- --- --- ---
 *    0   0   0   0   0   0   2   1   <-- add these up:  2 + 1  =  3
 */

// some nice number: 72, 108, 108, 111
int main(void) {
    unsigned char bytes[10] = {0};

    bytes[0] = 0x65;
    // 128 64 32 16 8 4 2 1

    for (int i = 0; i < 10; i++) {
        printf("[%2u] %3u", i, bytes[i]);
        printf("\n");
    }

    return 0;
}
