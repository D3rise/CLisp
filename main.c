#include <stdio.h>
#include <stdlib.h>

// If we are compiling on Windows,
// we would not need editline library
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
};

void add_history() {};
#else
#include <editline/readline.h>
#endif

int main() {
    while(1) {
        char* input = readline("CLisp> ");
        add_history(input);

        printf("Hi %s, i'm dad\n", input);
        free(input);
    }

    return 0;
}