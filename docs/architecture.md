---
layout: default
title: Architecture
---

# Picol Architecture

This document provides an overview of the Picol interpreter's internal architecture and design.

## Overview

Picol is designed with simplicity as its core principle. The entire interpreter fits in about 500 lines of C code, making it easy to understand and modify.

## Core Components

### 1. Lexical Analysis (Tokenizer)

The tokenizer breaks down the input script into meaningful tokens such as commands, variables, strings, and control structures.

```c
int picolParse(char *p, char **start, char **end) {
    // Tokenization logic
}
```

### 2. Parser

The parser takes tokens from the lexer and organizes them according to Picol's grammar rules, creating a structure that can be executed.

```c
int picolParseCommand(struct picolInterp *i, char *t, char **start, char **end) {
    // Command parsing logic
}
```

### 3. Interpreter

The interpreter executes the parsed commands, manages variable scope, and handles control flow.

```c
struct picolInterp {
    struct picolCmd *commands;  /* Command table */
    struct picolVar *variables; /* Variable table */
    char *result;              /* Result of last command */
};
```

### 4. Command Implementations

Built-in commands are implemented as C functions that interface with the interpreter.

```c
int picolCommandPuts(struct picolInterp *i, int argc, char **argv, void *privdata) {
    // Implementation of 'puts' command
}
```

## Data Structures

### Interpreter

The interpreter maintains the global state, including command and variable tables.

### Variable Table

Variables are stored in a linked list for easy lookup and modification.

```c
struct picolVar {
    char *name;               /* Variable name */
    char *val;                /* Variable value */
    struct picolVar *next;    /* Next variable in the list */
};
```

### Command Table

Commands (both built-in and user-defined) are stored in a command table.

```c
struct picolCmd {
    char *name;               /* Command name */
    picolCmdFunc func;        /* Implementation function */
    void *privdata;           /* Private data for the command */
    struct picolCmd *next;    /* Next command in the list */
};
```

## Execution Flow

1. The user provides a Tcl script as input
2. The tokenizer breaks the script into tokens
3. The parser organizes tokens into commands and expressions
4. The interpreter evaluates commands one by one
5. Command handlers execute specific functionality
6. Results are returned to the user

## Memory Management

Picol uses simple memory management with explicit allocation and deallocation. Each command is responsible for managing its own memory.

## Error Handling

Errors are reported through the interpreter's result field and return codes.

```c
void picolSetResult(struct picolInterp *i, char *s) {
    // Set the result string
}
```

## Extension Points

Picol can be extended by:

1. Adding new built-in commands through `picolRegisterCommand()`
2. Creating custom procedures in Tcl
3. Modifying the interpreter core for new language features
