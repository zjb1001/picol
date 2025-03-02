---
layout: default
title: Project Structure
---

# Picol Project Structure

This document provides an overview of the Picol interpreter's structure using UML diagrams.

<script src="https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.min.js"></script>
<script>
  document.addEventListener("DOMContentLoaded", function() {
    mermaid.initialize({
      startOnLoad: true,
      theme: 'dark',
      securityLevel: 'loose',
      fontFamily: 'monospace',
      fontSize: 14
    });
    
    // Initialize Mermaid diagrams
    setTimeout(function() {
      mermaid.init(undefined, document.querySelectorAll('.language-mermaid'));
    }, 500);
  });
</script>

## Picol Code Structure Overview

The Picol interpreter is a small Tcl-like language implementation in ~500 lines of C code. Here's an overview of its main components and their relationships based on analysis of the source code.

## Core Data Structures

```mermaid
classDiagram
    class picolInterp {
        +int level
        +struct picolCallFrame* callframe
        +struct picolCmd* commands
        +char* result
    }
    
    class picolCallFrame {
        +struct picolVar* vars
        +struct picolCallFrame* parent
    }
    
    class picolVar {
        +char* name
        +char* val
        +struct picolVar* next
    }
    
    class picolCmd {
        +char* name
        +picolCmdFunc func
        +void* privdata
        +struct picolCmd* next
    }
    
    class picolParser {
        +char* text
        +char* p
        +int len
        +char* start
        +char* end
        +int type
        +int insidequote
    }
    
    picolInterp "1" --> "1" picolCallFrame : has
    picolInterp "1" --> "*" picolCmd : has commands list
    picolCallFrame "1" --> "*" picolVar : has vars list
    picolCallFrame "1" --> "0..1" picolCallFrame : parent
```

## Function Relationships

```mermaid
flowchart TD
    main[Main] --> picolInitInterp[Initialize Interpreter]
    main --> picolRegisterCoreCommands[Register Commands]
    main --> picolEval[Evaluate Code]
    
    picolEval --> picolInitParser[Initialize Parser]
    picolEval --> picolGetToken[Get Token]
    picolEval --> picolGetCommand[Get Command]
    
    picolGetToken --> picolParseSep[Parse Separator]
    picolGetToken --> picolParseEol[Parse End of Line]
    picolGetToken --> picolParseCommand[Parse Command]
    picolGetToken --> picolParseVar[Parse Variable]
    picolGetToken --> picolParseBrace[Parse Brace]
    picolGetToken --> picolParseString[Parse String]
    picolGetToken --> picolParseComment[Parse Comment]
    
    picolInitInterp --> malloc[Memory Allocation]
    
    picolRegisterCoreCommands --> picolRegisterCommand[Register Command]
    picolRegisterCommand --> picolGetCommand
    picolRegisterCommand --> malloc
    
    picolCommandCallProc[Call Procedure] --> picolSetVar[Set Variable]
    picolCommandCallProc --> picolEval
    picolCommandCallProc --> picolDropCallFrame[Drop Call Frame]
```

## Core Commands Implementation

```mermaid
classDiagram
    class CoreCommands {
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
    
    picolInterp --> CoreCommands : calls
```

## Parser Token Types

```mermaid
classDiagram
    class TokenTypes {
        <<enumeration>>
        PT_ESC
        PT_STR
        PT_CMD
        PT_VAR
        PT_SEP
        PT_EOL
        PT_EOF
    }
    
    picolParser --> TokenTypes : uses for classification
```

## Return Codes

```mermaid
classDiagram
    class ReturnCodes {
        <<enumeration>>
        PICOL_OK
        PICOL_ERR
        PICOL_RETURN
        PICOL_BREAK
        PICOL_CONTINUE
    }
    
    picolEval --> ReturnCodes : returns
    CoreCommands --> ReturnCodes : returns
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

## Project File Structure

```mermaid
flowchart TD
    subgraph "Project Root"
        picol_c[picol.c]
        project_structure[project_structure.md]
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
| `picolInitParser` | Initialize the parser with a string to parse |
| `picolGetToken` | Get the next token from the input |
| `picolParseSep`, `picolParseEol`, etc. | Parse specific token types |
| `picolInitInterp` | Initialize the interpreter structure |
| `picolSetResult` | Set the result string of the interpreter |
| `picolGetVar` | Get a variable value by name |
| `picolSetVar` | Set a variable to a value |
| `picolGetCommand` | Get a command by name |
| `picolRegisterCommand` | Register a new command |
| `picolEval` | Evaluate a Tcl script |
| `picolCommandMath`, etc. | Core command implementations |
| `picolDropCallFrame` | Free a call frame and its variables |
| `picolRegisterCoreCommands` | Register all built-in commands |

The diagrams above provide a clear overview of how the interpreter is structured, which is helpful for understanding the code organization and for onboarding new contributors to the project.

<style>
.language-mermaid {
  background: #1a1a1a;
  border-radius: 8px;
  padding: 16px;
  margin-bottom: 24px;
}
table {
  width: 100%;
  margin-bottom: 24px;
  border-collapse: collapse;
}
th, td {
  padding: 8px 12px;
  border: 1px solid #555;
}
th {
  background-color: #333;
}
</style>