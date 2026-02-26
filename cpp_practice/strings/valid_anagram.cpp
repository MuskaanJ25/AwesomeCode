/*
 * Problem: Valid Anagram
 *
 * Description:
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 * typically using all the original letters exactly once.
 *
 * Input Format:
 * First line: string s
 * Second line: string t
 *
 * Output Format:
 * Print "true" if t is an anagram of s, "false" otherwise
 *
 * Constraints:
 * - 1 <= s.length, t.length <= 5 * 10^4
 * - s and t consist of lowercase English letters
 *
 * Example 1:
 * Input:
 * anagram
 * nagaram
 *
 * Output:
 * true
 *
 * Explanation:
 * Both strings contain the same letters 'a', 'n', 'a', 'g', 'r', 'a', 'm' in different order.
 *
 * Example 2:
 * Input:
 * rat
 * car
 *
 * Output:
 * false
 *
 * Explanation:
 * 'rat' does not have the same letters as 'car'.
 *
 */

// Approach:
// Count the frequency of each character in both strings using an array of size 26 (for lowercase letters).
// Alternatively, use hash maps for better flexibility.
// If both strings have identical character frequencies, they are anagrams.
//
// Complexity:
// - Time Complexity: O(n) - where n is the length of the string
// - Space Complexity: O(1) - fixed size array of 26 characters
// Alternative (hash map): O(n) space for all ASCII characters

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> char_count;

    // Increment count for characters in s
    for (char c : s) {
        char_count[c]++;
    }

    // Decrement count for characters in t
    for (char c : t) {
        char_count[c]--;
        if (char_count[c] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t)) {
        cout << "true" << endl;
        cout << "\"" << s << "\" and \"" << t << "\" are anagrams!" << endl;
    } else {
        cout << "false" << endl;
        cout << "\"" << s << "\" and \"" << t << "\" are NOT anagrams!" << endl;
    }

    return 0;
}