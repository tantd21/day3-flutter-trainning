#include <iostream>
#include <cmath>
using namespace std;
void quadratic(double a, double b, double c) {
    double delta = b*4 - 4*a*c;
        if(delta > 0){
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "x1: " << x1 << "x2: " << x2 << endl;
        }else if (delta = 0)
        {
            double x = -b/2*a;
        cout << "x: " << x << endl;
        }else {
        double x1 = -b / (2 * a);
        double x2 = sqrt(-delta) / (2 * a);
        cout << x1 << " + " << x2 << "i and " << x1 << " - " << x2 << "i" << endl;
        }   
        }
int main() {
    double a, b, c;
    cout << "Enter the (a, b, c): ";
    cin >> a >> b >> c;
    quadratic(a, b, c);
    return 0;
}
        



