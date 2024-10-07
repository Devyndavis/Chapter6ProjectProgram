#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void readData(string runners[], int miles[][7], int numRunners);
void calculateTotalsAndAverages(int miles[][7], int numRunners, int total[], double average[]);
void displayResults(const string runners[], const int miles[][7], int total[], double average[], int numRunners);

int main() {
    const int numRunners = 5; // Number of runners
    string runners[numRunners]; // Array to store runner names
    int miles[numRunners][7]; // 2D array to store miles run each day
    int total[numRunners]; // Array to store total miles for each runner
    double average[numRunners]; // Array to store average miles per day for each runner

    readData(runners, miles, numRunners); // Read data from file
    calculateTotalsAndAverages(miles, numRunners, total, average); // Calculate totals and averages
    displayResults(runners, miles, total, average, numRunners); // Display the results

    return 0;
}

// Function to read runner names and miles from the file
void readData(string runners[], int miles[][7], int numRunners) {
    ifstream inputFile("runner.txt"); // Open input file
    if (!inputFile) { // Check if file opened successfully
        cerr << "Error opening file." << endl;
        exit(1); // Exit if there's an error
    }

    for (int i = 0; i < numRunners; i++) {
        inputFile >> runners[i]; // Read runner's name
        for (int j = 0; j < 7; j++) {
            inputFile >> miles[i][j]; // Read miles run each day
        }
    }
    inputFile.close(); // Close the input file
}

// Function to calculate total and average miles run
void calculateTotalsAndAverages(int miles[][7], int numRunners, int total[], double average[]) {
    for (int i = 0; i < numRunners; i++) {
        total[i] = 0; // Initialize total
        for (int j = 0; j < 7; j++) {
            total[i] += miles[i][j]; // Sum miles for the week
        }
        average[i] = static_cast<double>(total[i]) / 7; // Calculate average miles
    }
}

// Function to display the results in a formatted table
void displayResults(const string runners[], const int miles[][7], int total[], double average[], int numRunners) {
    cout << setw(15) << left << "Runner's Name"; // Header for runner names
    cout << setw(10) << "Day 1" << setw(10) << "Day 2" << setw(10) << "Day 3" 
         << setw(10) << "Day 4" << setw(10) << "Day 5" << setw(10) << "Day 6" 
         << setw(10) << "Day 7" << setw(15) << "Total" << "Average" << endl;

    cout << fixed << setprecision(2); // Set decimal precision for average

    for (int i = 0; i < numRunners; i++) {
        cout << setw(15) << left << runners[i]; // Print runner's name
        for (int j = 0; j < 7; j++) {
            cout << setw(10) << miles[i][j]; // Print miles for each day
        }
        cout << setw(15) << total[i] << average[i] << endl; // Print total and average
    }
}