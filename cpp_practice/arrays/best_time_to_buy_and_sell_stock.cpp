/*
 * Problem: Best Time to Buy and Sell Stock
 *
 * Description:
 * You are given an array prices where prices[i] is the price of a given stock on the i-th day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 *
 * Input Format:
 * First line: n (number of days)
 * Second line: n space-separated integers (stock prices for each day)
 *
 * Output Format:
 * Print the maximum profit achievable
 *
 * Constraints:
 * - 1 <= prices.length <= 10^5
 * - 0 <= prices[i] <= 10^4
 *
 * Example:
 * Input:
 * 6
 * 7 1 5 3 6 4
 *
 * Output:
 * 5
 *
 * Explanation:
 * Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 *
 */

// Approach:
// Track the minimum price seen so far as we iterate through the array.
// For each day, calculate the potential profit if we bought at the minimum price seen so far and sold today.
// Keep track of the maximum profit.
//
// Complexity:
// - Time Complexity: O(n) - single pass through the array
// - Space Complexity: O(1) - only using a few variables

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < prices.size(); i++) {
        // Update minimum price seen so far
        min_price = min(min_price, prices[i]);
        // Calculate profit if we sell at current price
        max_profit = max(max_profit, prices[i] - min_price);
    }

    return max_profit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int profit = maxProfit(prices);

    cout << "Maximum Profit: " << profit << endl;

    return 0;
}