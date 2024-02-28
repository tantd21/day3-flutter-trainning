#include <iostream>
#include <string>
using namespace std;
int main() {
    double speed, time;
    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;
    cout << "How many hours has it traveled? ";
    cin >> time;
    cout << "\nHour Distance Traveled\n";
    cout << "--------------------------------\n";


    for (int hour = 1; hour <= time; ++hour) {
        double distance = speed * hour;
        cout << hour << "\t\t" << distance << "\n";
    }

    return 0;
}
