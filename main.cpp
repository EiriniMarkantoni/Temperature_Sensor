#include <iostream>
#include "TSensor.h"
using namespace std;

/*
    Κύριο πρόγραμμα

    Δημιουργεί 3 αισθητήρες και εκτελεί:
    - εκτύπωση δεδομένων
    - εύρεση max θερμοκρασίας
    - έλεγχο σωστής λειτουργίας αισθητήρων
    - σύγκριση μέσου όρου
*/

int main() {

    // Αισθητήρας 1 (constructor)
    TSensor s1(1, 22.5, 23.0, 22.8, 23.1, 22.9);

    // Αισθητήρας 2 (setData)
    TSensor s2;
    s2.setData(2, 22.5, 23.0, 22.8, 23.1, 22.9);

    // Αισθητήρας 3 (input)
    TSensor s3;
    cout << "Enter data for sensor 3:\n";
    cin >> s3;

    // Εκτύπωση δεδομένων
    cout << "\nSensor 1:\n";
    s1.printData();

    cout << "\nSensor 2:\n";
    s2.printData();

    cout << "\nSensor 3:\n";
    cout << s3;

    // Μέγιστες θερμοκρασίες
    cout << "\nMax temperatures:\n";
    cout << "S1: " << s1.maxTemp() << endl;
    cout << "S2: " << s2.maxTemp() << endl;
    cout << "S3: " << s3.maxTemp() << endl;

    // Έλεγχος αν οι δύο πρώτοι αισθητήρες είναι ίδιοι
    cout << "\nChecking sensors 1 and 2...\n";

    if (s1.hasSameMeasurements(s2)) {
        cout << "Sensors are working correctly.\n";
    } else {
        cout << "Error: Sensors differ!\n";
    }

    // Σύγκριση μέσου όρου
    cout << "\nComparing average temperature:\n";

    if (s1 > s2) {
        cout << "Sensor 1 has higher average:\n";
        s1.printData();
    } else {
        cout << "Sensor 2 has higher (or equal) average:\n";
        s2.printData();
    }

    return 0;
}
