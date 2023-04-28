#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_IDENTIFIER_LENGTH 50

int main() {
    char input[] = "if (x == 5) {\n"
                   "    /* This is a comment */\n"
                   "    y = x + 1;\n"
                   "    return y;\n"
                   "}";

    regex_t regex[6];
    int reti;
    size_t nmatch = 1;
    regmatch_t pmatch[1];

    // Compile the regular expressions
    reti = regcomp(&regex[0], "[a-zA-Z][a-zA-Z0-9]*", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regular expression\n");
        exit(1);
    }

    reti = regcomp(&regex[1], "[0-9]+", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regular expression\n");
        exit(1);
    }

    reti = regcomp(&regex[2], "if|else|while|for|return", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regular expression\n");
        exit(1);
    }

    reti = regcomp(&regex[3], "\\+|-|\\*|/|%|=|==|!=|<|<=|>|>=|&&|\\|\\|", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regular expression\n");
        exit(1);
    }

    reti = regcomp(&regex[4], "\\(|\\)|\\{|\\}|\\[|\\]|;|,", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regular expression\n");
        exit(1);
    }

    reti = regcomp(&regex[5], "/\\*.*?\\*/|", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regular expression\n");
        exit(1);
    }

}
