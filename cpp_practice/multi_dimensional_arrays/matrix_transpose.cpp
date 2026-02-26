/*
 * Problem: Matrix Transpose
 *
 * Description:
 * Given a 2D matrix, compute its transpose.
 * The transpose of a matrix is obtained by swapping rows with columns.
 * Element at position (i, j) in original becomes (j, i) in transposed matrix.
 *
 * Input Format:
 * First line: rows cols (dimensions of matrix)
 * Next rows lines: cols space-separated integers per row
 *
 * Output Format:
 * Print the transposed matrix (rows become columns)
 *
 * Constraints:
 * - 1 <= rows, cols <= 100
 * - -100 <= matrix[i][j] <= 100
 *
 * Example:
 * Input:
 * 2 3
 * 1 2 3
 * 4 5 6
 *
 * Output:
 * Transposed matrix:
 * 1 4
 * 2 5
 * 3 6
 *
 * Explanation:
 * Original matrix (2x3):
 * [1, 2, 3]
 * [4, 5, 6]
 *
 * Transposed matrix (3x2):
 * [1, 4]
 * [2, 5]
 * [3, 6]
 *
 */

// Approach:
// Create a new matrix with swapped dimensions (cols x rows).
// Use nested loops to copy elements:
// - For each element at (i, j) in original, place it at (j, i) in transposed.
// Print the resulting matrix.
//
// Complexity:
// - Time Complexity: O(rows * cols) - process every element once
// - Space Complexity: O(rows * cols) - create a new matrix

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    // Create transposed matrix with swapped dimensions
    vector<vector<int>> transposed(cols, vector<int>(rows));

    // Fill transposed matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) cout << " ";
        }
        cout << endl;
    }
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

    vector<vector<int>> transposed = transposeMatrix(matrix, rows, cols);

    cout << "\nTransposed matrix:\n";
    printMatrix(transposed);

    return 0;
}