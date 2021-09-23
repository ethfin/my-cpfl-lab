//Name: Christopher L. Galano
//Activity Name: OE2
//Description: POS Computer System that computes at least 3 kinds of product input, plus 12% VAT.
//Date: September 16 2021
#include <iostream>
#include <string>

using namespace std;

const double TAX = 0.12;

int main(){

    //--------------Variable names---------------
    string customerName, productName1, productName2, productName3;
    int productQuantity1, productQuantity2, productQuantity3;
    double productName1_price, productName2_price, productName3_price, totalPrice1, totalPrice2, totalPrice3, semiFinalAmount, finalPrice, withTAX;
    //-------------------------------------------

    //---------------Inputs----------------------
    cout << "Enter customer name :";
    getline(cin, customerName);
    cout << "Enter product#1 name:";
    cin >> productName1;
    cout << "Enter quantity      :";
    cin >> productQuantity1;
    cout << "Enter product price :";
    cin >> productName1_price;

    cout << "Enter product#2 name:";
    cin >> productName2;
    cout << "Enter quantity      :";
    cin >> productQuantity2;
    cout << "Enter product price :";
    cin >> productName2_price;

    cout << "Enter product#3 name:";
    cin >> productName3;
    cout << "Enter quantity      :";
    cin >> productQuantity3;
    cout << "Enter product price :";
    cin >> productName3_price;

    //---------------functions-------------------
    totalPrice1 = productQuantity1 * productName1_price;

    totalPrice2 = productQuantity2 * productName2_price;

    totalPrice3 = productQuantity3 * productName3_price;

    semiFinalAmount = totalPrice1 + totalPrice2 + totalPrice3;
    withTAX = semiFinalAmount * TAX;
    finalPrice = semiFinalAmount + withTAX;
    //------------------------------------------

    //----------format---------
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    //------------------------

    //final output
    cout << "\n|--------------RECEIPTS----------------|" << endl;
    cout << "Customer Name  :" << customerName << endl;
    cout << "Product#1 Name :" << productName1 << endl;
    cout << "Quantity       :" << productQuantity1 << endl;
    cout << "Price          :" << "P" << productName1_price << endl;
    cout << "TOTAL price    :" << "P" << totalPrice1 << endl;
    cout << "|--------------------------------------|" << endl;

    cout << "Product#2 Name :" << productName2 << endl;
    cout << "Quantity       :" << productQuantity2 << endl;
    cout << "Price          :" << "P" << productName2_price << endl;
    cout << "TOTAL price    :" << "P" << totalPrice2 << endl;
    cout << "|--------------------------------------|" << endl;

    cout << "Product#3 Name :" << productName3 << endl;
    cout << "Quantity       :" << productQuantity3 << endl;
    cout << "Price          :" << "P" << productName3_price << endl;
    cout << "TOTAL price    :" << "P" << totalPrice3 << endl;
    cout << "|--------------------------------------|" << endl;

    cout << "\n|----------------TOTAL-----------------|" << endl;
    cout << "GRAND TOTAL PRICE  :" << "P" << semiFinalAmount << endl;
    cout << "VAT (" << TAX * 100 << "%)       :" << "P" << withTAX << endl;
    cout << "TOTAL AMOUNT(W/VAT):" << "P" << finalPrice << endl;
    cout << "|--------------------------------------|" << endl;

    return 0;
}