/*
 * Problem: Matrix Diagonal Sum
 *
 * Description:
 * Given a square matrix, calculate the sum of the elements on the main diagonal
 * (top-left to bottom-right) and the secondary diagonal (top-right to bottom-left).
 * If the matrix has an odd size, the center element should be counted only once.
 *
 * Input Format:
 * First line: n (size of matrix, n x n)
 * Next n lines: n space-separated integers per row
 *
 * Output Format:
 * Print the sum of both diagonals
 *
 * Constraints:
 * - 1 <= n <= 100
 * - -100 <= matrix[i][j] <= 100
 *
 * Example:
 * Input:
 * 3
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * Output:
 * Sum of diagonals: 25
 *
 * Explanation:
 * Main diagonal: 1, 5, 7 (but note: center element 5 is shared)
 * Secondary diagonal: 3, 5, 7
 * Both diagonals combined (without double-counting center): 1 + 5 + 3 + 7 + 9 + 5 = 30
 * Actually, for a 3x3 matrix:
 * - Main diagonal indices: (0,0)=1, (1,1)=5, (2,2)=9 → sum = 15
 * - Secondary diagonal indices: (0,2)=3, (1,1)=5, (2,0)=7 → sum = 15
 * - Total = 15 + 15 - 5 (center counted twice) = 25
 *
 */

// Approach:
// Iterate through the matrix with a single loop.
// For each row i, add the main diagonal element at (i, i).
// Add the secondary diagonal element at (i, n-1-i).
// If n is odd and i is the center row, subtract the center element once
// to avoid double-counting.
//
// Complexity:
// - Time Complexity: O(n) - single pass through n rows
// - Space Complexity: O(1) - only using a few variables

#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        // Add main diagonal element
        sum += matrix[i][i];
        // Add secondary diagonal element
        sum += matrix[i][n - 1 - i];
    }

    // If matrix size is odd, subtract the center element (counted twice)
    if (n % 2 == 1) {
        sum -= matrix[n / 2][n / 2];
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter matrix elements row by row:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = diagonalSum(matrix);
    cout << "Sum of diagonals: " << result << endl;

    return 0;
}