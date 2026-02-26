/*
 * Problem: Climbing Stairs
 *
 * Description:
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 * Input Format:
 * A single integer n
 *
 * Output Format:
 * Print the number of distinct ways to climb to the top
 *
 * Constraints:
 * - 1 <= n <= 45
 *
 * Example 1:
 * Input:
 * 2
 *
 * Output:
 * 2
 *
 * Explanation:
 * There are two ways to climb to the top:
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 * Example 2:
 * Input:
 * 3
 *
 * Output:
 * 3
 *
 * Explanation:
 * There are three ways to climb to the top:
 * 1. 1 + 1 + 1 steps
 * 2. 1 + 2 steps
 * 3. 2 + 1 steps
 *
 */

// Approach:
// This is a classic Dynamic Programming problem similar to Fibonacci.
// Key insight: To reach step n, you can come from step (n-1) or step (n-2).
// Therefore, ways[n] = ways[n-1] + ways[n-2]
//
// Base cases:
// - ways[1] = 1 (only one way: take 1 step)
// - ways[2] = 2 (1+1 or 2)
//
// We can optimize space by only keeping track of the previous two values instead of an entire array.
//
// Complexity:
// - Time Complexity: O(n) - single pass from 1 to n
// - Space Complexity: O(1) - only using a few variables

#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int prev2 = 1;  // ways to reach step (i-2)
    int prev1 = 2;  // ways to reach step (i-1)
    int current;

    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    int ways = climbStairs(n);

    cout << "Number of distinct ways to climb " << n << " steps: " << ways << endl;

    // Show the pattern for clarity
    cout << "\nExplanation: This follows the Fibonacci-like pattern:" << endl;
    cout << "Steps 1: 1 way (1)" << endl;
    cout << "Steps 2: 2 ways (1+1, 2)" << endl;
    for (int i = 3; i <= min(n, 10); i++) {
        cout << "Steps " << i << ": " << climbStairs(i) << " ways" << endl;
    }

    return 0;
}