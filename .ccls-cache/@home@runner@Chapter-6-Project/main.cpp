#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Struct to represent a runner
struct Runner {
    string name;         // Runner's name
    int miles[7];       // Miles run for each day of the week
    int total;          // Total miles run for the week
    double average;     // Average miles run per day
};

// Function prototypes
void readData(Runner runners[], int numRunners);
void calculateTotalsAndAverages(Runner runners[], int numRunners);
void displayResults(const Runner runners[], int numRunners);

int main() {
    const int numRunners = 5; // Number of runners
    Runner runners[numRunners]; // Array of structs to store runner data

    readData(runners, numRunners); // Read data from file
    calculateTotalsAndAverages(runners, numRunners); // Calculate totals and averages
    displayResults(runners, numRunners); // Display the results

    return 0;
}

// Function to read runner names and miles from the file
void readData(Runner runners[], int numRunners) {
    ifstream inputFile("runner.txt"); // Open input file
    if (!inputFile) { // Check if file opened successfully
        cerr << "Error opening file." << endl;
        exit(1); // Exit if there's an error
    }

    for (int i = 0; i < numRunners; i++) {
        inputFile >> runners[i].name; // Read runner's name
        for (int j = 0; j < 7; j++) {
            inputFile >> runners[i].miles[j]; // Read miles run each day
        }
    }
    inputFile.close(); // Close the input file
}

// Function to calculate total and average miles run
void calculateTotalsAndAverages(Runner runners[], int numRunners) {
    for (int i = 0; i < numRunners; i++) {
        runners[i].total = 0; // Initialize total
        for (int j = 0; j < 7; j++) {
            runners[i].total += runners[i].miles[j]; // Sum miles for the week
        }
        runners[i].average = static_cast<double>(runners[i].total) / 7; // Calculate average miles
    }
}

// Function to display the results in a formatted table
void displayResults(const Runner runners[], int numRunners) {
    cout << setw(15) << left << "Runner's Name"; // Header for runner names
    cout << setw(10) << "Day 1" << setw(10) << "Day 2" << setw(10) << "Day 3" 
         << setw(10) << "Day 4" << setw(10) << "Day 5" << setw(10) << "Day 6" 
         << setw(10) << "Day 7" << setw(15) << "Total" << "Average" << endl;

    cout << fixed << setprecision(2); // Set decimal precision for average

    for (int i = 0; i < numRunners; i++) {
        cout << setw(15) << left << runners[i].name; // Print runner's name
        for (int j = 0; j < 7; j++) {
            cout << setw(10) << runners[i].miles[j]; // Print miles for each day
        }
        cout << setw(15) << runners[i].total << runners[i].average << endl; // Print total and average
    }
}