//Performance Task 2:
//Description: Conversion Console App using functions [Dollar to Peso & Peso to Dollar]
//             This is also a debugging activity
//Name: Christopher L. Galano
//Date: November 5, 2021

#include <iostream>

using namespace std;

struct group_facet: public numpunct<char> {
    protected:
        string do_grouping() const { return "\003"; }
};

void promptAndWait();

void dollarsToPeso(float rate, unsigned usd = 1);
void pesosToDollar(float rate, unsigned php = 1);

int main() {
    float conversionRate = 50.73;
    unsigned dollarsIn, pesosIn;
    int ch, ans=0;
    do{
        system("cls");
        cout << endl;
        cout << "Dollar to Peso Conversion App" << endl << endl;
        cout << "[1] Dollar to Peso" << endl;
        cout << "[2] Peso to Dollar" << endl;
        cout << "[0] Exit the Coversion App" << endl;
        cout << "Select Conversion : ";
        cin >> ch;

        switch(ch){
            case 1:{
                cout << "\n<< Convert Dollar to Peso >>" << endl;
                dollarsToPeso(conversionRate);
                cout << "Enter a US Dollar Amount (without the dollar sign, commas or a decimal) : [####] ";
                cin >> dollarsIn;
                dollarsToPeso(conversionRate, dollarsIn);
                promptAndWait();
                break;
            }

            case 2:{
                cout << "\n<< Convert Peso to Dollar >>" << endl;
                dollarsToPeso(conversionRate);
                cout << "Enter a Philippine Peso amount (without the peso sign, commas or a decimal) : [####] ";
                cin >> pesosIn;
                pesosToDollar(conversionRate, pesosIn);
                promptAndWait();
                break;
            }

            case 0:{
                cout << "Conversion App Terminated \nThank you for using the app!";
                return 0;
            }

            default:{
                cout << "Invalid Input!";
                break;
            }
        }
    }while(ans == 0);
    return 0;
}

void promptAndWait() {
    cin.ignore(100, '\n');
    cout << "\nPress Enter or Return to continue...";
    cin.get();
}

void dollarsToPeso (float rate, unsigned usd) {
    cout.setf(ios::fixed);
    cout.precision(2);

    cout.imbue(locale(cout.getloc(), new group_facet));
    cout << "\n$" << usd << " USD = " << "P" << (rate * usd) << " Pesos. \n";
}

void pesosToDollar (float rate, unsigned php) {
    cout.setf(ios::fixed);
    cout.precision(2);

    cout.imbue(locale(cout.getloc(), new group_facet));
    cout << "\nP" << php << " Pesos = " << "$" << (php / rate) << " USD. \n";
}