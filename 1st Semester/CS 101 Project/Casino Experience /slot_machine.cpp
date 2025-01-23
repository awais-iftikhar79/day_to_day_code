#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
extern string file_name;

const int rows=3;
const int columns=3;

int slot_machine_winnings_reporter(int &final_balance, string file_name) {
    fstream my_file(file_name, ios::app);
    my_file << "You played the slot machine, your balance changed to: $" << final_balance << endl;
    my_file.close();
    return final_balance;
}

void spin(int arr[rows][columns]){

for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < columns; j++)
    {
    arr[i][j]=rand()%5+1;       //Random numbers ranging from 1 to 5
    }
}
}

void displayGame(int arr[rows][columns]){

cout<<"Slot machine results:"<<endl;

for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < columns; j++)
    {
    cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
}

bool checkThreeInARow(int arr [rows][columns], int &row){

    for (int i = 0; i < rows; i++) {
        if (arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]) {       //Check matching row
            row=i;
            return true;
        }
    }

    return false;
    }

int userWinnings(int arr[rows][columns]) {

    int winnings=0;
    int winningRow=-1;

    if (checkThreeInARow(arr, winningRow)) {
        winnings=arr[winningRow][0]*10;
    }

    return winnings;
}

void play_slot_machine(int &balance){

    if (balance<5) {
        cout<<"Insufficient funds to play game!"<<endl;
        return;
    }

    balance=balance-5;
    int arr[rows][columns];     //Declaration of global variable

    spin(arr);                  //Spin machine
    displayGame(arr);           //Display results

    int winnings=userWinnings(arr);

    if (winnings>0) {
        cout<<"Congratulations! You have won $"<<winnings<<endl;
    } else {
        cout<<"You lost the game, better luck next time!"<<endl;
    }

    balance=balance+winnings;    //Update account balance after winnings or loss

    cout<<"Your updated balance is now $"<<balance<<endl;
    cout<<endl;

}

void slot_machine_main(){

    srand(time(0));
    
    //string file_name = "casino_file_system.txt";

    char option;
    int balance;

    cout<<"---------- WELCOME TO THE SLOT MACHINE GAME ---------- "<<endl;
    cout<<endl;

    do {
        cout<<"Enter your starting balance (Maximum allowed: $50): $";
        cin>>balance;

        if (balance>50 || balance<5)
        {
            cout<<"Invalid balance, please enter a value between $1 and $50."<<endl;
            cout<<endl;
        }

    } while (balance>50 || balance<5);


    do
    {
        cout<<"MAIN MENU:"<<endl;
        cout<<"     Spin slot machine ($5 per spin)     (1)"<<endl;
        cout<<"     View balance                        (2)"<<endl;
        cout<<"     Exit game                           (3)"<<endl;
        cout<<"What option would you like to perform?";
        cin>>option;
        cout<<endl;

        switch (option) {
            case '1':
                play_slot_machine(balance);
                break;

            case '2':
                cout<<"Your available balance is $"<<balance<<endl;
                break;

            case '3':
                cout<<"Thank you for playing the slot machine game!";
                break;

            default:
                cout<<"Invalid choice, pick again!"<<endl;
        }
    } while (option != '3');
    
    slot_machine_winnings_reporter(balance, file_name);
}


