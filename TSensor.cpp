#include "TSensor.h"
#include <iomanip>

/*
    Constructor χωρίς ορίσματα
    Αρχικοποιεί τον αισθητήρα με τιμές 0
*/
TSensor::TSensor() {
    sid = 0;

    for (int i = 0; i < 5; i++) {
        measurements[i] = 0;
    }
}

/*
    Constructor με ορίσματα
*/
TSensor::TSensor(int id, float m1, float m2, float m3, float m4, float m5) {
    setData(id, m1, m2, m3, m4, m5);
}

/*
    Ανάθεση τιμών στον αισθητήρα
*/
void TSensor::setData(int id, float m1, float m2, float m3, float m4, float m5) {
    sid = id;

    measurements[0] = m1;
    measurements[1] = m2;
    measurements[2] = m3;
    measurements[3] = m4;
    measurements[4] = m5;
}

/*
    Διαβάζει δεδομένα από το πληκτρολόγιο
*/
void TSensor::readData() {
    cin >> *this;
}

/*
    Υπολογισμός μέσου όρου θερμοκρασίας
*/
float TSensor::avgTemp() const {
    float sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += measurements[i];
    }

    return sum / 5;
}

/*
    Εύρεση μέγιστης θερμοκρασίας
*/
float TSensor::maxTemp() const {
    float max = measurements[0];

    for (int i = 1; i < 5; i++) {
        if (measurements[i] > max) {
            max = measurements[i];
        }
    }

    return max;
}

/*
    Εύρεση ελάχιστης θερμοκρασίας
*/
float TSensor::minTemp() const {
    float min = measurements[0];

    for (int i = 1; i < 5; i++) {
        if (measurements[i] < min) {
            min = measurements[i];
        }
    }

    return min;
}

/*
    Εκτύπωση δεδομένων αισθητήρα
*/
void TSensor::printData() const {
    cout << *this;
}

/*
    Member σύγκριση μέσου όρου
*/
bool TSensor::hasGreaterAverageThan(const TSensor& sensor) const {
    return avgTemp() > sensor.avgTemp();
}

/*
    Έλεγχος αν δύο αισθητήρες έχουν ίδιες μετρήσεις
*/
bool TSensor::hasSameMeasurements(const TSensor& sensor) const {
    for (int i = 0; i < 5; i++) {
        if (measurements[i] != sensor.measurements[i]) {
            return false;
        }
    }
    return true;
}

/*
    Friend συνάρτηση σύγκρισης
*/
bool friendGreaterAverage(const TSensor& s1, const TSensor& s2) {
    return s1.avgTemp() > s2.avgTemp();
}

/*
    Global συνάρτηση σύγκρισης
*/
bool globalGreaterAverage(const TSensor& s1, const TSensor& s2) {
    return s1.avgTemp() > s2.avgTemp();
}

/*
    Υπερφόρτωση >> (είσοδος)
*/
istream& operator>>(istream& in, TSensor& sensor) {
    cout << "Enter sensor ID: ";
    in >> sensor.sid;

    cout << "Enter 5 temperatures:\n";

    for (int i = 0; i < 5; i++) {
        cout << "Measurement " << i + 1 << ": ";
        in >> sensor.measurements[i];
    }

    return in;
}

/*
    Υπερφόρτωση << (εκτύπωση)
*/
ostream& operator<<(ostream& out, const TSensor& sensor) {
    out << fixed << setprecision(2);

    out << "Sensor ID: " << sensor.sid << endl;

    for (int i = 0; i < 5; i++) {
        out << "Measurement " << i + 1 << ": "
            << sensor.measurements[i] << endl;
    }

    out << "Average: " << sensor.avgTemp() << endl;
    out << "Max: " << sensor.maxTemp() << endl;
    out << "Min: " << sensor.minTemp() << endl;

    return out;
}

/*
    Υπερφόρτωση τελεστή >
*/
bool operator>(const TSensor& s1, const TSensor& s2) {
    return s1.avgTemp() > s2.avgTemp();
}
