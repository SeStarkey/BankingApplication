#ifndef INVESTMENT_H
#define INVESTMENT_H
#include "AppDisplay.h"

class userInvestment { // investment class for my header file that contains my static member functions to be accessed by my main() that will be used for calculations
public:
    static double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);
    static double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);
};

#endif
