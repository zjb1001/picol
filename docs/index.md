---
layout: default
title: Home
---

# Picol Documentation

Welcome to the Picol documentation site! Picol is a tiny Tcl interpreter implemented in ~500 lines of C code.

## Overview

Picol demonstrates how a complete interpreter can be implemented in a minimal amount of code while still providing useful functionality. This documentation covers its architecture, usage, and how to contribute to the project.

## Features

- Core Tcl-like syntax
- Variables and procedures
- Control structures (if, while)
- Basic arithmetic operations
- String handling
- Clean, understandable implementation

## Documentation Sections

- [Introduction](introduction.html)
- [Getting Started](getting-started.html)
- [Language Reference](reference/README.html)
- [Architecture](architecture.html)
- [Testing](testing.html)
- [Project Structure](project_structure.html)
- [Contributing](contributing.html)

## Quick Example

```tcl
proc fib {x} {
    if {$x < 2} {
        return $x
    } else {
        return [expr [fib [expr $x-1]] + [fib [expr $x-2]]]
    }
}

puts "Fibonacci of 10 is: [fib 10]"