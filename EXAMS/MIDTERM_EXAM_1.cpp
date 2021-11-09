//Name: Christopher L. Galano
//Activity Nsame: CPFL Midterm Exam
//Description: C++ program console conversion app
//Date: November 9, 2021

#include <iostream>

using namespace std;

//Function Declarations
//---------------------------
void kiloToMilli(double kg);
void gramToMilli(double grm);
void milliToGram(double mg);
void poundToOunce(double lb);
void promptAndWait();
//---------------------------

int main(){
    
    cout.setf(ios::fixed);
    cout.precision(2);

    //--------------------- (Variables)
    double kg, grm, mg, lb;
    int option, wait = 0;
    //--------------------- (End)

    do{
        system("cls");
        cout << endl;
        cout << "Weight Conversion App\n";
        cout << endl;
        cout << "[1] Kilogram to Milligram" << endl;
        cout << "[2] Gram to Milligram" << endl;
        cout << "[3] Milligram to Gram" << endl;
        cout << "[4] Pound to Ounce" << endl;
        cout << "[0] Exit" << endl;
        cout << "Select Conversion: ";
        cin >> option;

        switch(option){
            case 1:{
                cout << "\n<< Kilogram to Milligram >>\n";
                cout << "Enter Kilogram : ";
                cin >> kg;
                kiloToMilli(kg);
                promptAndWait();
                break;
            }

            case 2:{
                cout << "\n<< Gram to Milligram >>\n";
                cout << "Enter Gram : ";
                cin >> grm;
                gramToMilli(grm);
                promptAndWait();
                break;
            }

            case 3:{
                cout << "\n<< Milligram to Gram >>\n";
                cout << "Enter Milligram : ";
                cin >> mg;
                milliToGram(mg);
                promptAndWait();
                break;
            }

            case 4:{
                cout << "\n<< Pound to Ounce >>\n";
                cout << "Enter Pound : ";
                cin >> lb;
                poundToOunce(lb);
                promptAndWait();
                break;
            }

            case 0:{
                cout << "\nClosing the program..." << endl;
                return 0;
                break;
            }
            
            default:{
                cout << "\nError, please try again..." << endl;
                promptAndWait();
                break;
            }
        }
    } while(wait == 0);
    return 0;
}

// Functions
//-------------------------------------------------------------------
void promptAndWait() {
    cin.ignore(100, '\n');
    cout << "\nPress Enter to continue...";
    cin.get();
}

void kiloToMilli(double kg){
    cout << "\nKilogram to Milligram : " << (kg * 1000000) << " mg" << endl;
}

void gramToMilli(double grm){
    cout << "\nGram to Milligram : " << (grm * 1000) << " mg" << endl;
}

void poundToOunce(double lb){
    cout << "\nPound to Ounce : " << (lb * 16) << " oz" << endl;
}

void milliToGram(double mg){
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << "\nMilligram to Gram : " << (mg / 1000) << " g" << endl;
}
//-------------------------------------------------------------------