// Name: Christopher Galano
// Activity Name: PT3
// Description: Create a salary program that can also create a file.
// Date: November 21, 2021

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void salaryProgram();
void promptAndWait();
void logs();

const int VAT1 = 12;
const int VAT2 = 10;
const int VAT3 = 5;

int main(){
    int option, wait = 0;
    do{
        cout << "[1] Salary Program" << endl;
        cout << "[2] View File Logs" << endl;
        cout << "[3] Exit" << endl;
        cout << "Select Function: ";
        cin >> option;

        switch(option){
            case 1:{
                salaryProgram();
                promptAndWait();
                break;
            }

            case 2:{
                logs();
                promptAndWait();
                break;
            }

            case 3:{
                cout << "Closing the program..." << endl;
                return 0;
                break;
            }
            
            default:{
                cout << "Error, please try again..." << endl;
                break;
            }
        }
    } while(wait == 0);

    return 0;
}

void salaryProgram(){
    //--------------Variable names---------------
    string eName;
    int ID, numOfWork;
    double netPay, ratePerHour, taxPay, grossPay;
    ofstream op;
    //-------------------------------------------

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
    op.setf(ios::fixed);
    op.setf(ios::showpoint);
    op.precision(2);
    //------------------------

    if (netPay > 40000) {
        cout << "|-----------------------" << endl;
        netPay = netPay - (netPay * VAT1 / 100);
        cout << "|Employee ID  :" << ID << endl;
        cout << "|Employee Name:" << eName << endl;
        cout << "|Gross Pay    :" << grossPay << endl;
        cout << "|Tax Rate     :" << VAT1 << "%" << endl;
        cout << "|Net Pay      :" << netPay << endl;
        cout << "|-----------------------" << endl;

        op.open("logs.txt", ios::app);
        op << "|-----------------------" << endl;
        op << "|Employee ID  :" << ID << endl;
        op << "|Employee Name:" << eName << endl;
        op << "|Gross Pay    :" << grossPay << endl;
        op << "|Tax Rate     :" << VAT1 << "%" << endl;
        op << "|Net Pay      :" << netPay << endl;
        op << "|-----------------------" << endl << endl;
        op.close();
    } else if (netPay >= 30000) {
        cout << "|-----------------------" << endl;
        netPay = netPay - (netPay * VAT2 / 100);
        cout << "|Employee ID  :" << ID << endl;
        cout << "|Employee Name:" << eName << endl;
        cout << "|Gross Pay    :" << grossPay << endl;
        cout << "|Tax Rate     :" << VAT2 << "%" << endl;
        cout << "|Net Pay      :" << netPay << endl;
        cout << "|-----------------------" << endl;

        op.open("logs.txt", ios::app);
        op << "|-----------------------" << endl;
        op << "|Employee ID  :" << ID << endl;
        op << "|Employee Name:" << eName << endl;
        op << "|Gross Pay    :" << grossPay << endl;
        op << "|Tax Rate     :" << VAT2 << "%" << endl;
        op << "|Net Pay      :" << netPay << endl;
        op << "|-----------------------" << endl << endl;
        op.close();
    } else if (netPay <= 20000) {
        cout << "|-----------------------" << endl;
        netPay = netPay - (netPay * VAT3 / 100);
        cout << "|Employee ID  :" << ID << endl;
        cout << "|Employee Name:" << eName << endl;
        cout << "|Gross Pay    :" << grossPay << endl;
        cout << "|Tax Rate     :" << VAT3 << "%" << endl;
        cout << "|Net Pay      :" << netPay << endl;
        cout << "|-----------------------" << endl;

        op.open("logs.txt", ios::app);
        op << "|-----------------------" << endl;
        op << "|Employee ID  :" << ID << endl;
        op << "|Employee Name:" << eName << endl;
        op << "|Gross Pay    :" << grossPay << endl;
        op << "|Tax Rate     :" << VAT3 << "%" << endl;
        op << "|Net Pay      :" << netPay << endl;
        op << "|-----------------------" << endl << endl;
        op.close();
    } else {
        cout << "|-----------------------" << endl;
        cout << "|Employee ID  :" << ID << endl;
        cout << "|Employee Name:" << eName << endl;
        cout << "|Gross Pay    :" << grossPay << endl;
        cout << "|Tax Rate     :" << "0" << "%" << endl;
        cout << "|Net Pay      :" << netPay << endl;
        cout << "|-----------------------" << endl;

        op.open("logs.txt", ios::app);
        op << "|-----------------------" << endl;
        op << "|Employee ID  :" << ID << endl;
        op << "|Employee Name:" << eName << endl;
        op << "|Gross Pay    :" << grossPay << endl;
        op << "|Tax Rate     :" << "0" << "%" << endl;
        op << "|Net Pay      :" << netPay << endl;
        op << "|-----------------------" << endl << endl;
        op.close();
    };
}

void promptAndWait() {
    cin.ignore(100, '\n');
    cout << "\nPress Enter or Return to continue...";
    cin.get();
}

void logs(){
    string logs;
    ifstream in("logs.txt");
    if(in.fail()){
        cout << "Error opening file..." << endl;
        exit(1);
    }

    while (getline(in, logs)){
        cout << logs << endl;
    }

    in.close();
}