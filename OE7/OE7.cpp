//Name: Christopher L. Galano
//Activity Name: OE7
//Description: Add a Login system to the application.
//Date: December 7, 2021
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int VAT1 = 12;
const int VAT2 = 10;
const int VAT3 = 5;

const char username[10] = "admin";
const char password[10] = "admin";

void login();

// Tax schemes:           
//       Salary Range                      VAT
//       >40000                            12%
//       30000-40000                       10%
//       <20000                             5%

int main(){

    //--------------Variable names---------------
    string eName;
    int ID, numOfWork;
    double netPay, ratePerHour, taxPay, grossPay;
    //-------------------------------------------

    login();

    cout << "\nWelcome!" << endl;
    cout << "Enter employee ID  :";
    cin >> ID;
    cout << "Enter employee name:";
    cin >> eName;
    cout << "Enter hours worked :";
    cin >> numOfWork;
    cout << "Enter rate per hour:" ;
    cin >> ratePerHour;

    netPay = ratePerHour * numOfWork;
    grossPay = netPay;

    //----------format---------
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    //------------------------

    if (netPay > 40000) {
        cout << "-----------------------" << endl;
        netPay = netPay - (netPay * VAT1 / 100);
        cout << "Employee ID  :" << ID << endl;
        cout << "Employee Name:" << eName << endl;
        cout << "Gross Pay    :" << grossPay << endl;
        cout << "Tax Rate     :" << VAT1 << "%" << endl;
        cout << "Net Pay      :" << netPay << endl;
    } else if (netPay >= 30000) {
        cout << "-----------------------" << endl;
        netPay = netPay - (netPay * VAT2 / 100);
        cout << "Employee ID  :" << ID << endl;
        cout << "Employee Name:" << eName << endl;
        cout << "Gross Pay    :" << grossPay << endl;
        cout << "Tax Rate     :" << VAT2 << "%" << endl;
        cout << "Net Pay      :" << netPay << endl;
    } else if (netPay <= 20000) {
        cout << "-----------------------" << endl;
        netPay = netPay - (netPay * VAT3 / 100);
        cout << "Employee ID  :" << ID << endl;
        cout << "Employee Name:" << eName << endl;
        cout << "Gross Pay    :" << grossPay << endl;
        cout << "Tax Rate     :" << VAT3 << "%" << endl;
        cout << "Net Pay      :" << netPay << endl;
    } else {
        cout << "-----------------------" << endl;
        cout << "Employee ID  :" << ID << endl;
        cout << "Employee Name:" << eName << endl;
        cout << "Gross Pay    :" << grossPay << endl;
        cout << "Tax Rate     :" << "0" << "%" << endl;
        cout << "Net Pay      :" << netPay << endl;
        // The Tax schemes on the third activitie didn't specify what will happen 
        // if the Salary Range is greater than 20,000 (>20000) so I added 
        // another else to print out the salary.
    };

    return 0;
}

void login(){
    char usr_pwd[10];
    char usrnme[10];
    bool retry = true;

    while (retry){
        cout << "Please enter your username : ";
        cin >> usrnme;
        cout << "Please enter your password : ";
        cin >> usr_pwd;

        if(!(strcmp(usr_pwd, password) || strcmp(usrnme, username))){
            retry = false;
        } else {
            cout << endl << "Incorrect password or username... Please try again." << endl << endl;
        }
    }
}