# C++ Practice Problems

This directory contains beginner-friendly LeetCode-style problems for CS freshmen to practice C++ programming.

## How to Run

Each file is a standalone C++17 program:

```bash
g++ -std=c++17 <filename>.cpp -O2 -o <filename>
./<filename>
```

Example:
```bash
g++ -std=c++17 arrays/two_sum.cpp -O2 -o two_sum
./two_sum
```

## Problem Categories

### Arrays
- `two_sum.cpp` - Find two numbers that add up to target
- `best_time_to_buy_and_sell_stock.cpp` - Max profit from stock prices

### Strings
- `valid_anagram.cpp` - Check if two strings are anagrams

### Structs
- `student_average.cpp` - Calculate average scores using structs

### Multi-dimensional Arrays
- `matrix_diagonal_sum.cpp` - Sum of diagonal elements in a matrix
- `matrix_transpose.cpp` - Transpose a 2D matrix
- `row_max_sum.cpp` - Find row with maximum sum

### Recursion
- `recursive_factorial.cpp` - Calculate factorial using recursion
- `recursive_grid_paths.cpp` - Count paths in a grid using recursion

## Learning Path

1. **Start with Arrays**: `two_sum.cpp`, `best_time_to_buy_and_sell_stock.cpp`
2. **Move to Strings**: `valid_anagram.cpp`
3. **Learn Structs**: `student_average.cpp`
4. **Multi-dimensional Arrays**: `matrix_diagonal_sum.cpp`, `matrix_transpose.cpp`, `row_max_sum.cpp`
5. **Practice Recursion**: `recursive_factorial.cpp`, `recursive_grid_paths.cpp`

## File Format

Each problem file includes:
- Complete problem statement in comments at the top
- Input/output examples
- Constraints
- Approach explanation
- Time and space complexity
- Full compilable C++17 solution with `main()`

## Contributing

When adding new problems:
1. Follow the template in `_template.cpp`
2. Use snake_case filenames matching LeetCode problem titles
3. Include complete problem statement in comments
4. Use C++17 standard
5. Ensure each file compiles independently

## Tests

Test cases are provided for all practice problems in the `tests/` directory at the repository root.

### Test Structure

Each program has 10 test cases organized as follows:

```
tests/
├── two_sum/
│   ├── case_01/
│   │   ├── input.txt      # Test input (stdin)
│   │   └── output.txt     # Expected output (stdout)
│   ├── case_02/
│   │   ├── input.txt
│   │   └── output.txt
│   └── ... (cases 03-10)
└── [other programs with similar structure]
```

### Running Tests

To test a program against its test cases:

```bash
# Navigate to cpp_practice directory
cd cpp_practice

# Compile the program
g++ -std=c++17 arrays/two_sum.cpp -O2 -o two_sum

# Run with test input
./two_sum < ../tests/two_sum/case_01/input.txt

# Compare output with expected result
./two_sum < ../tests/two_sum/case_01/input.txt > actual.txt
diff actual.txt ../tests/two_sum/case_01/output.txt
```

### Test Coverage

Each program has 10 comprehensive test cases covering:
- Edge cases (boundary values, empty/single element inputs)
- Typical use cases
- Negative numbers, zeros, positive numbers
- Different input sizes

The `output.txt` files contain the complete program output including any prompts or informational messages to match the original interactive interface.