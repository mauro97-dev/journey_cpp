#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    int total_students = 0;
    int sum_scores = 0;     // test scores: 10 7 7 6 10
    double average_score = 0.0;
    double max_score = 0.0;
    double min_score = 0.0;

    cout << "==========================================================\n";
    cout << "This small script is a practical example of the vector container.\n";
    cout << "Enter the total number of students\n";
    cin >> total_students;

    // The container class template vector.
    // Is the most appropriate container for a sequence when random access.
    vector<int> scores(total_students);

    if (total_students > 0 ) {
        cout << "Enter the score for each student:\n";
        for (int i = 0; i < total_students; i++) {
            cin >> scores[i];
        }

        for (int i = 0; i < total_students; i++) {
            sum_scores += scores[i];
        }

        average_score = (double)sum_scores / total_students;

        // This corrects the type error when the average score is entered as a value between 0 and 10.
        if (average_score <= 10.0) {
            average_score *= 10.0; 
        }

    cout << "\n==========================================================\n";   
    if (average_score > 0.0) {
        if (average_score < 60.00) {
            cout << "The total score is low: " << average_score << "\n";
        } else if (average_score < 70.00) {
            cout << "The total score is regular: " << average_score << "\n";
        } else if (average_score < 80.00) {
            cout << "The total score is good: " << average_score << "\n";
        } else if (average_score < 90.00) {
            cout << "The total score is excellent: " << average_score << "\n";
        } else {
            cout << "The total score is outstanding: " << average_score << "\n";
        }
    }

    // Show max and min scores.
    max_score = scores[0];
    min_score = scores[0];

    for (int i = 1; i < total_students; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
        if (scores[i] < min_score) {
            min_score = scores[i];
        }
    }

    cout << "The maximum score is: " << max_score << "\n";
    cout << "The minimum score is: " << min_score << "\n";

    } else {
        cout << "Error. The number of students must be greater than 0.\n";
    }

    cout << "==========================================================\n";
    return 0;
}