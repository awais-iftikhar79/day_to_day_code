#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
extern string file_name;

const int colours=3;
const int numbers=7;

int wheel_of_fortune_winnings_reporter(int &final_balance, string file_name) {
    fstream my_file(file_name, ios::app);
    my_file << "You played the slot machine, your balance changed to: $" << final_balance << endl;
    my_file.close();
    return final_balance;
}

void spin_wheel_of_fortune(string arr[colours][numbers], string &result, int &row, int &column){
    
    row=rand()%colours;
    column=rand()%numbers;
    result=arr[row][column];
    
}

int user_winnings(string spinResult, int betAmount, char option, int betChoice, string betColour){
    
    int winnings=0;
    
    int spinNumber = spinResult[spinResult.size() - 1] - '0';               // Extract the number
    string spinColor = spinResult.substr(0, spinResult.find(' '));          // Extract the colour
    
    switch (option) {
        case '1':
            if (betChoice==spinNumber)
                winnings=betAmount*5;
            break;
            
        case '2':
            if (betColour==spinColor)
                winnings=betAmount*4;
            break;
            
        case '3':
            if ((betChoice==0 && spinNumber%2==0) || (betChoice==1 && spinNumber%2!=0))
                winnings=betAmount*3;
            break;
    }
    
    return winnings;
}


int wheel_of_fortune_main(){
    
    srand(time(0));
    //string file_name = "casino_file_system.txt";
    int net_winnings;
    
    string arr[colours][numbers] =
        {{"Red 1", "Red 2", "Red 3", "Red 4", "Red 5", "Red 6", "Red 7"},
        {"Blue 1", "Blue 2", "Blue 3", "Blue 4", "Blue 5", "Blue 6", "Blue 7"},
        {"Green 1", "Green 2", "Green 3", "Green 4", "Green 5", "Green 6", "Green 7"}};
    
    char option;
    int balance, betAmount, betNumber, spinRow, spinColumn;
    string betColour, spinResult;
    
    cout << "------------- WELCOME TO THE WHEEL OF FORTUNE -------------" << endl;
    cout << endl;
    
    do {
        cout<<"Enter your starting balance (Maximum allowed: $100): ";
        cin>>balance;
        
        if (balance>100 || balance<10)
        {
            cout<<"Invalid balance value, please enter a value between $10 and $100"<<endl;
            cout<<endl;
        }
        
    } while (balance>100 || balance<10);
    
    do
    {
        cout<<"MAIN MENU:"<<endl;
        cout<<"     Bet on a number (1-7):                  (1)"<<endl;
        cout<<"     Bet on a colour (Red, Blue, Green)      (2)"<<endl;
        cout<<"     Bet on an even or odd number            (3)"<<endl;
        cout<<"     View balance                            (4)"<<endl;
        cout<<"     Exit game                               (5)"<<endl;
        cout<<"Which option would you like to perform?";
        cin>>option;
        
        cout<<endl;
        
        do{
            
            cout<<"Enter the amount you want to bet in $: ";
            cin>>betAmount;
            
            if (balance < betAmount)
            {
                cout<<"Insufficient funds!"<<endl;
                cout<<endl;
            }
            
        } while((balance < betAmount) && (option =='1' || option =='2' || option =='3'));
        
        switch (option)
        {
            case '1':
                do {
                    cout << "Enter the number you wish to bet on (1-7): ";
                    cin >> betNumber;
                    
                    if (betNumber<1 || betNumber>7)
                    {
                        cout<<"Invalid number. Please enter a value between 1 and 7"<<endl;
                    }
                    
                } while (betNumber<1 || betNumber>7);
                break;
                
            case '2':
                do{
                    cout<<"Enter the colour you wish to bet on: ";
                    cin>>betColour;
                    
                    if (betColour!="Red" && betColour!="Blue" && betColour!="Green")
                    {
                        cout<<"Invalid colour input, choose one of Red, Blue, or Green"<<endl;
                    }
                    
                } while (betColour!="Red" && betColour!="Blue" && betColour!="Green");
                break;
                
            case '3':
                do{
                    cout<<"Bet on even (0) or odd (1) number: ";
                    cin>>betNumber;
                    
                    if (betNumber!=0 && betNumber!=1)
                    {
                        cout<<"Invalid input, enter (0) for even numbers and (1) for odd numbers"<<endl;
                    }
                    
                } while (betNumber!=0 && betNumber!=1);
                break;
                
            case '4':
                cout<<"Your available balance is $"<<balance<<endl;
                continue;
                
            case '5':
                cout<<"Thank you for playing!"<<endl;
                cout<<"Your final balance is: $"<<balance<<endl;
                return 0;
                
            default:
                cout<<"Invalid choice, pick again!"<<endl;
        }
        
        balance=balance-betAmount;
        spin_wheel_of_fortune(arr, spinResult, spinRow, spinColumn);
        cout<<"The wheel landed on: "<<spinResult<<endl;
        
        int winnings = user_winnings(spinResult, betAmount, option, betNumber, betColour);
        
        if (winnings>0)
        {
            cout<<"Congratulations! Your winnings are: $"<<winnings<<endl;
            cout<<endl;
            balance=balance+winnings;
        }
        else
        {
            cout<<"You lost."<<endl;
            cout<<endl;
        }
        
    } while (option!=5);
        
    net_winnings = balance;
    wheel_of_fortune_winnings_reporter(net_winnings, file_name);
    
    return 0;
}
