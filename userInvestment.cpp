#include "userInvestment.h"  // Including header file with class definition.
#include <iostream>          // Needed both input and output. 
#include <iomanip>           // Needed to format my numbers.
using namespace std;

// My first function, which calculates the investment growth "without" monthly deposits.
double userInvestment::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) { // Method for userInvestment class that is taking on 3 parameters.
    double balance = initialInvestment;        // Initializing my balance variable with initialInvestment amount.
    double monthlyRate = interestRate / 100.0 / 12.0;  // Initializing my monthlyRate variable with the proper conversion for the annual interest rate to a monthly rate.

    for (int year = 1; year <= numberOfYears; year++) {  // My out loop iterating through each year of the investment.
        double startingBalance = balance;  // storing the calculation so that i can use balance later to calculate the interest earned during that year.

        for (int month = 1; month <= 12; month++) { // My inner loop to compound the interest monthly. The interest is calculated and added to the balance each month
            balance = balance * (1.0 + monthlyRate);
        }

        double interestEarned = balance - startingBalance;    // interestEarned is store the caculation for the total interest earned during the year.
        printInvestmentDetails(year, balance, interestEarned); // Call out for method to print out the investment details for each year.
    }

    return balance;
}
// My second function, which is similar to the first but is calculating the investment growth "with" monthly deposits.
double userInvestment::balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    double balance = initialInvestment;
    double monthlyRate = interestRate / 100.0 / 12.0;

    for (int year = 1; year <= numberOfYears; year++) {
        double startingBalance = balance;

        for (int month = 1; month <= 12; month++) {
            balance = balance * (1.0 + monthlyRate);
            balance += monthlyDeposit;
        }

        double interestEarned = balance - startingBalance - (monthlyDeposit * 12.0);
        printInvestmentDetails(year, balance, interestEarned);
    }

    return balance;
}