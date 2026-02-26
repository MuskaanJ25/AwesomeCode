/*
 * Problem: Student Average
 *
 * Description:
 * Given a list of students with their names and scores in multiple subjects,
 * calculate the average score for each student.
 * This problem demonstrates the use of structs to organize related data.
 *
 * Input Format:
 * First line: n (number of students)
 * For each student:
 *   - First line: name (string, single word)
 *   - Second line: m (number of subjects)
 *   - Third line: m space-separated integers (scores)
 *
 * Output Format:
 * For each student, print "Name: Average" on a separate line
 * Average should be printed with 2 decimal places
 *
 * Constraints:
 * - 1 <= n <= 100
 * - 1 <= m <= 10
 * - 0 <= score <= 100
 *
 * Example:
 * Input:
 * 3
 * Alice
 * 3
 * 85 90 78
 * Bob
 * 2
 * 75 80
 * Charlie
 * 4
 * 90 85 95 88
 *
 * Output:
 * Alice: 84.33
 * Bob: 77.50
 * Charlie: 89.50
 *
 * Explanation:
 * Alice's average: (85 + 90 + 78) / 3 = 84.33
 * Bob's average: (75 + 80) / 2 = 77.50
 * Charlie's average: (90 + 85 + 95 + 88) / 4 = 89.50
 *
 */

// Approach:
// Define a struct to store student information (name and scores).
// Read input data for each student and populate their struct.
// Calculate the average by summing all scores and dividing by the count.
// Print the result with formatted output.
//
// Complexity:
// - Time Complexity: O(n * m) - process n students, each with m scores
// - Space Complexity: O(n * m) - storing all student data

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Struct to represent a student
struct Student {
    string name;
    vector<int> scores;

    // Method to calculate average
    double getAverage() const {
        if (scores.empty()) return 0.0;
        int sum = 0;
        for (int score : scores) {
            sum += score;
        }
        return (double)sum / scores.size();
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    // Read data for each student
    for (int i = 0; i < n; i++) {
        cout << "Enter student name: ";
        cin >> students[i].name;

        int m;
        cout << "Enter number of subjects: ";
        cin >> m;

        students[i].scores.resize(m);
        cout << "Enter scores: ";
        for (int j = 0; j < m; j++) {
            cin >> students[i].scores[j];
        }
    }

    // Calculate and print average for each student
    cout << "\nResults:\n";
    for (const auto& student : students) {
        double avg = student.getAverage();
        cout << student.name << ": " << fixed << setprecision(2) << avg << endl;
    }

    return 0;
}