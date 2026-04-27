# Temperature Sensor Monitoring System (C++)

A console-based C++ application that simulates a temperature monitoring system using object-oriented programming principles.

---

## Description

This project implements a `TSensor` class that represents a temperature sensor storing its latest 5 measurements.

The program allows:
- Creating and managing multiple sensors
- Reading sensor data from user input
- Calculating statistics such as average, minimum, and maximum temperature
- Comparing sensors using multiple approaches (member, friend, global functions, and operator overloading)

---

## Features

- Object-Oriented Design (classes, constructors)
- Operator Overloading (`<<`, `>>`, `>`)
- Input Validation (sensor ID and temperature range)
- Statistical Analysis:
  - Average temperature
  - Maximum temperature
  - Minimum temperature
- Comparison of sensors using:
  - Member function
  - Friend function
  - Global function
  - Overloaded operator `>`
- Clean and formatted console output

---

## How It Works

The program creates **3 sensors**:

1. One using a constructor with parameters  
2. One using the `setData()` function  
3. One using user input (`cin >>`)  

It then:
- Displays all sensor data
- Shows max temperature per sensor
- Checks if two sensors have identical measurements
- Compares average temperatures and displays the sensor with the highest value

---

##  Technologies Used

- C++
- Console (CLI)

---

##  How to Run

### Using Dev-C++
1. Open the project
2. Add files:
   - `main.cpp`
   - `TSensor.cpp`
   - `TSensor.h`
3. Click **Compile & Run (F11)**

### Using terminal (g++)
```bash
g++ main.cpp TSensor.cpp -o sensor
./sensor
```
---
## Notes
- Temperature values are validated between -50°C and 100°C
- Sensor ID must be a positive integer
- The program demonstrates multiple comparison techniques in C++

---
## Future Improvements
- Store multiple sensors dynamically (vectors)
- File input/output support
- Graphical interface (GUI)
- Real-time data simulation

---
## Author

Eirini Markantoni
