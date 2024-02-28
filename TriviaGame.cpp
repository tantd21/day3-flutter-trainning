#include <iostream>
#include <vector>
#include <string>
#include "AnswerProcessor.h" // Include file containing processAnswers function
#include "TriviaQuiz.h" // Include file containing TriviaQuiz class

using namespace std;

int main() {
    // Create trivia questions
    vector<TriviaQuiz> trivias = {
        TriviaQuiz("What is the capital of France?", "Paris", "Berlin", "London", "Rome", 1),
        TriviaQuiz("Who wrote 'Romeo and Juliet'?", "William Shakespeare", "Charles Dickens", "Jane Austen", "Leo Tolstoy", 1),
        TriviaQuiz("Which planet is known as the Red Planet?", "Mars", "Venus", "Jupiter", "Saturn", 1),
        TriviaQuiz("What is the largest mammal in the world?", "Blue Whale", "Elephant", "Giraffe", "Hippo", 1),
        TriviaQuiz("Who painted the Mona Lisa?", "Leonardo da Vinci", "Pablo Picasso", "Vincent van Gogh", "Michelangelo", 1),
        TriviaQuiz("What is the chemical symbol for water?", "H2O", "CO2", "NaCl", "O2", 1),
        TriviaQuiz("What is the tallest mountain in the world?", "Mount Everest", "K2", "Kangchenjunga", "Lhotse", 1),
        TriviaQuiz("What is the main ingredient in guacamole?", "Avocado", "Tomato", "Onion", "Lemon", 1),
        TriviaQuiz("Who was the first man to walk on the moon?", "Neil Armstrong", "Buzz Aldrin", "Yuri Gagarin", "Alan Shepard", 1),
        TriviaQuiz("Which country is famous for the tulip festival?", "Netherlands", "Japan", "France", "Italy", 1)
    };

    int score = processAnswers(trivias); // Process answers and calculate score

    // Display the player's final score
    cout << "Your score: " << score << "/" << trivias.size() << endl;

    return 0;
}
