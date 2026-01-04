#include <iostream>
#include <string>

using namespace std;

int main() {
    char condition_loop = 'y';
    int option = 0;
    int amount = 0;
    int actual_balance = 0;
    string user_name;

    cout << "===============================\n";
    cout << "BANKING SYSTEM\n";
    cout << "===============================\n";
    cout << "Please, identify yourself: ";
    
    getline(cin, user_name);

    if (!user_name.empty()) {
        cout << "\nWelcome, " << user_name << endl;

        while (condition_loop == 'y' || condition_loop == 'Y') {

            cout << "\n--- MAIN MENU ---" << endl;
            cout << "1: Deposit money" << endl;
            cout << "2: Check balance" << endl;
            cout << "3: Withdraw money" << endl;
            cout << "0: Exit" << endl;
            cout << "Choose an option: ";
            cin >> option;

            switch (option) {
                case 1:
                    cout << "Amount to deposit: ";
                    cin >> amount;
                    actual_balance += amount;
                    cout << "Success! Deposited: $" << amount << endl;
                    break;

                case 2:
                    cout << "Current balance: $" << actual_balance << endl;
                    if (actual_balance == 0) cout << "Your account is empty" << endl;
                    break;

                case 3:
                    cout << "Amount to withdraw: ";
                    cin >> amount;

                    if (amount <= actual_balance) {
                        actual_balance -= amount;
                        cout << "Withdrawal successful, new balance: $" << actual_balance << endl;
                    } else {
                        cout << "Error: Insufficient funds. You only have $" << actual_balance << endl;
                    }
                    break;

                case 0:
                    condition_loop = 'n';
                    cout << "Exiting menu..." << endl;
                    break;

                default:
                    cout << "Invalid option. Try again." << endl;
            }

            if (option != 0) {
                cout << "\nDo you want to perform another operation? (y-yes/n-no): ";
                cin >> condition_loop;
            }
        }
    } else {
        cout << "Error: Name cannot be empty" << endl;
    }

    cout << "\nThank you for using our system. Goodbye!" << endl;
    return 0;
}
