---
layout: default
title: Language Reference
---

# Picol Language Reference

This section provides detailed information about the Picol language syntax, commands, and features.

## Language Syntax

Picol follows a syntax similar to Tcl, with commands following this general format:

```
command arg1 arg2 arg3 ...
```

Commands are separated by newlines or semicolons:

```
command1 arg1 arg2; command2 arg1
```

## Variables

Define variables with `set`:

```tcl
set x 10
set name "Picol"
```

Access variable values using the `$` prefix:

```tcl
puts $name
set y [expr $x + 5]
```

## Control Structures

### Conditional Execution

```tcl
if {$x > 5} {
    puts "x is greater than 5"
} else {
    puts "x is not greater than 5"
}
```

### Loops

```tcl
# While loop
set i 0
while {$i < 10} {
    puts "i is $i"
    set i [expr $i + 1]
}
```

## Procedures

Define procedures using `proc`:

```tcl
proc add {a b} {
    return [expr $a + $b]
}
```

Call procedures:

```tcl
set result [add 3 4]
puts "The result is $result"
```

## Built-in Commands

- `puts`: Print a string
- `set`: Define or access variables
- `proc`: Define procedures
- `return`: Return a value from a procedure
- `expr`: Evaluate an expression
- `if`: Conditional execution
- `while`: Loop execution

## Expressions

Expressions can include:

- Arithmetic: `+`, `-`, `*`, `/`
- Comparison: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Logical: `&&`, `||`, `!`

Example:

```tcl
set result [expr ($a + $b) * ($c - 5)]
```

## String Handling

String concatenation:

```tcl
set fullname "$firstname $lastname"
```
