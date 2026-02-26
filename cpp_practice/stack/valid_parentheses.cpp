/*
 * Problem: Valid Parentheses
 *
 * Description:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 *
 * Input Format:
 * A single line containing the string s
 *
 * Output Format:
 * Print "true" if the string is valid, "false" otherwise
 *
 * Constraints:
 * - 1 <= s.length <= 10^4
 * - s consists of parentheses only: '()[]{}'
 *
 * Example 1:
 * Input:
 * ()
 *
 * Output:
 * true
 *
 * Example 2:
 * Input:
 * ()[]{}
 *
 * Output:
 * true
 *
 * Example 3:
 * Input:
 * (]
 *
 * Output:
 * false
 *
 * Example 4:
 * Input:
 * ([)]
 *
 * Output:
 * false
 *
 * Example 5:
 * Input:
 * {[]}
 *
 * Output:
 * true
 *
 */

// Approach:
// Use a stack to keep track of opening brackets.
// When we encounter a closing bracket, check if it matches the top of the stack.
// If it matches, pop the opening bracket. If not or stack is empty, return false.
// After processing all characters, the string is valid only if the stack is empty.
//
// Complexity:
// - Time Complexity: O(n) - single pass through the string
// - Space Complexity: O(n) - worst case, all opening brackets are pushed to stack

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> matching = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        // If it's a closing bracket
        if (matching.find(c) != matching.end()) {
            // Check if stack is empty or top doesn't match
            if (st.empty() || st.top() != matching[c]) {
                return false;
            }
            st.pop();
        } else {
            // It's an opening bracket, push to stack
            st.push(c);
        }
    }

    // Valid if stack is empty (all brackets matched)
    return st.empty();
}

int main() {
    string s;
    cout << "Enter brackets string: ";
    cin >> s;

    if (isValid(s)) {
        cout << "true" << endl;
        cout << "The brackets are properly matched!" << endl;
    } else {
        cout << "false" << endl;
        cout << "The brackets are NOT properly matched!" << endl;
    }

    return 0;
}