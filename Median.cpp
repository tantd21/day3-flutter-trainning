#include <iostream>

using namespace std;

double calculateMedian(int* array, int size) {
    if (size == 0) {
        cerr << "Error: Empty array\n";
        return 0.0;
    }
    int middleIndex = size / 2;
    if (size % 2 == 0) {
        double median = static_cast<double>(array[middleIndex - 1] + array[middleIndex]) / 2.0;
        return median;
    } else {
        return static_cast<double>(array[middleIndex]);
    }
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* dynamicArray = new int[size];
    cout << "Enter " << size << " elements of the array in ascending order: ";
    for (int i = 0; i < size; ++i) {
        cin >> dynamicArray[i];
    }
    double median = calculateMedian(dynamicArray, size);
    cout << "Median: " << median << endl;
    delete[] dynamicArray;
    return 0;
}
