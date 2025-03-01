# FILE: /picol-documentation/picol-documentation/docs/project_structure.md
# Picol Project Structure

This document provides an overview of the Picol interpreter's structure using UML diagrams.

## Picol Code Structure Overview

The Picol interpreter is a small Tcl-like language implementation in ~500 lines of C code. Here's an overview of its main components and their relationships based on analysis of the source code.

## Core Data Structures

## Function Relationships
```mermaid
flowchart TD
    main --> picolInitInterp
    main --> picolRegisterCoreCommands
    main --> picolEval
    
    picolEval --> picolInitParser
    picolEval --> picolGetToken
    picolEval --> picolGetCommand
    
    picolGetToken --> picolParseSep
    picolGetToken --> picolParseEol
    picolGetToken --> picolParseCommand
    picolGetToken --> picolParseVar
    picolGetToken --> picolParseBrace
    picolGetToken --> picolParseString
    picolGetToken --> picolParseComment
    
    picolInitInterp --> malloc
    
    picolRegisterCoreCommands --> picolRegisterCommand
    picolRegisterCommand --> picolGetCommand
    picolRegisterCommand --> malloc
    
    picolCommandCallProc --> picolSetVar
    picolCommandCallProc --> picolEval
    picolCommandCallProc --> picolDropCallFrame
```

## Core Commands Implementation
```mermaid
classDiagram
    class CommandFunctions {
        <<interface>>
        +picolCommandMath()
        +picolCommandSet()
        +picolCommandPuts()
        +picolCommandIf()
        +picolCommandWhile()
        +picolCommandRetCodes()
        +picolCommandCallProc()
        +picolCommandProc()
        +picolCommandReturn()
    }
    
    picolInterp --> CommandFunctions : calls
```

## Parser Token Types
```mermaid
classDiagram
    class TokenTypes {
        PT_ESC
        PT_STR
        PT_CMD
        PT_VAR
        PT_SEP
        PT_EOL
        PT_EOF
    }
    
    picolParser --> TokenTypes : uses
```

## Return Codes
```mermaid
classDiagram
    class ReturnCodes {
        PICOL_OK
        PICOL_ERR
        PICOL_RETURN
        PICOL_BREAK
        PICOL_CONTINUE
    }
    
    picolEval --> ReturnCodes : returns
    CommandFunctions --> ReturnCodes : returns
```

## Test Suite Structure
```mermaid
flowchart TD
    subgraph "Test Components"
        test_basic[test_basic.c]
        test_edge[test_edge.c]
        test_performance[test_performance.c]
        test_runner[test_runner.c]
        picol_test_h[picol_test.h]
    end
    
    subgraph "Build System"
        makefile[Makefile]
        run_tests_sh[run_tests.sh]
    end
    
    subgraph "Test Scripts"
        basic_tcl[basic.tcl]
        advanced_tcl[advanced.tcl]
        edge_cases_tcl[edge_cases.tcl]
        performance_tcl[performance.tcl]
    end
    
    picol_c[picol.c] --> picol_test_h
    picol_test_h --> test_basic
    picol_test_h --> test_edge
    picol_test_h --> test_performance
    picol_test_h --> test_runner
    
    test_basic --> test_runner
    test_edge --> test_runner
    test_performance --> test_runner
    
    makefile --> test_basic
    makefile --> test_edge
    makefile --> test_performance
    makefile --> test_runner
    
    run_tests_sh --> makefile
```

## Memory Management
```mermaid
flowchart TD
    subgraph "Memory Allocation"
        malloc
        strdup
        realloc
    end
    
    subgraph "Memory Deallocation"
        free
        picolDropCallFrame
    end
    
    picolInterp --> malloc
    picolInterp --> strdup
    picolInterp --> free
    
    picolSetVar --> malloc
    picolSetVar --> strdup
    picolSetVar --> free
    
    picolRegisterCommand --> malloc
    picolRegisterCommand --> strdup
    
    picolEval --> malloc
    picolEval --> realloc
    picolEval --> free
    
    picolDropCallFrame --> free
```

## Project File Structure
```mermaid
flowchart TD
    subgraph "Project Root"
        picol_c[picol.c]
    end
    
    subgraph "Tests Directory"
        test_dir[tests/]
        test_dir --> test_runner[test_runner.c]
        test_dir --> test_basic[test_basic.c]
        test_dir --> test_edge[test_edge.c]
        test_dir --> test_performance[test_performance.c]
        test_dir --> picol_test_h[picol_test.h]
        test_dir --> makefile[Makefile]
        test_dir --> run_tests[run_tests.sh]
        test_dir --> test_guide[TEST_GUIDE.md]
        test_dir --> test_scripts[test_scripts/]
        test_scripts --> basic_tcl[basic.tcl]
        test_scripts --> advanced_tcl[advanced.tcl]
        test_scripts --> edge_cases_tcl[edge_cases.tcl]
        test_scripts --> performance_tcl[performance.tcl]
    end
    
    subgraph "Build Directory"
        build_dir[build/]
        build_dir --> build_picol[picol]
        build_dir --> test_build[tests/]
        test_build --> test_runner_bin[test_runner]
        test_build --> test_basic_bin[test_basic_standalone]
        test_build --> test_edge_bin[test_edge_standalone]
        test_build --> test_performance_bin[test_performance_standalone]
    end
```
## Function Summary

| Function | Purpose |
|----------|---------|
| picolInitParser | Initialize the parser with a string to parse |
| picolGetToken | Get the next token from the input |
| picolParseSep, picolParseEol, etc. | Parse specific token types |
| picolInitInterp | Initialize the interpreter structure |
| picolSetResult | Set the result string of the interpreter |
| picolGetVar | Get a variable value by name |
| picolSetVar | Set a variable to a value |
| picolGetCommand | Get a command by name |
| picolRegisterCommand | Register a new command |
| picolEval | Evaluate a Tcl script |
| picolCommandMath, etc. | Core command implementations |

This project structure document uses Mermaid diagrams to visualize different aspects of the Picol interpreter:

1. Core data structures and their relationships
2. Function call relationships
3. Command implementation structure
4. Parser token types
5. Return code enumeration
6. Test suite organization
7. Memory management flow
8. Project file structure

The diagrams provide a clear overview of how the interpreter is structured, which is helpful for understanding the code organization and for onboarding new contributors to the project.