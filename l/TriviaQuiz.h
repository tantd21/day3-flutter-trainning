#ifndef TRIVIAQUIZ_H
#define TRIVIAQUIZ_H

#include <iostream>
#include <string>

using namespace std;

class TriviaQuiz {
private:
    string question;
    string answer1;
    string answer2;
    string answer3;
    string answer4;
    int correctAnswer;

public:
    TriviaQuiz(const string& q, const string& a1, const string& a2, const string& a3, const string& a4, int correct) : 
        question(q), answer1(a1), answer2(a2), answer3(a3), answer4(a4), correctAnswer(correct) {}

    void display() const {
        cout << "Question: " << question << endl;
        cout << "1. " << answer1 << endl;
        cout << "2. " << answer2 << endl;
        cout << "3. " << answer3 << endl;
        cout << "4. " << answer4 << endl;
    }

    int getCorrectAnswer() const {
        return correctAnswer;
    }
};

#endif
