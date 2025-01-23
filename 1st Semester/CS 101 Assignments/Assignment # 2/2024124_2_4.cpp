#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string grayCodeArray[16] = {"0000", "0001", "0011", "0010", "0110", "0111",
                                 "0101", "0100", "1100", "1101", "1111", "1110",
                                 "1010", "1011", "1001", "1000"};
    
    int userInput = -1;
    while (userInput < 0 || userInput > 65535) {
        cout << "Please enter a value between 0 and 65535 (inclusive): ";
        cin >> userInput;
    }
    
    int hexValues[4] = {0}; 

  
    for (int position = 3; position >= 0; --position) { 
        hexValues[position] = userInput % 16; 
        userInput /= 16;
    }
    
    
    cout << "Gray codes for the input are: ";
    for (int index = 0; index < 4; ++index) {
        cout << grayCodeArray[hexValues[index]] << ' ';
    }
    
    cout << endl;
    return 0;
}

