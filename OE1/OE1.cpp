//Name: Christopher L. Galano
//Activity: OE1
//Description: Input and Output
//Date: September 7 2021
#include <iostream>
#include <string>

using namespace std;

int main()
{

    //--------------Variable names---------------
    string name, gender, address, yrsc, course;
    long long age, cn;
    //-------------------------------------------

    cout << "Hello!" << endl;

    //Name
    cout << "Enter your Name:";
    getline(cin, name);
    //Gender
    cout << "Enter your Gender:";
    getline(cin, gender);
    //Age
    cout << "Enter your Age:";
    cin >> age;
    cin.ignore();
    //Address
    cout << "Enter your Address:";
    getline(cin, address);
    //Year & Section
    cout << "Enter your Year & Section:";
    getline(cin, yrsc);
    //Course
    cout << "Enter your Course:";
    getline(cin, course);
    //Contact Number
    cout << "Enter your Contact Number:";
    cin >> cn;

    //----------Output-----------
    cout << "\nYour Name is:" << name;
    cout << "\nYour Gender is:" << gender;
    cout << "\nYour Age is:" << age;
    cout << "\nYour Address is:" << address;
    cout << "\nYour Year & Section is:" << yrsc;
    cout << "\nYour Course is:" << course;
    cout << "\nYour Contact Number is:" << cn;
    return 0;
}