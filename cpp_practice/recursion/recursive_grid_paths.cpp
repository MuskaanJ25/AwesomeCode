/*
 * Problem: Count Paths in Grid (Recursive)
 *
 * Description:
 * Given a 2D grid of size m x n, starting from the top-left corner (0, 0),
 * count the number of unique paths to reach the bottom-right corner (m-1, n-1).
 * You can only move right or down at any point in time.
 *
 * Input Format:
 * Two integers m and n (rows and columns of grid)
 *
 * Output Format:
 * Print the number of unique paths
 *
 * Constraints:
 * - 1 <= m, n <= 20
 * - (Note: Larger values may cause stack overflow due to recursion depth)
 *
 * Example:
 * Input:
 * 3 7
 *
 * Output:
 * Number of unique paths: 28
 *
 * Explanation:
 * From a 3x7 grid, there are 28 unique paths from top-left to bottom-right
 * using only right and down moves.
 *
 */

// Approach:
// Use recursion to explore all possible paths.
// Base cases:
//   - If we reach the destination (m-1, n-1), return 1 (found a path)
//   - If we go out of bounds, return 0 (invalid path)
// Recursive case:
//   - Sum of paths by moving right and paths by moving down
//   - countPaths(row, col, m, n) = countPaths(row+1, col, m, n) + countPaths(row, col+1, m, n)
//
// Complexity:
// - Time Complexity: O(2^(m+n)) - exponential due to overlapping subproblems
// - Space Complexity: O(m+n) - recursion stack depth
//
// Note: This is a basic recursive solution. For larger inputs, memoization would
// be needed to improve performance.

#include <iostream>
using namespace std;

long long countPaths(int row, int col, int m, int n) {
    // If we reached the destination
    if (row == m - 1 && col == n - 1) {
        return 1;
    }

    // If we went out of bounds
    if (row >= m || col >= n) {
        return 0;
    }

    // Explore both directions (right and down)
    long long down = countPaths(row + 1, col, m, n);
    long long right = countPaths(row, col + 1, m, n);

    return down + right;
}

int main() {
    int m, n;
    cout << "Enter grid dimensions (m n): ";
    cin >> m >> n;

    if (m < 1 || n < 1) {
        cout << "Error: Grid dimensions must be positive." << endl;
    } else if (m > 20 || n > 20) {
        cout << "Error: Grid dimensions too large for recursive solution." << endl;
    } else {
        long long result = countPaths(0, 0, m, n);
        cout << "Number of unique paths: " << result << endl;
    }

    return 0;
}