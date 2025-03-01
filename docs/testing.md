---
layout: default
title: Testing
---

# Testing the Picol Interpreter

This document describes how to run and create tests for the Picol interpreter.

## Test Suite Overview

The Picol test suite consists of both unit tests written in C and functional tests written in Tcl. The tests verify that the interpreter works correctly across various use cases.

## Running Tests

### Running All Tests

To run the entire test suite:

```bash
make test
```

### Running Individual Tests

To run a specific test:

```bash
./test_runner test_name
```

## Test Structure

### Unit Tests

Unit tests are located in the `tests/` directory and focus on testing individual components of the interpreter.

```c
// Example unit test
void test_variable_creation() {
    struct picolInterp *interp = picolCreateInterp();
    picolSetVar(interp, "testvar", "value");
    assert(strcmp(picolGetVar(interp, "testvar"), "value") == 0);
    picolFreeInterp(interp);
}
```

### Functional Tests

Functional tests are written in Tcl and test the interpreter as a whole.

```tcl
# Example functional test
set x 10
set y 20
set z [expr $x + $y]
if {$z != 30} {
    error "Addition failed: expected 30, got $z"
}
puts "Addition test passed"
```

## Writing New Tests

### Adding a Unit Test

1. Create a new test function in the appropriate test file
2. Add the test to the test registry
3. Update the test runner to include your test

```c
void my_new_test() {
    // Test logic here
    assert(condition_to_test);
}

// Add to test registry
TEST_REGISTER(my_new_test, "Description of my new test");
```

### Adding a Functional Test

1. Create a new .tcl file in the tests directory
2. Add your test logic
3. Include assertions to verify expected behavior
4. Add the test to the test suite configuration

```tcl
# my_new_test.tcl
source "test_helpers.tcl"

# Test setup
set input "value"

# Execute test
set result [process $input]

# Verify results
assert_equal "expected" $result "The process function should return 'expected'"

puts "Test passed!"
```

## Test Coverage

The goal is to maintain high test coverage of the Picol codebase. Current coverage metrics:

- Core interpreter: ~90% coverage
- Built-in commands: ~85% coverage
- Parser components: ~95% coverage

## Continuous Integration

Tests are automatically run on all pull requests and commits to the main branch using GitHub Actions.

## Debugging Failed Tests

When a test fails, you can enable additional debugging output:

```bash
PICOL_DEBUG=1 ./test_runner test_name
```

This will show detailed information about the interpreter state during test execution.

## Testing Best Practices

1. Each test should focus on a single aspect of functionality
2. Tests should be independent and not rely on other tests
3. Always clean up after your tests to avoid affecting other tests
4. Use meaningful assert messages to make failures easier to understand
5. Consider edge cases and error conditions in your tests
