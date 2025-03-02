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

- [Introduction]({{ site.baseurl }}/introduction.html) - Overview of Picol and its features
- [Getting Started]({{ site.baseurl }}/getting-started.html) - How to build and run Picol
- [Language Reference]({{ site.baseurl }}/reference/) - Detailed syntax and command reference
- [Architecture]({{ site.baseurl }}/architecture.html) - Technical details of the Picol implementation
- [Testing]({{ site.baseurl }}/testing.html) - Information about the test suite and how to run tests
- [Project Structure]({{ site.baseurl }}/project_structure.html) - UML diagrams showing code organization
- [Contributing]({{ site.baseurl }}/contributing.html) - Guidelines for contributing to the project

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
```

## Home Navigation

You are currently on the [Home](index.md) page. To view project structure information, please see the [Project Structure](project_structure.md) page.

## Source Code

The complete source code for Picol is contained in a single C file of approximately 500 lines, making it easy to understand and modify.