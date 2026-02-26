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
├── _template.cpp           # Template for creating new problems
├── README.md               # Detailed index and learning path
├── arrays/                 # Array-based problems
│   ├── two_sum.cpp
│   └── best_time_to_buy_and_sell_stock.cpp
├── strings/                # String manipulation problems
│   └── valid_anagram.cpp
├── hashing/                # Hash map and frequency problems
│   └── top_k_frequent_elements.cpp
├── stack/                  # Stack-based problems
│   └── valid_parentheses.cpp
├── linked_list/            # Linked list problems
│   └── reverse_linked_list.cpp
├── binary_search/          # Binary search problems
│   └── binary_search.cpp
└── dp/                     # Dynamic Programming (introductory)
    └── climbing_stairs.cpp
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

### Current Problems (8 problems)

| Category | Problem | Difficulty |
|----------|---------|------------|
| Arrays | Two Sum | Easy |
| Arrays | Best Time to Buy and Sell Stock | Easy |
| Strings | Valid Anagram | Easy |
| Hashing | Top K Frequent Elements | Medium |
| Stack | Valid Parentheses | Easy |
| Linked List | Reverse Linked List | Easy |
| Binary Search | Binary Search | Easy |
| DP | Climbing Stairs | Easy |

For a complete learning path and more details, see [cpp_practice/README.md](cpp_practice/README.md)

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