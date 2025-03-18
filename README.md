# Lexer-Oprator
# CCX Tokenizer

## Overview

This project is a simple tokenizer for the CCX programming language. It reads an input file and identifies keywords, operators, and other tokens. The tokenizer supports handling multi-line comments, string literals, and character literals.

## Features

- Recognizes and categorizes CCX keywords.

- Identifies CCX operators.

- Ignores comments and correctly processes string and character literals.

- Reads input files and tokenizes their contents.

## Technologies Used

- C Programming Language: The tokenizer is implemented in C for efficient text processing.

- Standard Libraries: Used libraries include stdio.h, stdlib.h, string.h, and ctype.h for file handling, string operations, and character classification.

## How It Works

- The program reads a file line by line.

- It checks for and handles multi-line comments.

- It detects string and character literals.

- It identifies operators using a predefined list.

- It checks for keywords from a predefined set.

- It prints categorized tokens to the console.

## How to Use

- Compile the program using a C compiler, such as GCC:

`gcc tokenizer.c -o tokenizer`

- Run the executable with an input file:

`./tokenizer <filename>`

# Example Output

Given an input file:
```
if x := 10 then
  while x > 0 loop
        x := x - 1;
    end loop;
```

The output will be:
```
Keyword: if 
Token: x
Operator: :=
Token: 10
Keyword: then
Keyword: while
Token: x
Operator: >
Token: 0
Token: loop
Token: x
Operator: :=
Token: x
Operator: -
Token: 1
Operator: ;
Keyword: end
Token: loop
Operator: ;
```

