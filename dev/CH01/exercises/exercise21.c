/*
 Write a program entab that replaces strings of blanks
 by the minimum number of tabs and blanks to achieve the same spacing.
 Use the same tab stops as for detab. When either a tab or a single
 blank would suffice to reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define TAB_WIDTH 4 /* Define the tab width */

void entab(FILE *input, FILE *output);

int main(void) {
    entab(stdin, stdout);
    return 0;
}
/* fgetc(): Reads a single character from a file */
/* fputc() : Writes a single character to a file */
void entab(FILE *input, FILE *output) {
    int ch, space_count = 0, column = 0;

    while ((ch = fgetc(input)) != EOF) {
        if (ch == ' ') {
            space_count++;
            column++;
            if (column % TAB_WIDTH == 0) {
                /* At a tab stop, so we can print a tab and reset space_count */
                fputc('\t', output);
                space_count = 0;
            }
        } else {
            /* If there are pending spaces, we need to output them */
            while (space_count > 0) {
                if (space_count >= TAB_WIDTH) {
                    fputc('\t', output);
                    space_count -= TAB_WIDTH;
                } else {
                    fputc(' ', output);
                    space_count--;
                }
            }
            fputc(ch, output);
            column++;
            if (ch == '\n') {
                column = 0;
            }
        }
    }
    /* Flush remaining spaces at the end of input */
    while (space_count > 0) {
        if (space_count >= TAB_WIDTH) {
            fputc('\t', output);
            space_count -= TAB_WIDTH;
        } else {
            fputc(' ', output);
            space_count--;
        }
    }
}
