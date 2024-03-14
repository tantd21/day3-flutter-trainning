#include <iostream>
#include <fstream>
using namespace std;

const int ARRAY_MAX = 50;

int main() {
    ifstream fileInput("C:/Users/thaid/Desktop/C++ Programming/test.txt");
    if (fileInput.fail()) {
        cout << "Failed to open this file" << endl;
        return -1;
    }

    int numbers[ARRAY_MAX];
    int i(0);

    while (!fileInput.eof()){
        fileInput >> numbers[i]; 
        i++;
    }
    int n = i;

    fileInput.close();
  
    cout << "Dãy số chẵn là: ";
    ofstream fileOut("C:/Users/thaid/Desktop/C++ Programming/test2.txt");
    if (fileOut.is_open()) {
        for (i = 0; i < n; i++) {
            if (numbers[i] % 2 == 0) {
                cout << numbers[i] << "   ";
                fileOut << numbers[i] << "   ";
            }
        }
        fileOut.close();
    } else {
        cout << "Không thể mở tệp tin để ghi." << endl;
    }
    cout << endl;

     }



