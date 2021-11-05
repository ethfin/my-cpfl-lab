//Name: Christopher L. Galano
//Activity Name: OE5
//Description: reverse string and numbers using void functions and functions with parameters
//Date: November 5 2021

#include <iostream>
#include <string>

using namespace std;

//-------------------
string ltrs;
int option, wait = 0;
unsigned int num;
//-------------------

void reverseString(string InputString);
void reverseInt();

int main(){
    do{
        cout << "[1] Reverse a String" << endl;
        cout << "[2] Reverse Unsigned Integer" << endl;
        cout << "[3] Exit" << endl;
        cout << "Select Function: ";
        cin >> option;

        switch(option){
            case 1:{
                cout << "<< Reverse a String >>\n" << endl;
                cout << "Enter a word : ";
                cin.ignore();
                getline(cin, ltrs);
                reverseString(ltrs);
                break;
            }

            case 2:{
                cout << "<< Reverse an unsigned Integer >>\n" << endl;
                cout << "Enter a number [0-9]: ";
                cin >> num;
                cin.ignore();
                reverseInt();
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

void reverseString(string InputString){
    cout << "Reversed word: ";
    for(int i = InputString.length() - 1 ; i >= 0; i--){
        cout << InputString[i];
    }
    cout  << endl << endl;
}

void reverseInt(){
    int r;
    do {
        r *= 10;
        r += num % 10;
        num /= 10;
    } while (num > 0);
    cout << "Reversed number: " <<  r << endl << endl;
}