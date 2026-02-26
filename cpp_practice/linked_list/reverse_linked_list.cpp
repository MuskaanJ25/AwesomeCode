/*
 * Problem: Reverse Linked List
 *
 * Description:
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 *
 * Input Format:
 * First line: n (number of nodes)
 * Second line: n space-separated integers (values of nodes)
 *
 * Output Format:
 * Print the reversed linked list (space-separated values)
 *
 * Constraints:
 * - The number of nodes in the list is in the range [0, 5000]
 * - -5000 <= Node.val <= 5000
 *
 * Example:
 * Input:
 * 5
 * 1 2 3 4 5
 *
 * Output:
 * 5 4 3 2 1
 *
 * Explanation:
 * Original list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 * Reversed list: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
 *
 */

// Approach:
// Use three pointers: prev, current, and next.
// Initialize prev to NULL and current to head.
// For each node:
// 1. Store the next node
// 2. Reverse the link by pointing current->next to prev
// 3. Move prev and current one step forward
// At the end, prev will be the new head of the reversed list.
//
// Complexity:
// - Time Complexity: O(n) - single pass through the list
// - Space Complexity: O(1) - only using three pointers

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next;

    while (curr != NULL) {
        next = curr->next;  // Store next node
        curr->next = prev;  // Reverse the link
        prev = curr;        // Move prev forward
        curr = next;        // Move current forward
    }

    return prev;  // prev is the new head
}

// Helper function to create a linked list from vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return NULL;

    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;

    for (size_t i = 1; i < values.size(); i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }

    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val;
        if (curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << "-> NULL" << endl;
}

// Helper function to delete the linked list (memory cleanup)
void deleteList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    ListNode* reversed = reverseList(head);

    cout << "Reversed list: ";
    printList(reversed);

    // Clean up memory
    deleteList(reversed);

    return 0;
}