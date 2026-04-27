#ifndef TSENSOR_H
#define TSENSOR_H

#include <iostream>
using namespace std;

class TSensor {
private:
    int sid;
    float measurements[5];

public:
    TSensor();
    TSensor(int id, float m1, float m2, float m3, float m4, float m5);

    void setData(int id, float m1, float m2, float m3, float m4, float m5);
    void readData();
    void printData() const;

    float avgTemp() const;
    float maxTemp() const;
    float minTemp() const;

    bool hasSameMeasurements(const TSensor& sensor) const;

    bool hasGreaterAverageThan(const TSensor& sensor) const;
    friend bool friendGreaterAverage(const TSensor& s1, const TSensor& s2);

    friend istream& operator>>(istream& in, TSensor& sensor);
    friend ostream& operator<<(ostream& out, const TSensor& sensor);
    friend bool operator>(const TSensor& s1, const TSensor& s2);
};

bool globalGreaterAverage(const TSensor& s1, const TSensor& s2);

#endif
