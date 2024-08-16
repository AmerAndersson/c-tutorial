/**
 * Write a program to check a C program for rudimentary syntax errors
 * like unmatched parentheses, brackets and braces. Don't forget about
 *  quotes, both single and double, escape sequences, and comments.
 * (This program is hard if you do it in full generality.)
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000

// Stack data structure
typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, char c);

char pop(Stack *s);

int isEmpty(Stack *s);

char peek(Stack *s);

int main(void) {
    Stack stack;
    stack.top = 0;

    int in_single_quote = 0, in_double_quote = 0, in_comment = 0, escape = 0;
    char c, last_char = '\0';

    while ((c = getchar()) != EOF) {
        if (escape) {
            escape = 0;
            continue;
        }

        if (c == '\\') {
            escape = 1;
            continue;
        }

        if (in_comment) {
            if (in_comment == 1 && last_char == '*' && c == '/') {
                in_comment = 0;
            }
            last_char = c;
            continue;
        }

        if (c == '/' && last_char == '/') {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (c == '*' && last_char == '/') {
            in_comment = 1;
            last_char = '\0';
            continue;
        }

        if (in_single_quote) {
            if (c == '\'' && !escape) {
                in_single_quote = 0;
            }
            last_char = c;
            continue;
        }

        if (in_double_quote) {
            if (c == '\"' && !escape) {
                in_double_quote = 0;
            }
            last_char = c;
            continue;
        }

        if (c == '\'') {
            in_single_quote = 1;
            last_char = c;
            continue;
        }

        if (c == '\"') {
            in_double_quote = 1;
            last_char = c;
            continue;
        }

        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&stack)) {
                printf("Unmatched %c\n", c);
                return 1;
            }
            char top = pop(&stack);
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                printf("Mismatched %c and %c\n", top, c);
                return 1;
            }
        }

        last_char = c;
    }

    if (!isEmpty(&stack)) {
        printf("Unmatched %c\n", peek(&stack));
        return 1;
    }

    printf("No unmatched parentheses, brackets, or braces found.\n");
    return 0;
}

void push(Stack *s, char c) {
    if (s->top < MAX_STACK_SIZE) {
        s->data[s->top++] = c;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

char pop(Stack *s) {
    if (s->top > 0) {
        return s->data[--s->top];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

int isEmpty(Stack *s) {
    return s->top == 0;
}

char peek(Stack *s) {
    if (s->top > 0) {
        return s->data[s->top - 1];
    } else {
        return '\0';
    }
}
