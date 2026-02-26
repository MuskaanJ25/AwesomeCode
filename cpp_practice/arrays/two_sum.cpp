/*
 * Problem: Two Sum
 *
 * Description:
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Input Format:
 * First line: n (size of array)
 * Second line: n space-separated integers (array elements)
 * Third line: target integer
 *
 * Output Format:
 * Print two space-separated indices (0-based) representing the two numbers that add up to target
 *
 * Constraints:
 * - 2 <= nums.length <= 10^4
 * - -10^9 <= nums[i] <= 10^9
 * - -10^9 <= target <= 10^9
 * - Only one valid answer exists
 *
 * Example:
 * Input:
 * 4
 * 2 7 11 15
 * 9
 *
 * Output:
 * 0 1
 *
 * Explanation:
 * Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 */

// Approach:
// Use nested loops to check all possible pairs of elements.
// For each element at index i, check all elements at indices j > i.
// If nums[i] + nums[j] equals target, return the indices.
// This is a straightforward brute force approach without using any complex data structures.
//
// Complexity:
// - Time Complexity: O(n²) - nested loops through the array
// - Space Complexity: O(1) - only using a few variables, no extra data structures

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;

    // Nested loops: check all pairs (i, j) where j > i
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]]
             << " = " << nums[result[0]] + nums[result[1]] << " (target: " << target << ")" << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}