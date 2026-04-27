#include "TSensor.h"
#include <iomanip>

TSensor::TSensor() {
    sid = 0;
    for (int i = 0; i < 5; i++) {
        measurements[i] = 0;
    }
}

TSensor::TSensor(int id, float m1, float m2, float m3, float m4, float m5) {
    setData(id, m1, m2, m3, m4, m5);
}

void TSensor::setData(int id, float m1, float m2, float m3, float m4, float m5) {
    sid = id;
    measurements[0] = m1;
    measurements[1] = m2;
    measurements[2] = m3;
    measurements[3] = m4;
    measurements[4] = m5;
}

void TSensor::readData() {
    cin >> *this;
}

float TSensor::avgTemp() const {
    float sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += measurements[i];
    }

    return sum / 5;
}

float TSensor::maxTemp() const {
    float max = measurements[0];

    for (int i = 1; i < 5; i++) {
        if (measurements[i] > max) {
            max = measurements[i];
        }
    }

    return max;
}

float TSensor::minTemp() const {
    float min = measurements[0];

    for (int i = 1; i < 5; i++) {
        if (measurements[i] < min) {
            min = measurements[i];
        }
    }

    return min;
}

void TSensor::printData() const {
    cout << *this;
}

bool TSensor::hasSameMeasurements(const TSensor& sensor) const {
    for (int i = 0; i < 5; i++) {
        if (measurements[i] != sensor.measurements[i]) {
            return false;
        }
    }

    return true;
}

bool TSensor::hasGreaterAverageThan(const TSensor& sensor) const {
    return avgTemp() > sensor.avgTemp();
}

bool friendGreaterAverage(const TSensor& s1, const TSensor& s2) {
    return s1.avgTemp() > s2.avgTemp();
}

bool globalGreaterAverage(const TSensor& s1, const TSensor& s2) {
    return s1.avgTemp() > s2.avgTemp();
}

istream& operator>>(istream& in, TSensor& sensor) {
    do {
        cout << "Enter sensor ID (positive integer): ";
        in >> sensor.sid;

        if (sensor.sid <= 0) {
            cout << "Invalid ID. Please try again." << endl;
        }

    } while (sensor.sid <= 0);

    cout << "Enter 5 temperature measurements (-50 to 100 Celsius):" << endl;

    for (int i = 0; i < 5; i++) {
        do {
            cout << "Measurement " << i + 1 << ": ";
            in >> sensor.measurements[i];

            if (sensor.measurements[i] < -50 || sensor.measurements[i] > 100) {
                cout << "Invalid temperature. Please enter a value between -50 and 100." << endl;
            }

        } while (sensor.measurements[i] < -50 || sensor.measurements[i] > 100);
    }

    return in;
}

ostream& operator<<(ostream& out, const TSensor& sensor) {
    out << fixed << setprecision(2);

    out << "----------------------------------" << endl;
    out << "Sensor ID: " << sensor.sid << endl;
    out << "Measurements: ";

    for (int i = 0; i < 5; i++) {
        out << sensor.measurements[i] << "°C";
        if (i < 4) {
            out << ", ";
        }
    }

    out << endl;
    out << "Average temperature: " << sensor.avgTemp() << "°C" << endl;
    out << "Maximum temperature: " << sensor.maxTemp() << "°C" << endl;
    out << "Minimum temperature: " << sensor.minTemp() << "°C" << endl;
    out << "----------------------------------" << endl;

    return out;
}

bool operator>(const TSensor& s1, const TSensor& s2) {
    return s1.avgTemp() > s2.avgTemp();
}
