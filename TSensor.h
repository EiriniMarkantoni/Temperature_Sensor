#ifndef TSENSOR_H
#define TSENSOR_H

#include <iostream>
using namespace std;

/*
    Η κλάση TSensor αναπαριστά έναν αισθητήρα θερμοκρασίας

    Κάθε αισθητήρας έχει:
    - έναν κωδικό (sid)
    - έναν πίνακα με 5 μετρήσεις θερμοκρασίας
*/

class TSensor {
private:
    int sid;                 // Κωδικός αισθητήρα
    float measurements[5];   // Πίνακας με 5 θερμοκρασίες

public:

    // Constructor χωρίς ορίσματα (αρχικοποιεί τιμές σε 0)
    TSensor();

    // Constructor με ορίσματα για αρχικοποίηση δεδομένων
    TSensor(int id, float m1, float m2, float m3, float m4, float m5);

    // Συνάρτηση για ανάθεση τιμών στον αισθητήρα
    void setData(int id, float m1, float m2, float m3, float m4, float m5);

    // Διαβάζει δεδομένα από το πληκτρολόγιο
    void readData();

    // Εκτυπώνει τα δεδομένα του αισθητήρα
    void printData() const;

    // Υπολογισμός μέσου όρου θερμοκρασίας
    float avgTemp() const;

    // Επιστρέφει μέγιστη θερμοκρασία
    float maxTemp() const;

    // Επιστρέφει ελάχιστη θερμοκρασία
    float minTemp() const;

    // Member συνάρτηση σύγκρισης μέσου όρου
    bool hasGreaterAverageThan(const TSensor& sensor) const;

    // Έλεγχος αν δύο αισθητήρες έχουν ίδιες μετρήσεις
    bool hasSameMeasurements(const TSensor& sensor) const;

    // Friend συνάρτηση σύγκρισης
    friend bool friendGreaterAverage(const TSensor& s1, const TSensor& s2);

    // Global συνάρτηση σύγκρισης
    friend bool globalGreaterAverage(const TSensor& s1, const TSensor& s2);

    // Υπερφόρτωση >> για είσοδο δεδομένων
    friend istream& operator>>(istream& in, TSensor& sensor);

    // Υπερφόρτωση << για εκτύπωση δεδομένων
    friend ostream& operator<<(ostream& out, const TSensor& sensor);

    // Υπερφόρτωση > για σύγκριση μέσου όρου
    friend bool operator>(const TSensor& s1, const TSensor& s2);
};

// Δήλωση global συνάρτησης
bool globalGreaterAverage(const TSensor& s1, const TSensor& s2);

#endif
