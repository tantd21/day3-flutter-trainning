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
    for ( i = 0; i < n; i++)
        cout << numbers[i] << "   ";

    int max = numbers[0];
    for (i = 1; i<n; i++)
        if (max < numbers[i])
            max = numbers[i];
        cout << endl << "So lon nhat: " << max << endl;

        ofstream fileOut ("C:/Users/thaid/Desktop/C++ Programming/test2.txt");
        fileOut << max << endl;
        fileOut.close();
        

    

}
