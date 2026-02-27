# AwesomeCode

Welcome to AwesomeCode - a collection of programming implementations and practice problems!

## Overview

This repository contains:
- **C++ Practice Problems** - A curated set of beginner-friendly LeetCode-style problems
- **Basic Data Structure Implementations** - Stack, Linked List, Queue, etc.
- **Advanced Topics** - Templates, Friend Classes, Inheritance examples

## C++ Practice Problems (NEW!)

A new `cpp_practice/` directory has been added containing beginner-friendly LeetCode-style problems perfect for CS freshmen.

### Directory Structure
```
cpp_practice/
├── _template.cpp                 # Template for creating new problems
├── README.md                     # Detailed index and learning path
├── arrays/                       # Array-based problems
│   ├── two_sum.cpp
│   └── best_time_to_buy_and_sell_stock.cpp
├── binary_search/                # Binary search problems
│   └── binary_search.cpp
├── dp/                           # Dynamic programming problems
│   └── climbing_stairs.cpp
├── hashing/                      # Hashing problems
│   └── top_k_frequent_elements.cpp
├── linked_list/                  # Linked list problems
│   └── reverse_linked_list.cpp
├── strings/                      # String manipulation problems
│   └── valid_anagram.cpp
├── structs/                      # Struct-based problems
│   └── student_average.cpp
├── multi_dimensional_arrays/     # 2D array problems
│   ├── matrix_diagonal_sum.cpp
│   ├── matrix_transpose.cpp
│   └── row_max_sum.cpp
├── recursion/                    # Recursion problems
│   ├── recursive_factorial.cpp
│   └── recursive_grid_paths.cpp
└── stack/                        # Stack problems
    └── valid_parentheses.cpp
```

### How to Run

Each problem file is a standalone C++17 program:

```bash
# Compile
g++ -std=c++17 cpp_practice/arrays/two_sum.cpp -O2 -o two_sum

# Run
./two_sum
```

### Features
- **Complete Problem Statements**: Full problem description in comments at the top of each file
- **Interactive I/O**: Each program reads from stdin and prints to stdout
- **Detailed Explanations**: Approach and complexity analysis included
- **Standalone**: No dependencies between files - each compiles independently

### Current Problems (14 problems)

| Category | Problem | Difficulty |
|----------|---------|------------|
| Arrays | Two Sum | Easy |
| Arrays | Best Time to Buy and Sell Stock | Easy |
| Binary Search | Binary Search | Easy |
| Dynamic Programming | Climbing Stairs | Easy |
| Hashing | Top K Frequent Elements | Easy |
| Linked List | Reverse Linked List | Easy |
| Strings | Valid Anagram | Easy |
| Structs | Student Average | Easy |
| Multi-dimensional Arrays | Matrix Diagonal Sum | Easy |
| Multi-dimensional Arrays | Matrix Transpose | Easy |
| Multi-dimensional Arrays | Row Max Sum | Easy |
| Recursion | Recursive Factorial | Easy |
| Recursion | Recursive Grid Paths | Easy |
| Stack | Valid Parentheses | Easy |

For a complete learning path and more details, see [cpp_practice/README.md](cpp_practice/README.md)

### Tests

Test cases are provided for all practice problems in the `tests/` directory. Each program has 10 test cases covering edge cases and typical scenarios.

#### Test Structure

```
tests/
├── two_sum/
│   ├── case_01/
│   │   ├── input.txt
│   │   └── output.txt
│   ├── case_02/
│   │   ├── input.txt
│   │   └── output.txt
│   └── ... (cases 03-10)
├── best_time_to_buy_and_sell_stock/
│   └── ... (10 test cases)
└── ... (other problems with 10 test cases each)
```

#### Running Tests

Test scripts are provided to automate testing:

```bash
# Run all tests for all programs
./run_all_tests.sh

# Run a specific test case for a program
./run_test.sh <program_name> <case_number>
# Example: ./run_test.sh two_sum 01
```

The `run_all_tests.sh` script compiles each program and runs all 10 test cases, providing a summary of passed/failed tests. It returns non-zero exit code if any test fails, making it suitable for CI/CD.

You can also run tests manually:

```bash
# Compile the program
g++ -std=c++17 cpp_practice/arrays/two_sum.cpp -O2 -o two_sum

# Run with test input and compare with expected output
./two_sum < tests/two_sum/case_01/input.txt > actual_output.txt
diff actual_output.txt tests/two_sum/case_01/output.txt
```

All test outputs include the program's prompts and complete stdout to match the original interface.

## Legacy Content

The original `hi.cpp` contains various implementations including:
- Basic algorithms (max, min, factorial, etc.)
- Stack implementation
- Linked lists (singly and circular)
- Queue (with optional resize)
- Template examples
- Friend classes and inheritance

## Contributing

When adding new C++ practice problems:
1. Follow the template in `cpp_practice/_template.cpp`
2. Use snake_case filenames matching LeetCode problem titles
3. Include complete problem statement in comments
4. Use C++17 standard
5. Ensure each file compiles independently

## License

Educational purposes only. Enjoy learning!