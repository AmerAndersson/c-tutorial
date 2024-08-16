/**
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest.
 */
#include <stdbool.h>
#include <stdio.h>

void remove_comments(FILE *input, FILE *output);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    remove_comments(input, output);

    fclose(input);
    fclose(output);

    return 0;
}

void remove_comments(FILE *input, FILE *output) {
    char ch, next_ch;
    bool in_string = false;
    bool in_char = false;
    bool in_single_line_comment = false;
    bool in_multi_line_comment = false;

    while ((ch = fgetc(input)) != EOF) {
        if (in_single_line_comment) {
            if (ch == '\n') {
                in_single_line_comment = false;
                fputc(ch, output);
            }
        } else if (in_multi_line_comment) {
            if (ch == '*' && (next_ch = fgetc(input)) == '/') {
                in_multi_line_comment = false;
            } else if (ch == '*' && next_ch != EOF) {
                ungetc(next_ch, input);
            }
        } else if (in_string) {
            if (ch == '\\' && (next_ch = fgetc(input)) != EOF) {
                fputc(ch, output);
                ch = next_ch;  // escape sequence within string
            } else if (ch == '"') {
                in_string = false;
            }
            fputc(ch, output);
        } else if (in_char) {
            if (ch == '\\' && (next_ch = fgetc(input)) != EOF) {
                fputc(ch, output);
                ch = next_ch;  // escape sequence within char literal
            } else if (ch == '\'') {
                in_char = false;
            }
            fputc(ch, output);
        } else {
            if (ch == '/' && (next_ch = fgetc(input)) == '/') {
                in_single_line_comment = true;
            } else if (ch == '/' && next_ch == '*') {
                in_multi_line_comment = true;
            } else {
                if (ch == '"') {
                    in_string = true;
                } else if (ch == '\'') {
                    in_char = true;
                }
                fputc(ch, output);
                if (next_ch != EOF && ch != '/') {
                    ungetc(next_ch, input);
                } else if (ch == '/') {
                    fputc(next_ch, output);
                }
            }
        }
    }
}
