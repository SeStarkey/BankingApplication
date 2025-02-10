#include "userInvestment.h"  // Including header files
#include "AppDisplay.h"      // Including header files
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> 
#include <sstream> // Required to use the ostringstream for the printInvestmentDetails.
#include <iostream>
using namespace std;

// My display Header function. This is what the user will initially see. Spiced it up a litte, while also using string constructors to produce my symbols '*' and '='.
void displayHeader() {
    cout << string(46, '=') << endl;
    cout << "|              AIRGEAD BANKING               |" << endl;
    cout << string(46, '=') << endl;
    cout << endl;
    cout << string(46, '*') << endl;
    cout << string(17, '*') << " Data Input " << string(17, '*') << endl;
    cout << endl;
}
// My get UserInput function that provides the required print statements and the ability to get user input. I also used references here &. From what I've read this increases the speed of the program, while also allowing the users input to actually change the variables in the main() of the program.
void getUserInput(double& initialInvestment, double& monthlyDeposit, double& annualInterest, int& years) {
   
    cout << "Initial Investment Amount: ";
    cin >> initialInvestment;
   
    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;
   
    cout << "Annual Interest: ";
    cin >> annualInterest;
   
    cout << "Number of years: ";
    cin >> years;
   
    cout << "Press any key to continue . . ." << endl;
    cin.ignore(); // clearing my input buffer.
    cin.get(); // added for the user to press any key before continuing.
}
// This is my function for the display report, which took a lot of tweaking to produce the required format. Once again I utilized & string and const. I did this to add some functionality within the parameter and title.
void displayReport(const string& title) {
    
    cout << endl << title << endl;
    cout << string(66, '_') << endl;
    cout << string(66, '-') << endl;
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << string(66, '-') << endl;
    cout << string(66, '-') << endl;
}
// This is my function for the printInvestmentDetails.
void printInvestmentDetails(int year, double yearEndBalance, double interestEarned) {
    ostringstream yearEndBalanceStr, interestEarnedStr;

    // This is formatting my yearEndBalance.
    yearEndBalanceStr << "$" << fixed << setprecision(2) << yearEndBalance; // setprecision here to only two decimal places.

    // This is formatting my interestEarned
    interestEarnedStr << "$" << fixed << setprecision(2) << interestEarned; // setprecision here to only two decimal places.

    // This is allowing me to print everything and fixing my column widths to 8, 20, and 35 as well as aligning my year to left and the rest to the right. 
    cout << " " << left << setw(8) << year
        << right << setw(20) << yearEndBalanceStr.str()
        << right << setw(35) << interestEarnedStr.str() << endl;
}

int main() {
    char userRepeat;        // Created characer variable for the do/while loop for user input.
    cout << "\033[92m";     // Color code to turn my programs lettering to a lime green. 
    // Do loop to keep program running as long as my user types 'y' or 'Y'.
    do {
        double initialInvestment, monthlyDeposit, annualInterest;    // Declared variables to store my users input or money amounts
        int years;                                                   // Declared my years int variable

        displayHeader();                                             // Allowing my title for the program to be shown on the users end.
        getUserInput(initialInvestment, monthlyDeposit, annualInterest, years);  // Getting my users input or investment details (money inputs)

        system("cls");                                               // To clear the screen.

        // Display report (WITHOUT) additional monthly deposits.
        displayReport("Balance and Interest Without Additional Monthly Deposits");
        userInvestment::calculateBalanceWithoutMonthlyDeposit(initialInvestment, annualInterest, years);
        
        cout << endl;                                  // Providing space between both reports. 
        // Display report (WITH) additional monthly deposits.
        displayReport("Balance and Interest With Additional Monthly Deposits");
        userInvestment::balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, annualInterest, years);

        
        // Asking my user if they would like to continue. Added line break to improve readability for user by adding space. 
        cout << "\nDo you want to continue with new inputs, or would you like to quit the program? Please select (y/n): ";
        cin >> userRepeat;

        
        if (tolower(userRepeat) == 'y') {
            system("cls");                       // If my user wants to run the program back this will clear the screen and allow them to start new running totals.
        }

    } while (tolower(userRepeat) == 'y');
    
    cout << "\nThank you for choosing the Airgead investment calculator!\n";  // Thank you message to the user using line breaks and ending program if n or N is selected. 
    return 0;
}