/*
 * Problem: Binary Search
 *
 * Description:
 * Given an array of integers nums which is sorted in ascending order, and an integer target,
 * write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Input Format:
 * First line: n (size of array)
 * Second line: n space-separated integers (sorted in ascending order)
 * Third line: target integer
 *
 * Output Format:
 * Print the index of target if found, otherwise print -1
 *
 * Constraints:
 * - 1 <= nums.length <= 10^4
 * - -10^4 < nums[i], target < 10^4
 * - All the integers in nums are unique
 * - nums is sorted in ascending order
 *
 * Example 1:
 * Input:
 * 6
 * -1 0 3 5 9 12
 * 9
 *
 * Output:
 * 4
 *
 * Explanation:
 * 9 exists in nums and its index is 4.
 *
 * Example 2:
 * Input:
 * 6
 * -1 0 3 5 9 12
 * 2
 *
 * Output:
 * -1
 *
 * Explanation:
 * 2 does not exist in nums so return -1.
 *
 */

// Approach:
// Classic binary search algorithm:
// 1. Use two pointers: left (start) and right (end)
// 2. While left <= right:
//    a. Calculate mid point
//    b. If nums[mid] == target, return mid
//    c. If target < nums[mid], search left half (right = mid - 1)
//    d. If target > nums[mid], search right half (left = mid + 1)
// 3. If loop ends without finding target, return -1
//
// Complexity:
// - Time Complexity: O(log n) - halves the search space each iteration
// - Space Complexity: O(1) - only using a few variables

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        // Prevent integer overflow
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;  // Target not found
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    int index = binarySearch(nums, target);

    if (index != -1) {
        cout << "Target " << target << " found at index: " << index << endl;
    } else {
        cout << "Target " << target << " not found in the array!" << endl;
    }

    return 0;
}