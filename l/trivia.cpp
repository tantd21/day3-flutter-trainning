#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TriviaQuizz {
    string question;
    string answer1;
    string answer2;
    string answer3;
    string answer4;
    int correctanswer;

public:
TriviaQuizz() {
    question = " ";
    answer1 = " ";
    answer2 = " ";
    answer3 = " ";
    answer4 = " ";
    correctanswer = 0;
}
TriviaQuizz(string ques, string ans1,string ans2,string ans3,string ans4, int correct) {
    question = ques;
    answer1 = ans1;
    answer2 = ans2;
    answer3 = ans3;
    answer4 = ans4;
    correctanswer = correct;
}
string getquestion() const {
    return question;
}
string getanswer1() const {
    return answer1;
}
string getanswer2() const {
    return answer2;
}
string getanswer3() const {
    return answer3;
}
string getanswer4() const {
    return answer4;
}
int getcorrectanswer() const {
    return correctanswer;
}
};
int main() {
    vector<TriviaQuizz> trivias = {
        TriviaQuizz("Who Ask Who Care?", "HDNguyen", "HoDangNguyen", "HDNguyenDEV", "NguyenDamSau", 1),
         TriviaQuizz("DMM, May O Dau ???", "Gio Linh", "KTX", "O Trong Tim", "On cai Lo", 1),
          TriviaQuizz("Thi`?", "Thi` Tho^i-Reddy", "Thi` Thi cai cuc cut", "Thi` anh xin noi voi em mot cau", "Cam nin", 1),
           TriviaQuizz("Tuong tu cua ban la gi?", "Chua te bong toi", "Zed", "Vahellxin", "Khong co con tuong yeu chi co nguoi choi toi", 1),
           
        // Add other trivia questions here
    };
    int score = 0;
     for (size_t i = 0; i < trivias.size(); ++i) {
        // Display the question and possible answers
        cout << "Question " << i + 1 << ": " << trivias[i].getquestion() << endl;
        cout << "1. " << trivias[i].getanswer1() << endl;
        cout << "2. " << trivias[i].getanswer2() << endl;
        cout << "3. " << trivias[i].getanswer3() << endl;
        cout << "4. " << trivias[i].getanswer4() << endl;

        // Ask the player for their answer
        int playerAnswer;
        cout << "Enter your answer (1-4): ";
        cin >> playerAnswer;

        // Check if the player's answer is correct
        if (playerAnswer == trivias[i].getcorrectanswer()) {
            cout << "Correct!" << endl;
            score++; // Increase the player's score by 1
        } else {
            cout << "Incorrect!" << endl;
        }

        // Clear input buffer
        cin.ignore();
    }

    // Display the player's final score
    cout << "Your score: " << score << endl;

    return 0;
}

