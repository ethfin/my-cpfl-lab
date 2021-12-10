// Name: Christopher Galano
// Activity Name: Case Study
// Description: Create a program in C++ such that you need to implement the following concepts in your program
// Date: December 10, 2021
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void promptAndWait();
void edit(int arrayInput[]);
void addStudent(int input[]);
void logs();
void averageGrade(int avgrd[]);
void printLogs(int grades[]);

const int MAX = 4;
string name;

int main(){

    int input[MAX], c;

    system("cls");
    cout << "Please enter students name : ";
    getline(cin, name);
    cout << "\t\tPlease enter the students grades in this subjects.\n";
    cout << "\n\t[0] Math \t [1] English \t [2] Science \t [3] Filipino \n\n";
    for(int i = 0; i < MAX; i++){
        cout << "Enter the grade in [" << i << "] number :";
        cin >> input[i];
    }

    do{
        //-------------------
        system("cls");
        cout << "\t\t\t\tStudent Name: " << name << endl;
        cout << "\n\t\t [0] Math \t [1] English \t [2] Science \t [3] Filipino \n";
        cout << "\tGrades\n";
        for(int x = 0; x < MAX; x++){
            cout << "\t\t " << input[x];
        }
        cout << "\n\n";
        //---------------------------
        cout << "[1] Edit Grades" << endl;
        cout << "[2] Add new student" << endl;
        cout << "[3] View Average" << endl;
        cout << "[4] View students grade records" << endl;
        cout << "[5] Print Grade records" << endl;
        cout << "[0] Exit" << endl;
        cout << "Select Function: ";
        cin >> c;

        switch(c){
            case 1:{
                edit(input);
                promptAndWait();
                break;
            }

            case 2:{
                addStudent(input);
                promptAndWait();
                break;
            }

            case 3:{
                averageGrade(input);
                promptAndWait();
                break;
            }

            case 4:{
                logs();
                promptAndWait();
                break;
            }

            case 5:{
                printLogs(input);
                promptAndWait();
                break;
            }

            case 0:{ 
                cout << "Closing the program...";
                return 0;
                break;
            }

            default:
            {
                cout << "Error, please try again..." << endl;
                break;
            }
        }
    } while (true);

    return 0;
}

void promptAndWait() {
    cin.ignore(100, '\n');
    cout << "\nPress Enter or Return to continue...";
    cin.get();
}

void edit(int arrayInput[]){
    //---------------------------
    system("cls");
    cout << "\n\t\t [0] Math \t [1] English \t [2] Science \t [3] Filipino \n";
    cout << "\tGrades\n";
    for(int x = 0; x < MAX; x++){
        cout << "\t\t " << arrayInput[x];
    }
    cout << "\n\n";
    //---------------------------
    int i, change;
    cout << "Enter a number from 0 to " << MAX-1 << " to edit : ";
    cin >> i;

    if (i >= MAX){
        cout << "Please try again...";
    } else {
        if (i == 0){
            cout << endl << "The [0] Math grade is " << arrayInput[i] << endl;
        } else if (i == 1) {
            cout << endl << "The [1] English grade is " << arrayInput[i] << endl;
        } else if (i == 2) {
            cout << endl << "The [2] Science grade is " << arrayInput[i] << endl;
        } else if (i == 3) {
            cout << endl << "The [3] Filipino grade is " << arrayInput[i] << endl;
        }
        cout << "Enter the number you want to put : ";
        cin >> change;
        arrayInput[i] = change;
    }
}

void logs(){
    string logs;
    ifstream in("grades.txt");
    if(in.fail()){
        cout << "Error opening file..." << endl;
        exit(1);
    }

    while (getline(in, logs)){
        cout << logs << endl;
    }

    in.close();
}

void printLogs(int grades[]){
    int avg = (grades[0] + grades[1] + grades[2] + grades[3]) / 4;
    ofstream file;
    cout << endl;
    cout << "\tStudent Name :" << name << endl;
    cout << "|\t" << "Math Grade :" << grades[0] << "\t\t|" << endl;
    cout << "|\t" << "English Grade :" << grades[1] << "\t|" << endl;
    cout << "|\t" << "Science Grade :" << grades[2] << "\t|" << endl;
    cout << "|\t" << "Filipino Grade :" << grades[3] << "\t|" << endl;
    cout << "|\t" << "AVERAGE GRADE :" << avg << "\t|" << endl;
    cout << endl;

    file.open("grades.txt", ios::app);
    file << endl;
    file << "\tStudent Name :" << name << endl;
    file << "|\t" << "Math Grade :" << grades[0] << "\t\t|" << endl;
    file << "|\t" << "English Grade :" << grades[1] << "\t|" << endl;
    file << "|\t" << "Science Grade :" << grades[2] << "\t|" << endl;
    file << "|\t" << "Filipino Grade :" << grades[3] << "\t|" << endl;
    file << "|\t" << "AVERAGE GRADE :" << avg << "\t|" << endl;
    file << endl;
    file.close();
}

void averageGrade(int avgrd[]){
    int avg = (avgrd[0] + avgrd[1] + avgrd[2] + avgrd[3]) / 4, fail = 0;
    cout << "The students average grade is " << avg << endl << endl;
    for (int i = 0; i < 4; i++){
        if(avgrd[i] < 75){
            fail++;
        }
    }
    cout << "The student have failed " << fail << " subject/s\n";
    if (fail == 0){
        if (avg >= 75){
            cout << "The student Passed!" << endl;
        } else {
            cout << "The student Failed..." << endl;
        }
    }
}

void addStudent(int input[]){
    system("cls");
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Please enter students name : ";
    getline(cin, name);
    cout << "\t\tPlease enter the students grades in this subjects.\n";
    cout << "\n\t[0] Math \t [1] English \t [2] Science \t [3] Filipino \n\n";
    for(int y = 0; y < MAX; y++){
        cout << "Enter the grade in [" << y << "] number :";
        cin >> input[y];
    }
}