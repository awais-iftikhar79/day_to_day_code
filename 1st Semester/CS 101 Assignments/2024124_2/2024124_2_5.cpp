#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX_NUM_ACCOUNTS = 100;

void showMenu() {
    cout << "Available Transaction Types" << endl;
    cout << "O: Open Account" << endl;
    cout << "B: Check Balance" << endl;
    cout << "D: Deposit" << endl;
    cout << "W: Withdraw" << endl;
    cout << "C: Close Account" << endl;
    cout << "I: Interest" << endl;
    cout << "P: Print All Accounts" << endl;
    cout << "E: Exit" << endl;
}

bool isAccountValid(int accountNum, bool accountStatus[]) {
    int index = accountNum - 1001;
    return index >= 0 && index < MAX_NUM_ACCOUNTS && accountStatus[index];
}

int main() {
    cout << fixed << setprecision(2);
    
    float accountBalances[MAX_NUM_ACCOUNTS] = {0};
    bool accountStatus[MAX_NUM_ACCOUNTS] = {false};
    int totalAccounts = 0;

    while (true) {
        showMenu();
        char transType;
        cout << "\nTransaction Type?: ";
        cin >> transType;
        cout << endl;

        switch (transType) {
            case 'O': {
                if (totalAccounts < MAX_NUM_ACCOUNTS) {
                    float initialDeposit;
                    cout << "Amount to Deposit?: ";
                    cin >> initialDeposit;

                    if (initialDeposit < 0) {
                        cout << "ERROR: Deposit amount cannot be negative.\n";
                    } else {
                        accountBalances[totalAccounts] = initialDeposit;
                        accountStatus[totalAccounts] = true;
                        cout << "Account Number Assigned: " << 1001 + totalAccounts << endl;
                        totalAccounts++;
                    }
                } else {
                    cout << "ERROR: NO AVAILABLE VACANCY\n";
                }
                break;
            }

            case 'B': {
                int accountNum;
                cout << "Account Number?: ";
                cin >> accountNum;

                if (isAccountValid(accountNum, accountStatus)) {
                    cout << "Balance: " << accountBalances[accountNum - 1001] << endl;
                } else {
                    cout << "ERROR: ACCOUNT NOT FOUND\n";
                }
                break;
            }

            case 'D': {
                int accountNum;
                cout << "Account Number?: ";
                cin >> accountNum;

                if (isAccountValid(accountNum, accountStatus)) {
                    float depositAmount;
                    cout << "Amount to Deposit?: ";
                    cin >> depositAmount;

                    if (depositAmount < 0) {
                        cout << "ERROR: Deposit amount cannot be negative.\n";
                    } else {
                        accountBalances[accountNum - 1001] += depositAmount;
                        cout << "Acc# " << accountNum << "\nNew Balance: " << accountBalances[accountNum - 1001] << endl;
                    }
                } else {
                    cout << "ERROR: ACCOUNT NOT FOUND\n";
                }
                break;
            }

            case 'W': {
                int accountNum;
                cout << "Account Number?: ";
                cin >> accountNum;

                if (isAccountValid(accountNum, accountStatus)) {
                    float withdrawalAmount;
                    cout << "Amount to Withdraw?: ";
                    cin >> withdrawalAmount;

                    if (withdrawalAmount < 0) {
                        cout << "ERROR: Withdrawal amount cannot be negative.\n";
                    } else if (accountBalances[accountNum - 1001] >= withdrawalAmount) {
                        accountBalances[accountNum - 1001] -= withdrawalAmount;
                        cout << "Acc# " << accountNum << "\nNew Balance: " << accountBalances[accountNum - 1001] << endl;
                    } else {
                        cout << "ERROR: NOT ENOUGH FUNDS\n";
                    }
                } else {
                    cout << "ERROR: ACCOUNT NOT FOUND\n";
                }
                break;
            }

            case 'C': {
                int accountNum;
                cout << "Account Number?: ";
                cin >> accountNum;

                int index = accountNum - 1001;
                if (index >= 0 && index < MAX_NUM_ACCOUNTS && accountStatus[index]) {
                    accountStatus[index] = false;
                    accountBalances[index] = 0; // Set balance to 0
                    cout << "Account #" << accountNum << " Closed Successfully.\n";
                } else {
                    cout << "ERROR: ACCOUNT NOT FOUND\n";
                }
                break;
            }

            case 'I': {
                float interestRate;
                cout << "Interest Rate (%): ";
                cin >> interestRate;

                if (interestRate < 0) {
                    cout << "ERROR: Interest rate cannot be negative.\n";
                } else {
                    for (int j = 0; j < MAX_NUM_ACCOUNTS; ++j) {
                        if (accountStatus[j]) {
                            accountBalances[j] *= (1 + interestRate / 100);
                        }
                    }
                    cout << "Interest applied to all open accounts.\n";
                }
                break;
            }

            case 'P': {
                for (int j = 0; j < MAX_NUM_ACCOUNTS; ++j) {
                    cout << "\nAcc# " << 1001 + j << ": ";
                    if (accountStatus[j]) {
                        cout << "Balance: " << accountBalances[j] << endl;
                    } else {
                        cout << "ACCOUNT DOES NOT EXIST\n";
                    }
                }
                break;
            }

            case 'E': {
                cout << "Exiting the program. Thank you!\n";
                exit(EXIT_SUCCESS);
            }

            default:
                cout << "ERROR: INVALID TRANSACTION TYPE\n";
                break;
        }

        int continueTrans;
        cout << "\nMake Another Transaction (1 for yes, 0 for no): ";
        cin >> continueTrans;
        if (continueTrans != 1) {
            cout << "Thank you for using the banking system!\n";
            break;
        }
        cout << endl;
    }

    return 0;
}

