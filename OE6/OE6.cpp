//Name: Christopher L. Galano
//Activity Name: OE6
//Description: create a function that can search and sort arrays
//Date: November 25 2021
#include <iostream>

using namespace std;

void promptAndWait();
void search(int arrayInput[], int n);
void asc(int arrayInput[], int n);
void des(int arrayInput[], int n);

const int MAX = 100;

int main(){

    int input[MAX], inp, c;

    cout << "Enter a number of indices in the array : ";
    cin >> inp;

    // Read array elements
    for(int i = 0; i < inp; i++){
        cout << "Enter the index [" << i << "] number :";
        cin >> input[i];
    }

    do{
        system("cls");
        //---------------------------
        cout << "\nArray list {";
        for(int x = 0; x < inp; x++){
            cout << " " << input[x];
        }
        cout << " }\n\n";
        //---------------------------
        cout << "[1] Searching Array" << endl;
        cout << "[2] Sorting Array (Ascending)" << endl;
        cout << "[3] Sorting Array (Descending)" << endl;
        cout << "[0] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;

        switch(c){
            case 1:{
                search(input, inp);
                promptAndWait();
                break;
            }

            case 2:{
                asc(input, inp);
                promptAndWait();
                break;
            }

            case 3:{
                des(input, inp);
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
                promptAndWait();
                break;
            }
        }
    } while(true);
    

    return 0;
}

void promptAndWait() {
    cin.ignore(100, '\n');
    cout << "\nPress Enter or Return to continue...";
    cin.get();
}


void search(int arrayInput[], int n){
    //---------------------------
    cout << "\nArray list {";
    for(int x = 0; x < n; x++){
        cout << " " << arrayInput[x];
    }
    cout << " }\n";
    //---------------------------
    int i;
    cout << "Enter a number from 0 to " << n-1 << " : ";
    cin >> i;

    if (i == n){
        cout << "Please try again...";
    } else {
        cout << endl << "The array index of " << i << " is " << arrayInput[i];
    }
}

void asc(int arrayInput[], int n){
    //---------------------------
    cout << "\nArray list {";
    for(int x = 0; x < n; x++){
        cout << " " << arrayInput[x];
    }
    cout << " }\n";
    //---------------------------
    int tValue;
    for(int i = 0; i < n; i++){		
		for(int j = i + 1; j < n; j++){
			if(arrayInput[j] < arrayInput[i]){
				tValue = arrayInput[i];
				arrayInput[i] = arrayInput[j];
				arrayInput[j] = tValue;
			}
		}
	}

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Array Index [" << i << "] = "<< arrayInput[i];
    }
}

void des(int arrayInput[], int n){
    //---------------------------
    cout << "\nArray list {";
    for(int x = 0; x < n; x++){
        cout << " " << arrayInput[x];
    }
    cout << " }\n";
    //---------------------------
    int tValue;
    for(int i = 0; i < n; i++){		
		for(int j = i + 1; j < n; j++){
			if(arrayInput[i] < arrayInput[j]){
				tValue = arrayInput[i];
				arrayInput[i] = arrayInput[j];
				arrayInput[j] = tValue;
			}
		}
	}

    for (int i = 0; i < n; i++){
        cout << endl << "Array Index [" << i << "] = "<< arrayInput[i];
    }
}