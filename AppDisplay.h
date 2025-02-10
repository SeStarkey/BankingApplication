#ifndef DISPLAY_H // preventing multiple inclusions
#define DISPLAY_H // preventing multiple inclusions
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void printInvestmentDetails(int year, double yearEndBalance, double interestEarned); // Function to print the detailed investment information using 3 required parameters.
void displayHeader(); // My function to display header for the app/calculator
void getUserInput(double& initialInvestment, double& monthlyDeposit, double& annualInterest, int& years); // Function to collect user investment parameters.
void displayReport(string& title);  // Function to display my final report.

#endif
