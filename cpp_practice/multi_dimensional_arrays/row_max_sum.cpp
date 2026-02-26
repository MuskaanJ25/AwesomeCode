/*
 * Problem: Find Row with Maximum Sum
 *
 * Description:
 * Given a 2D matrix, find the row that has the maximum sum of its elements.
 * If multiple rows have the same maximum sum, return the one with the smallest index.
 *
 * Input Format:
 * First line: rows cols (dimensions of matrix)
 * Next rows lines: cols space-separated integers per row
 *
 * Output Format:
 * Print the index of the row with maximum sum (0-based) and the sum
 *
 * Constraints:
 * - 1 <= rows, cols <= 100
 * - -100 <= matrix[i][j] <= 100
 *
 * Example:
 * Input:
 * 3 4
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
 *
 * Output:
 * Row with maximum sum: 2
 * Maximum sum: 42
 *
 * Explanation:
 * Row 0 sum: 1 + 2 + 3 + 4 = 10
 * Row 1 sum: 5 + 6 + 7 + 8 = 26
 * Row 2 sum: 9 + 10 + 11 + 12 = 42
 * Maximum sum is 42 at row index 2.
 *
 */

// Approach:
// Traverse the matrix row by row using nested loops.
// For each row, calculate the sum of all elements.
// Keep track of the maximum sum encountered and its row index.
// If multiple rows have the same maximum sum, the first one (smallest index) is kept.
//
// Complexity:
// - Time Complexity: O(rows * cols) - process every element once
// - Space Complexity: O(1) - only using a few variables

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findRowWithMaxSum(vector<vector<int>>& matrix, int rows, int cols) {
    int maxSum = INT_MIN;
    int maxRowIndex = 0;

    for (int i = 0; i < rows; i++) {
        int currentSum = 0;

        // Calculate sum of current row
        for (int j = 0; j < cols; j++) {
            currentSum += matrix[i][j];
        }

        // Update maximum if current row has higher sum
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxRowIndex = i;
        }
    }

    cout << "Row with maximum sum: " << maxRowIndex << endl;
    cout << "Maximum sum: " << maxSum << endl;
}

int main() {
    int rows, cols;
    cout << "Enter matrix dimensions (rows cols): ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix elements row by row:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    findRowWithMaxSum(matrix, rows, cols);

    return 0;
}