#include <iostream>
using namespace std;

int main() {
    for (int row = 0; row < 16; ++row) {
        if (row < 15) {
            
            for (float space = 0; space < (16 - row) / 4; ++space) {
                cout << "     "; 
            }

                       if (row % 4 == 0) {
                cout << "*****"; 
            } else {
                cout << "     *    "; 
            }

            
            for (float space = 0; space < row / 4; ++space) {
                cout << "     "; 
            }

        } else {
            
            for (int dash = -1; dash < (row + 1) / 4; ++dash) {
                cout << "*****";
            }
        }
        cout << '*' << endl; 
    }

    return 0;
}

