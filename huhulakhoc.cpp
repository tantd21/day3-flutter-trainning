#include <iostream>
#include <fstream>
using namespace std;

const int ARRAY_MAX = 50;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

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
  
    cout << "UCLN: ";
    ofstream fileOutUCLN("C:/Users/thaid/Desktop/C++ Programming/test2.txt");
    if (fileOutUCLN.is_open()) {
        int resultUCLN = numbers[0];
    for (i = 1; i < n; i++) {
        resultUCLN = gcd(resultUCLN, numbers[i]);
    }
                cout << resultUCLN << "   ";
                fileOutUCLN << resultUCLN << "   ";
            fileOutUCLN.close();
            }      
     else {
        cout << "Không thể mở tệp tin để ghi." << endl;
    }
    cout << "BCNN: ";
    ofstream fileOutBCNN("C:/Users/thaid/Desktop/C++ Programming/test3.txt");
    if ( fileOutBCNN.is_open()){
        int resultBCNN = numbers[0]; 
    for (i = 1; i<n; i++){
          resultBCNN = lcm(resultBCNN, numbers[i]);
    }
        cout << resultBCNN << "   ";
        fileOutBCNN << resultBCNN << "   ";
        fileOutBCNN.close();
    }
     else {
        cout << "Không thể mở tệp tin để ghi." << endl;
    }


     }



