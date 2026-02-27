#!/bin/bash
# Run all test cases for all C++ practice programs
# Returns non-zero exit code if any test fails

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Statistics
TOTAL_PROGRAMS=0
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0
FAILED_PROGRAMS=""

# Temporary directory for compiled programs
BUILD_DIR="/tmp/cpp_practice_build"

# Create build directory
mkdir -p "$BUILD_DIR"

echo "======================================"
echo "Running All C++ Practice Tests"
echo "======================================"
echo ""

# Define all programs and their file locations
declare -A PROGRAMS=(
    ["best_time_to_buy_and_sell_stock"]="cpp_practice/arrays/best_time_to_buy_and_sell_stock.cpp"
    ["two_sum"]="cpp_practice/arrays/two_sum.cpp"
    ["binary_search"]="cpp_practice/binary_search/binary_search.cpp"
    ["climbing_stairs"]="cpp_practice/dp/climbing_stairs.cpp"
    ["top_k_frequent_elements"]="cpp_practice/hashing/top_k_frequent_elements.cpp"
    ["reverse_linked_list"]="cpp_practice/linked_list/reverse_linked_list.cpp"
    ["matrix_diagonal_sum"]="cpp_practice/multi_dimensional_arrays/matrix_diagonal_sum.cpp"
    ["matrix_transpose"]="cpp_practice/multi_dimensional_arrays/matrix_transpose.cpp"
    ["row_max_sum"]="cpp_practice/multi_dimensional_arrays/row_max_sum.cpp"
    ["recursive_factorial"]="cpp_practice/recursion/recursive_factorial.cpp"
    ["recursive_grid_paths"]="cpp_practice/recursion/recursive_grid_paths.cpp"
    ["valid_parentheses"]="cpp_practice/stack/valid_parentheses.cpp"
    ["valid_anagram"]="cpp_practice/strings/valid_anagram.cpp"
    ["student_average"]="cpp_practice/structs/student_average.cpp"
)

# Check if tests directory exists
if [ ! -d "tests" ]; then
    echo -e "${RED}Error: tests directory not found!${NC}"
    exit 1
fi

# Test each program
for PROGRAM_NAME in "${!PROGRAMS[@]}"; do
    PROGRAM_FILE="${PROGRAMS[$PROGRAM_NAME]}"
    TEST_BASE="tests/$PROGRAM_NAME"

    echo -e "${YELLOW}Testing $PROGRAM_NAME...${NC}"

    # Check if program file exists
    if [ ! -f "$PROGRAM_FILE" ]; then
        echo -e "  ${RED}✗ Program file not found: $PROGRAM_FILE${NC}"
        FAILED_TESTS=$((FAILED_TESTS + 10))
        FAILED_PROGRAMS="$FAILED_PROGRAMS $PROGRAM_NAME"
        TOTAL_TESTS=$((TOTAL_TESTS + 10))
        TOTAL_PROGRAMS=$((TOTAL_PROGRAMS + 1))
        continue
    fi

    # Check if tests exist for this program
    if [ ! -d "$TEST_BASE" ]; then
        echo -e "  ${RED}✗ Tests directory not found: $TEST_BASE${NC}"
        FAILED_TESTS=$((FAILED_TESTS + 10))
        FAILED_PROGRAMS="$FAILED_PROGRAMS $PROGRAM_NAME"
        TOTAL_TESTS=$((TOTAL_TESTS + 10))
        TOTAL_PROGRAMS=$((TOTAL_PROGRAMS + 1))
        continue
    fi

    # Compile the program
    BINARY="$BUILD_DIR/$PROGRAM_NAME"
    echo -n "  Compiling..."
    if g++ -std=c++17 "$PROGRAM_FILE" -O2 -o "$BINARY" 2>/dev/null; then
        echo -e " ${GREEN}OK${NC}"
    else
        echo -e " ${RED}FAILED${NC}"
        echo -e "  ${RED}✗ Compilation failed for $PROGRAM_NAME${NC}"
        FAILED_TESTS=$((FAILEDTests + 10))
        FAILED_PROGRAMS="$FAILED_PROGRAMS $PROGRAM_NAME"
        TOTAL_TESTS=$((TOTAL_TESTS + 10))
        TOTAL_PROGRAMS=$((TOTAL_PROGRAMS + 1))
        continue
    fi

    # Run all test cases for this program
    PROGRAM_PASSED=0
    PROGRAM_FAILED=0
    FAILED_CASES=""

    for CASE_NUM in {01..10}; do
        TEST_DIR="$TEST_BASE/case_$CASE_NUM"

        if [ ! -d "$TEST_DIR" ]; then
            echo "    ${YELLOW}⚠ Test case $CASE_NUM not found, skipping${NC}"
            continue
        fi

        INPUT_FILE="$TEST_DIR/input.txt"
        OUTPUT_FILE="$TEST_DIR/output.txt"

        if [ ! -f "$INPUT_FILE" ] || [ ! -f "$OUTPUT_FILE" ]; then
            echo "    ${YELLOW}⚠ Test case $CASE_NUM incomplete, skipping${NC}"
            continue
        fi

        # Run the program with test input
        ACTUAL_OUTPUT=$(cat "$INPUT_FILE" | "$BINARY" 2>&1)

        # Compare outputs
        EXPECTED_OUTPUT=$(cat "$OUTPUT_FILE")

        if [ "$ACTUAL_OUTPUT" = "$EXPECTED_OUTPUT" ]; then
            PROGRAM_PASSED=$((PROGRAM_PASSED + 1))
            TOTAL_TESTS=$((TOTAL_TESTS + 1))
            PASSED_TESTS=$((PASSED_TESTS + 1))
        else
            PROGRAM_FAILED=$((PROGRAM_FAILED + 1))
            TOTAL_TESTS=$((TOTAL_TESTS + 1))
            FAILED_TESTS=$((FAILED_TESTS + 1))
            FAILED_CASES="$FAILED_CASES $CASE_NUM"
            echo "    ${RED}✗ Case $CASE_NUM FAILED${NC}"
        fi
    done

    TOTAL_PROGRAMS=$((TOTAL_PROGRAMS + 1))

    # Print summary for this program
    if [ $PROGRAM_FAILED -eq 0 ]; then
        echo -e "  ${GREEN}✓ All tests passed ($PROGRAM_PASSED/$((PROGRAM_PASSED + PROGRAM_FAILED)))${NC}"
    else
        echo -e "  ${RED}✗ Failed: $PROGRAM_FAILED/$((PROGRAM_PASSED + PROGRAM_FAILED)) (cases:$FAILED_CASES)${NC}"
        FAILED_PROGRAMS="$FAILED_PROGRAMS $PROGRAM_NAME"
    fi

    echo ""
done

# Print overall summary
echo "======================================"
echo "Test Summary"
echo "======================================"
echo "Programs tested: $TOTAL_PROGRAMS"
echo "Total tests: $TOTAL_TESTS"
echo -e "Passed: ${GREEN}$PASSED_TESTS${NC}"
echo -e "Failed: ${RED}$FAILED_TESTS${NC}"

if [ $FAILED_TESTS -eq 0 ]; then
    echo ""
    echo -e "${GREEN}✓ All tests PASSED!${NC}"
    exit 0
else
    echo ""
    echo -e "${RED}✗ Some tests FAILED.${NC}"
    echo -e "${RED}Failed programs:$FAILED_PROGRAMS${NC}"
    exit 1
fi