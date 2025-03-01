---
layout: default
title: Introduction
---

# Introduction to Picol

Picol is a tiny Tcl interpreter implemented in approximately 500 lines of C code. The project demonstrates how a complete interpreter can be implemented with minimal code while still providing useful functionality.

## What is Picol?

Picol stands for "Pico Language" and is a minimalist implementation of a Tcl-like language. It was created as an educational project to showcase interpreter design and implementation in a concise codebase.

## Why Picol?

- **Educational value**: Learn interpreter concepts without wading through thousands of lines of code
- **Extensibility**: Easily modify and extend to experiment with language features
- **Portability**: Small, self-contained codebase that can be embedded in other applications
- **Performance**: While not optimized for speed, its simplicity makes it easy to understand performance characteristics

## Key Components

- Lexer: Converts source code into tokens
- Parser: Structures tokens according to language grammar
- Evaluator: Executes parsed commands
- Core command implementations: Basic built-in functionality

## Design Philosophy

Picol follows a design philosophy of extreme simplicity while maintaining functionality. It demonstrates that a useful interpreter doesn't require a complex implementation.
