#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>

using namespace std;
extern string file_name;


int diceroll_winnings_reporter(int &final_balance, string file_name) {
    fstream my_file(file_name, ios::app);
    my_file << "You played Dice Roll, your balance changed to: $" << final_balance << endl;
    my_file.close();
    return final_balance;
}

void dice_roll_main_menu(){
    cout<<"---------------------------------"<<endl;
    cout<<"------------- Welcome to the Dice Roll Game! -------------"<<endl;
    cout<<"Select one of the following choices:"<<endl;
    cout<<"Start game    (1)"<<endl;
    cout<<"Show balance  (2)"<<endl;
    cout<<"Exit Game     (3)"<<endl;
    cout<<"----------------------------------"<<endl;
}


void dice_roll_display(){
    cout<<"--------------------------"<<endl;
    cout<<"Please select your bet type"<<endl;
    cout<<"Predict sum of dices    (1)"<<endl;
    cout<<"Predict sum is even     (2)"<<endl;
    cout<<"Predict sum is odd      (3)"<<endl;
    cout<<"--------------------------"<<endl;
}


int roll_dice(){
    return rand() % 6 + 1;
}


bool dice_roll_check_win(int bet_type,int user_guess,int dice_sum){
    switch(bet_type){
        case 1:
            return (dice_sum==user_guess);
        case 2:
            return (dice_sum%2==0);
        case 3:
            return (dice_sum%2!=0);
        default :
            cout<<"Invalid Bet Type."<<endl;
            return false;
    }
}


void play_dice_roll(int &balance){
    
    int bet_amount,bet_type,user_guess,dice_1,dice_2,dice_sum;
    cout<<"Your current balance is : $"<<balance<<endl;
    
    do{
    cout<<"Enter bet amount: $";
    cin>>bet_amount;
    if(bet_amount<0 || bet_amount>balance){
        cout<<"Please enter a valid bet amount  ($1 - $" << balance << ")";
        }
    } while(bet_amount<0 || bet_amount>balance);
    
    do{
    dice_roll_display();
    cout<<"Enter your bet type (1-3): ";
    cin>>bet_type;
    if(bet_type<1 || bet_type>3){
        cout<<"Please enter a valid bet type."<<endl;
    }
    }while(bet_type<1 || bet_type>3);
    
    do{
    if(bet_type==1){
        cout<<"Enter your guess for sum of dices (1-12): ";
        cin>>user_guess;
        if(user_guess<=0 || user_guess >12){
        cout<<"Please enter a valid sum of two dices."<<endl;
        }
    }
    } while(user_guess<=0 || user_guess >12);
    
    dice_1=roll_dice();
    dice_2=roll_dice();
    cout<<"Number on Dice 1: " <<dice_1<< " || Number on Dice 2: " << dice_2 << endl;
    dice_sum=dice_1+dice_2;
    cout<<"The sum of two dices is : "<<dice_sum<<endl;
    if (dice_roll_check_win (bet_type,user_guess,dice_sum)) {
        cout<<"Congratulations, you won!" <<endl;
        balance += (2*bet_amount);
    }else{
        cout<<"You lost the game."<<endl;
        balance -= bet_amount;
    }
}

int dice_roll_main() {
    
    srand(time(0));
    
    int starting_balance=100;
    int choice;
    bool play_again=true;
    
    do{
    dice_roll_main_menu();
    cout<<"Enter one of the choices mention above (1-3): ";
    while(true){
        cin>>choice;
        if(cin.fail() || choice<1 || choice>3){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid choice! Please enter a valid choice (1,2,3)."<<endl;
        }else{
            break;
        }
    }
    switch(choice){
        case 1:
            play_dice_roll(starting_balance);
            if(starting_balance<=0){
                cout<<"You don't have enough money to play again."<<endl;
                play_again=false;
            }
                break;
        case 2:
            cout<<"Your updated balance is: $"<<starting_balance<<endl;
            break;
        case 3:
            cout<<"Thanks for playing!"<<endl;
            play_again=false;
            break;
        default :
            cout<<"Invalid choice."<<endl;
    }
        if(starting_balance>0 && play_again){
            cout<<"Do you want to play again? (Yes: (1) | No: (0)"<<endl;
            cin>>choice;
            if(choice!=1){
                cout<<"Thanks for playing!"<<endl;
                break;
            }
        }
        } while(play_again);
    
    
    diceroll_winnings_reporter(starting_balance, file_name);
    return 0;
}

