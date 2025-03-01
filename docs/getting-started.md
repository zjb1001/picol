---
layout: default
title: Getting Started
---

# Getting Started with Picol

This guide will help you set up and run Picol on your local machine.

## Prerequisites

- A C compiler (GCC, Clang, or MSVC)
- Basic command line knowledge
- Make (optional, for building with the Makefile)

## Building from Source

### Using Make

```bash
# Clone the repository
git clone https://github.com/yourusername/picol.git
cd picol

# Build the project
make

# Run the interpreter
./picol
```

### Manual Build

```bash
# Compile picol.c directly
gcc -o picol picol.c

# Run the interpreter
./picol
```

## Running Picol Scripts

You can run Picol scripts either by passing them as command-line arguments or through the interactive interpreter.

```bash
# Run a script file
./picol myscript.tcl

# Use the interactive interpreter
./picol
```

## Your First Picol Program

Create a file named `hello.tcl` with the following content:

```tcl
# Define a procedure
proc greet {name} {
    puts "Hello, $name!"
}

# Call the procedure
greet "Picol User"
```

Run it with:

```bash
./picol hello.tcl
```

## Next Steps

- Explore the [Language Reference](reference/README.md) to learn about Picol syntax
- Try implementing your own Picol commands
- Check out the [Architecture](architecture.md) section to understand how Picol works internally
