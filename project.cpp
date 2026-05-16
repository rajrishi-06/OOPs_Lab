#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string questionText;
    vector<string> options;
    int correctOption;
};

void displayQuestion(const Question& q, int qNumber) {
    cout << "\nQuestion " << qNumber << ": " << q.questionText << endl;
    for (int i = 0; i < q.options.size(); ++i) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
}

int main() {
    vector<Question> quiz = {
        {
            "What is the capital of France?",
            {"Berlin", "London", "Paris", "Madrid"},
            3
        },
        {
            "Which language is used for Android app development?",
            {"Python", "Kotlin", "Swift", "C#"},
            2
        },
        {
            "What is 2 + 2?",
            {"3", "4", "5", "2"},
            2
        }
    };

    int score = 0;
    int userAnswer;

    cout << "==== Welcome to the Online Quiz System ====\n";

    for (int i = 0; i < quiz.size(); ++i) {
        displayQuestion(quiz[i], i + 1);
        cout << "Your answer (1-4): ";
        cin >> userAnswer;

        if (userAnswer == quiz[i].correctOption) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! Correct answer was: " << quiz[i].correctOption << ". " << quiz[i].options[quiz[i].correctOption - 1] << "\n";
        }
    }

    cout << "\n==== Quiz Finished ====\n";
    cout << "Your Score: " << score << "/" << quiz.size() << endl;

    if (score == quiz.size()) {
        cout << "Excellent! 🏆\n";
    } else if (score >= quiz.size() / 2) {
        cout << "Good Job! 👍\n";
    } else {
        cout << "Better luck next time. 💡\n";
    }

    return 0;
}