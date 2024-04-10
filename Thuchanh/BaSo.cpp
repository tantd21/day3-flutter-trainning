#include <iostream>
#include <stdexcept>

using namespace std;

// Function template tính tổng của ba số kiểu T (int hoặc float)
template<typename T>
T sumOfThree(T a, T b, T c) {
    return a + b + c;
}

// Hàm đệ quy tính tổng các số từ 1 đến n
int sumFrom1ToN(int n) {
    if (n < 0) {
        throw invalid_argument("n must be a positive integer.");
    }
    if (n == 0) {
        return 0;
    } else {
        return n + sumFrom1ToN(n - 1);
    }
}

int main() {
    // Sử dụng function template tính tổng của ba số
    int sum1 = sumOfThree(1, 2, 3);
    cout << "Sum of 1 + 2 + 3 = " << sum1 << endl;

    float sum2 = sumOfThree(1.5f, 2.5f, 3.5f);
    cout << "Sum of 1.5 + 2.5 + 3.5 = " << sum2 << endl;

    // Sử dụng hàm đệ quy tính tổng các số từ 1 đến n
    try {
        int n;
        cout << "Enter a positive integer n: ";
        cin >> n;

        int result = sumFrom1ToN(n);
        cout << "Sum from 1 to " << n << " = " << result << endl;

    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
