#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 int main() {
    ifstream fileInput("C:/Users/thaid/Desktop/C++ Programming/docphai.txt");
    vector<string> values;
    string temp;
    while(getline(fileInput, temp, ",")){
        values.push_back(temp);
    }
    for(const auto &line : values)
    cout << line << endl;
    fileInput.close();
 }