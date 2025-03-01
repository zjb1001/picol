#!/bin/bash

# Define build directories
BUILD_DIR="../build"
TEST_BUILD_DIR="$BUILD_DIR/tests"

# Compile all the tests
echo "Compiling test suite..."
make all

echo "=========================================="
echo "Running individual test categories:"
echo "=========================================="

echo -e "\n--- BASIC FUNCTIONALITY TESTS ---"
$TEST_BUILD_DIR/test_basic_standalone

echo -e "\n--- EDGE CASE TESTS ---"
$TEST_BUILD_DIR/test_edge_standalone

echo -e "\n--- PERFORMANCE TESTS ---"
$TEST_BUILD_DIR/test_performance_standalone

echo -e "\n=========================================="
echo "Running combined test runner:"
echo "=========================================="
$TEST_BUILD_DIR/test_runner

# Run test scripts with the Picol interpreter
echo -e "\n=========================================="
echo "Running test scripts with the Picol interpreter:"
echo "=========================================="

# Compile Picol if needed
if [ ! -f "$BUILD_DIR/picol" ]; then
    echo "Compiling Picol interpreter..."
    make $BUILD_DIR/picol
fi

# Run the test scripts
echo -e "\nRunning basic tests:"
$BUILD_DIR/picol test_scripts/basic.tcl

echo -e "\nRunning advanced tests:"
$BUILD_DIR/picol test_scripts/advanced.tcl

echo -e "\nRunning edge case tests:"
$BUILD_DIR/picol test_scripts/edge_cases.tcl

echo -e "\nRunning performance tests (this may take a while):"
time $BUILD_DIR/picol test_scripts/performance.tcl

echo -e "\n=========================================="
echo "All tests completed!"
echo "=========================================="
