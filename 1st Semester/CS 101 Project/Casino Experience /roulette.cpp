#include<iostream>
#include<cstdlib>
#include<ctime>
#include <fstream>
using namespace std;

extern string file_name;
const int MIN=1;

int roulette_winnings_reporter(int &final_balance, string file_name) {
    fstream my_file(file_name, ios::app);
    my_file << "You played roulette, your balance changed to: $" << final_balance << endl;
    my_file.close();
    return final_balance;
}

void display_dice_roll(){
    cout<<"--------------------------------------------"<<endl;
    cout<<"Welcome to Casino Roulette!"<<endl;
    cout<<" Choose anyone of following for bet"<<endl;
    cout<<"     For numbers 0 to 18:             (1)"<<endl;
    cout<<"     For numbers 19 to 36:            (2)"<<endl;
    cout<<"     For Odd numbers (Black Pocket):  (3)"<<endl;
    cout<<"     For Even numbers (Red Pocket):   (4)"<<endl;
    cout<<"     Or, enter a specific bet number: (5)"<<endl;
    cout<<"--------------------------------------------"<<endl;
}
int spin_roulette_wheel(){
    return rand() % 37 ;
}
bool Check_win(int result,int bet_number,int bet_type){
    switch(bet_type){
        case 1:
            return (0<=result && result<19 );
        case 2:
            return (18<result && result<37);
        case 3:
            return (result!=0 && result%2!=0);
        case 4:
            return (result!=0 && result%2==0);
        case 5:
            return (result==bet_number);
        default :
            cout<<"Invalid Bet_Type"<<endl;
            return 0;
    }
}
void play_roulette(int &balance){
    int bet_type,bet_number,bet_amount;
    cout<<"You current balance is: "<<balance<<endl;
    do{
    cout<<"Enter bet amount between $1 and $"<<balance << ": ";
    cin>>bet_amount;
        
    if(bet_amount<MIN ||bet_amount>balance){
        if(bet_amount<MIN){
            cout<<"Bet amount is too small. Please increase it to between: $"<<MIN<<" - $"<<balance<<endl;
        } else if (bet_amount>balance) {
            cout<<"Bet amount is too large. Please decrease it to between: $"<<MIN<<" - $"<<balance<<endl;
        }
    }
        
    } while(bet_amount<MIN ||bet_amount>balance);
    display_dice_roll();
    do {
        cout << "Please select bet type you want to play: ";
        cin >> bet_type;
    } while(bet_type<0 || bet_type>5);
    
    if (bet_type == 5){
        
        do {
            cout<<"Enter your lucky number on which you want bet: ";
            cin>>bet_number;
            if(bet_number<0 || bet_number>36){
                cout<<"Please enter a valid number in range (0-36)"<<endl;
            }
        } while (bet_number<0 || bet_number>36);
}
    int result=spin_roulette_wheel();
        cout<<"After spinnig the wheel, the result is... " << result << endl;

    if (Check_win(result,bet_number,bet_type)){
        cout<<"You won!"<<endl;
        if(bet_type==5){
            balance += bet_amount * 35;
        }else{
            balance += bet_amount;
        }
    }else{
        cout<<"You lost."<<endl;
        balance -= bet_amount;
    }
        cout<<"Final balance: "<<balance<<endl;

}

int roulette_main(){
    srand(time(0));
    
    int starting_balance=100;
    char choice;
    bool play_again=true;
    while(play_again && starting_balance>0){
    play_roulette(starting_balance);
        
    if(starting_balance>0){
        cout<<"Do you want to play again? (Y/N): ";
        cin>>choice;
        if(choice!='y'&&choice!='Y'){
            play_again=false;
        }
    } else {
        cout<<"You don't have sufficient balance to play again."<<endl;
        play_again=false;
        }
    }
    cout<<"Thank you for playing!\n"<<endl;
    //cout << "Your final balance is: $" << starting_balance << endl;

    roulette_winnings_reporter(starting_balance, file_name);
    return starting_balance;
}
