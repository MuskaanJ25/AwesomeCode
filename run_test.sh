#!/bin/bash
# Helper script to run a single test case for a C++ practice program
# Usage: ./run_test.sh <program_name> <case_number>
# Example: ./run_test.sh two_sum 01

if [ $# -ne 2 ]; then
    echo "Usage: $0 <program_name> <case_number>"
    echo "Example: $0 two_sum 01"
    echo ""
    echo "Available programs:"
    ls -1 tests/ | grep -v "run_test" | sed 's/^/  /'
    exit 1
fi

PROGRAM=$1
CASE=$2
TEST_DIR="tests/$PROGRAM/case_$CASE"
PROGRAM_FILE=""

# Find the program file
if [ -f "cpp_practice/arrays/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/arrays/$PROGRAM.cpp"
elif [ -f "cpp_practice/binary_search/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/binary_search/$PROGRAM.cpp"
elif [ -f "cpp_practice/dp/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/dp/$PROGRAM.cpp"
elif [ -f "cpp_practice/hashing/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/hashing/$PROGRAM.cpp"
elif [ -f "cpp_practice/linked_list/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/linked_list/$PROGRAM.cpp"
elif [ -f "cpp_practice/multi_dimensional_arrays/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/multi_dimensional_arrays/$PROGRAM.cpp"
elif [ -f "cpp_practice/recursion/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/recursion/$PROGRAM.cpp"
elif [ -f "cpp_practice/stack/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/stack/$PROGRAM.cpp"
elif [ -f "cpp_practice/strings/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/strings/$PROGRAM.cpp"
elif [ -f "cpp_practice/structs/$PROGRAM.cpp" ]; then
    PROGRAM_FILE="cpp_practice/structs/$PROGRAM.cpp"
else
    echo "Error: Program '$PROGRAM' not found"
    echo "Available programs:"
    ls -1 tests/ | grep -v "run_test" | sed 's/^/  /'
    exit 1
fi

# Check if test case exists
if [ ! -d "$TEST_DIR" ]; then
    echo "Error: Test case $CASE not found for program '$PROGRAM'"
    echo "Available cases:"
    ls -1 tests/$PROGRAM/ | sed 's/^/  /'
    exit 1
fi

# Compile the program
echo "Compiling $PROGRAM_FILE..."
g++ -std=c++17 "$PROGRAM_FILE" -O2 -o /tmp/test_program

if [ $? -ne 0 ]; then
    echo "Error: Compilation failed"
    exit 1
fi

# Run the test
echo "Running test case $CASE..."
/tmp/test_program < "$TEST_DIR/input.txt" > /tmp/actual_output.txt

# Compare outputs
echo "Comparing output..."
diff -u "$TEST_DIR/output.txt" /tmp/actual_output.txt

if [ $? -eq 0 ]; then
    echo "✓ Test PASSED"
    exit 0
else
    echo "✗ Test FAILED"
    exit 1
fi