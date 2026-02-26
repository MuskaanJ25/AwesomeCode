/*
 * Problem: Top K Frequent Elements
 *
 * Description:
 * Given an integer array nums and an integer k, return the k most frequent elements.
 * You may return the answer in any order.
 *
 * Input Format:
 * First line: n (size of array)
 * Second line: n space-separated integers
 * Third line: k (number of most frequent elements to return)
 *
 * Output Format:
 * Print k space-separated integers representing the most frequent elements
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 * - k is in the range [1, number of unique elements in the array]
 * - It is guaranteed that the answer is unique
 *
 * Example:
 * Input:
 * 6
 * 1 1 1 2 2 3
 * 2
 *
 * Output:
 * 1 2
 *
 * Explanation:
 * Element 1 appears 3 times, element 2 appears 2 times, element 3 appears 1 time.
 * The 2 most frequent elements are [1, 2].
 *
 */

// Approach:
// 1. Count frequency of each element using a hash map
// 2. Use a min-heap (priority queue) of size k to keep track of the k most frequent elements
// 3. For each element in the frequency map:
//    - If heap has less than k elements, add the element
//    - Otherwise, if current element's frequency is greater than the minimum in heap, replace it
// Alternatively, bucket sort may be used when frequencies are bounded
// 4. Extract elements from the heap
//
// Complexity:
// - Time Complexity: O(n log k) - n elements, heap operations of log k
// - Space Complexity: O(n) - for the frequency map and heap

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Count frequency of each element
    unordered_map<int, int> freq_map;
    for (int num : nums) {
        freq_map[num]++;
    }

    // Min-heap based on frequency (pair: frequency, element)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    for (auto& [num, freq] : freq_map) {
        if (min_heap.size() < k) {
            min_heap.push({freq, num});
        } else if (freq > min_heap.top().first) {
            min_heap.pop();
            min_heap.push({freq, num});
        }
    }

    // Extract elements from heap
    vector<int> result;
    while (!min_heap.empty()) {
        result.push_back(min_heap.top().second);
        min_heap.pop();
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

    int k;
    cout << "Enter k (number of most frequent elements): ";
    cin >> k;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}