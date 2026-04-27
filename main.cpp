#include <iostream>
#include "TSensor.h"

using namespace std;

void printBiggerAverageSensor(const TSensor& s1, const TSensor& s2) {
    if (s1.avgTemp() == s2.avgTemp()) {
        cout << "Both sensors have the same average temperature." << endl;
    } else if (s1 > s2) {
        cout << "Sensor 1 has the greater average temperature:" << endl;
        s1.printData();
    } else {
        cout << "Sensor 2 has the greater average temperature:" << endl;
        s2.printData();
    }
}

int main() {
    cout << "==================================" << endl;
    cout << " Temperature Sensor Monitoring App " << endl;
    cout << "==================================" << endl;

    TSensor sensor1(101, 22.5, 23.0, 22.8, 23.1, 22.9);

    TSensor sensor2;
    sensor2.setData(102, 22.5, 23.0, 22.8, 23.1, 22.9);

    TSensor sensor3;

    cout << endl << "Enter data for the third sensor:" << endl;
    cin >> sensor3;

    cout << endl << "Sensor 1 data:" << endl;
    sensor1.printData();

    cout << "Sensor 2 data:" << endl;
    sensor2.printData();

    cout << "Sensor 3 data:" << endl;
    cout << sensor3;

    cout << endl;
    cout << "Maximum temperature recorded by each sensor:" << endl;
    cout << "Sensor 1: " << sensor1.maxTemp() << "°C" << endl;
    cout << "Sensor 2: " << sensor2.maxTemp() << "°C" << endl;
    cout << "Sensor 3: " << sensor3.maxTemp() << "°C" << endl;

    cout << endl;
    cout << "System reliability check for Sensor 1 and Sensor 2:" << endl;

    if (sensor1.hasSameMeasurements(sensor2)) {
        cout << "Status: OK - The two sensors have identical measurements." << endl;
    } else {
        cout << "Status: ERROR - Problem detected! The two sensors have different measurements." << endl;
    }

    cout << endl;
    cout << "Average temperature comparison between Sensor 1 and Sensor 2:" << endl;

    cout << endl << "Using member function:" << endl;
    printBiggerAverageSensor(sensor1, sensor2);

    cout << endl << "Using friend function:" << endl;
    if (friendGreaterAverage(sensor1, sensor2)) {
        sensor1.printData();
    } else if (friendGreaterAverage(sensor2, sensor1)) {
        sensor2.printData();
    } else {
        cout << "Both sensors have the same average temperature." << endl;
    }

    cout << endl << "Using global function:" << endl;
    if (globalGreaterAverage(sensor1, sensor2)) {
        sensor1.printData();
    } else if (globalGreaterAverage(sensor2, sensor1)) {
        sensor2.printData();
    } else {
        cout << "Both sensors have the same average temperature." << endl;
    }

    cout << endl << "Using overloaded > operator:" << endl;
    printBiggerAverageSensor(sensor1, sensor2);

    return 0;
}
