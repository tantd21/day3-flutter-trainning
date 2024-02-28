#include <iostream>
#include <fstream>
using namespace std;
 int main() {
    ifstream fileInput("C:/Users/thaid/Desktop/C++ Programming/docphai.txt");
    if (fileInput.fail()) {
        cout << "Failed to open this file" << endl;
        return -1;
    }

    while (!fileInput.eof())
    {
        char temp[255];
        fileInput.getline(temp, 255);
        string line = temp;
        cout << line << endl;
    }
 }
    