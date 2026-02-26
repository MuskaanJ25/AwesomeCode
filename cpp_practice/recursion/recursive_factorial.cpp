/*
 * Problem: Recursive Factorial
 *
 * Description:
 * Calculate the factorial of a non-negative integer using recursion.
 * Factorial of n (denoted as n!) is the product of all positive integers from 1 to n.
 * By definition, 0! = 1.
 *
 * Input Format:
 * A single integer n
 *
 * Output Format:
 * Print the factorial of n
 *
 * Constraints:
 * - 0 <= n <= 20
 * - (Note: 21! exceeds the range of 64-bit integer)
 *
 * Example:
 * Input:
 * 5
 *
 * Output:
 * Factorial of 5: 120
 *
 * Explanation:
 * 5! = 5 * 4 * 3 * 2 * 1 = 120
 *
 */

// Approach:
// Use recursion to calculate factorial.
// Base case: factorial(0) = 1 and factorial(1) = 1
// Recursive case: factorial(n) = n * factorial(n-1)
// The function calls itself with a smaller argument until it reaches the base case.
//
// Complexity:
// - Time Complexity: O(n) - n recursive calls
// - Space Complexity: O(n) - recursion stack depth of n

#include <iostream>
using namespace std;

// Recursive function to calculate factorial
long long factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
    } else if (n > 20) {
        cout << "Error: Input too large. Factorial exceeds maximum value." << endl;
    } else {
        long long result = factorial(n);
        cout << "Factorial of " << n << ": " << result << endl;
    }

    return 0;
}