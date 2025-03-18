#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// List of CCX keywords
const char* keywords[] = {"accessor", "and", "array", "bool", "case", "character", "constant", "else", "elsif", "end", "exit", "float",
    "func", "if", "ifc", "in", "integer", "is", "mutator", "natural", "null", "of", "or", "others", "out", "pkg", "positive", "proc",
    "ptr", "range", "subtype", "then", "type", "when", "while"};

// List of CCX operators
const char* operators[] = {"<", ">", "(", ")", "+", "-", "*", "/", "|", "&", ";", ",", ":", "=", "$", "@",
    ":=", "..", ".", "<<", ">>", "<>", "<=", ">=", "**", "==", "!=", "=>", "[", "]", "{" , "}", "{:", "}:"};

#define NUM_KEYWORDS (sizeof(keywords) / sizeof(keywords[0]))
#define NUM_OPERATORS (sizeof(operators) / sizeof(operators[0]))

// Function to check if a string is a keyword
int isKeyword(const char* str) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is an operator
const char* isOperator(const char* str) {
    for (int i = 0; i < NUM_OPERATORS; i++) {
        if (strncmp(str, operators[i], strlen(operators[i])) == 0) {
            return operators[i];
        }
    }
    return NULL;
}

// Function to tokenize the input file
void tokenizeFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char* start = line;
        char buffer[256];
        int insideString = 0, insideChar = 0, insideComment = 0;
        
        while (*start) {
            if (!insideString && !insideChar && *start == '/' && *(start + 1) == '*') {
                insideComment = 1;
                start += 2;
                continue;
            }
            if (insideComment) {
                if (*start == '*' && *(start + 1) == '/') {
                    insideComment = 0;
                    start += 2;
                } else {
                    start++;
                }
                continue;
            }
            if (*start == '"') {
                insideString = !insideString;
                start++;
                continue;
            }
            if (*start == '\'') {
                insideChar = !insideChar;
                start++;
                continue;
            }
            
            if (isspace((unsigned char)*start)) {
                start++;
                continue;
            }
            
            const char* op = isOperator(start);
            if (op) {
                printf("Operator: %s\n", op);
                start += strlen(op);
                continue;
            }
            
            char* token = buffer;
            while (*start && !isspace((unsigned char)*start) && !isOperator(start)) {
                *token++ = *start++;
            }
            *token = '\0';
            
            if (isKeyword(buffer)) {
                printf("Keyword: %s\n", buffer);
            } else {
                printf("Token: %s\n", buffer);
            }
        }
    }
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    tokenizeFile(argv[1]);
    return 0;
}
