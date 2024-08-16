/**
 * write a program that reads a set of text lines and prints the longest
 * The outline is simple enough:
 * -----------------------------------------------
 * while (there's another line)
 *      if (it's longer than the previous longest)
 *          (save it)
 *          (save its length) print longest line
 * ------------------------------------------------
 */
#include <stdio.h>

#define MAXLINE 1000  // maximum input line length

int get_line(char line[], int max_line);
void copy(char to[], char from[]);

// print the longest input line
int main(void) {
    int len;                // current line length
    int max;                // maximum length seen so far
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved here

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)  // there was a line
        printf("%s", longest);
    return 0;
}
// getline: read a line into s, return length
int get_line(char str[], int limit) {
    int c, i;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        str[i] = c;
    if (c == '\n') {
        str[i] = c;
        ++i;
    }
    str[i] = '\0';
    return i;
}
// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
