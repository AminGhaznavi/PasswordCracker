#include <iostream>
#include "UserDatabase.h"
#include "BruteForceEngine.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    UserDatabase db("users_db.txt");
    bool running = true;

    while (running) {
        cout << "\n=======================================" << endl;
        cout << "   High-Performance Password Cracker   " << endl;
        cout << "=======================================" << endl;
        cout << "1. Register New User\n";
        cout << "2. Start Brute-Force Attack\n";
        cout << "3. Delete User (Admin Only)\n";
        cout << "4. Exit\n";
        cout << "Select Option: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "[!] Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                string user, pass;
                cout << "\nEnter Username: ";
                cin >> user;

                if (db.userExists(user)) {
                    cout << "[!] Error: Username '" << user << "' already exists. Please choose a different name.\n";
                    break;
                }

                cout << "Enter Password (4 chars): ";
                cin >> pass;

                if (pass.length() != 4) {
                    cout << "[!] Error: Password length must be exactly 4 characters!\n";
                } else if (db.saveUser(user, pass)) {
                    cout << "[+] User registered successfully.\n";
                } else {
                    cout << "[!] File save error.\n";
                }
                break;
            }
            case 2: {
                string user;
                cout << "\nEnter Target Username: ";
                cin >> user;

                string targetPass = db.getPassword(user);
                if (targetPass.empty()) {
                    cout << "[!] User not found.\n";
                } else {
                    BruteForceEngine engine(targetPass.length());
                    engine.crackPassword(targetPass);
                }
                break;
            }
            case 3: {
                string adminPass, userToDelete;
                cout << "\nEnter Admin Password: ";
                cin >> adminPass;

                if (adminPass != "amin86") {
                    cout << "[!] Access Denied: Incorrect Admin Password!\n";
                    break;
                }

                cout << "Enter Username to Delete: ";
                cin >> userToDelete;

                if (db.deleteUser(userToDelete, adminPass)) {
                    cout << "[+] User '" << userToDelete << "' deleted successfully.\n";
                } else {
                    cout << "[!] Delete failed. User may not exist.\n";
                }
                break;
            }
            case 4:
                cout << "\nExiting application. Goodbye!\n";
                running = false;
                break;

            default:
                cout << "[!] Invalid option. Try again.\n";
                break;
        }
    }

    return 0;
}