#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int rows=3;
const int columns=3;
const int colours=3;
const int numbers=7;
string file_name;


// ----------------------------------------------------------------
int roulette_main();                                                 //
void play_roulette(int balance);                                     //
bool Check_win(int result, int bet_number, int bet_type);            // ROULETTE FUNCTION DEFINITIONS
int spin_roulette_wheel();                                           //
void display_dice_roll();                                            //
int roulette_winnings_reporter(int final_balance, string file_name); //
// ---------------------------------------------------------------
void slot_machine_main();                                               //
void play_slot_machine(int balance);                                    //
int userWinnings(int arr[rows][columns]);                               //
bool checkThreeInARow(int arr [rows][columns], int row);                // SLOT MACHINE DEFINITIONS
void displayGame(int arr[rows][columns]);                               //
void spin(int arr[rows][columns]);                                      //
int slot_machine_winnings_reporter(int final_balance, string file_name);//
// ---------------------------------------------------------------
int dice_roll_main();                                                //
void play_dice_roll(int balance);                                    //
bool dice_roll_check_win(int bet_type,int user_guess,int dice_sum);  // DICE ROLL DEFINITIONS
void dice_roll_display();                                            //
void dice_roll_main_menu();                                          //
int diceroll_winnings_reporter(int final_balance, string file_name);
// ---------------------------------------------------------------
int wheel_of_fortune_main();                                                                        //
int user_winnings(string spinResult, int betAmount, char option, int betChoice, string betColour);  // WHEEL OF FORTUNE DEFINITIONS
void spin_wheel_of_fortune(string arr[colours][numbers], string result, int row, int column);       //
int wheel_of_fortune_winnings_reporter(int &final_balance, string file_name);
// ---------------------------------------------------------------


int read_file(string file_name) {
    string line;
    ifstream my_file(file_name);
    
    if (!my_file) {
        cout << "Couldn't open file for read." << endl;
        return 0;
    }
    cout << "Our files say...\nHere's your playing history: " << endl;
    cout  << "Name: ";
    getline(my_file, line);
    cout << line << endl;
    
    int i = 0;
    while (getline(my_file, line)) {
        i++;
        cout << i << ": " << line << endl;
    }
    
    my_file.close();
    return 1;
}


int main(){
    
    string name;
    int choice;
    

    cout << "---------------- WELCOME TO THE CASINO EXPERIENCE ----------------" << endl;
    
    cout << "Create an account to proceed" << endl;
    cout << "Enter your name: ";
    
    getline(cin, name);
    
    file_name = name + ".txt";
    
    ofstream my_file(file_name, ios::app);
    if (!my_file) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    my_file << name << endl;
    
    cout << "                       Available Games:" << endl;
    cout << "                           Roulette     (1)" << endl;
    cout << "                         Slot Machine   (2)" << endl;
    cout << "                          Dice Roll     (3)" << endl;
    cout << "                       Wheel Of Fortune (4)" << endl;
    
    cout << endl;
    
    cout << "Select any option to play: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            // Roulette
            roulette_main();
            
            break;
        case 2:
            // Slot Machine
            slot_machine_main();
            break;
        case 3:
            // Dice Roll
            dice_roll_main();
            break;
        case 4:
            // Wheel Of Fortune
            wheel_of_fortune_main();
            break;
        default:
            cout << "Invalid choice. Please restart and choose an option between 1 and 4 from the above list." << endl;
            exit(1);
            break;
    }
    read_file(file_name);
    my_file.close();
    return 0;
}

