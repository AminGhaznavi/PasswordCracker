#include "UserDatabase.h"
#include "SHA256.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

UserDatabase::UserDatabase(const string& dbFile) : filename(dbFile) {}

bool UserDatabase::userExists(const string& username) {
    ifstream inFile(filename);
    string user, hashVal;
    if (inFile.is_open()) {
        while (inFile >> user >> hashVal) {
            if (user == username) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
    }
    return false;
}

bool UserDatabase::saveUser(const string& username, const string& plainPassword) {
    if (userExists(username)) return false;

    ofstream outFile(filename, ios::app);
    if (!outFile.is_open()) return false;

    // تبدیل رمز عبور ساده به هش SHA-256 قبل از ذخیره
    string hashedPassword = SHA256::hash(plainPassword);

    outFile << username << " " << hashedPassword << "\n";
    outFile.close();
    return true;
}

string UserDatabase::getPasswordHash(const string& username) {
    ifstream inFile(filename);
    string user, hashVal;
    if (inFile.is_open()) {
        while (inFile >> user >> hashVal) {
            if (user == username) {
                inFile.close();
                return hashVal;
            }
        }
        inFile.close();
    }
    return "";
}

bool UserDatabase::deleteUser(const string& username, const string& inputAdminPass) {
    if (inputAdminPass != adminPassword) return false;
    if (!userExists(username)) return false;

    ifstream inFile(filename);
    ofstream tempFile("temp_db.txt");

    string user, hashVal;
    bool deleted = false;

    if (inFile.is_open() && tempFile.is_open()) {
        while (inFile >> user >> hashVal) {
            if (user == username) {
                deleted = true;
                continue;
            }
            tempFile << user << " " << hashVal << "\n";
        }
        inFile.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp_db.txt", filename.c_str());
    }

    return deleted;
}

void UserDatabase::listUsers(const string& inputAdminPass) {
    if (inputAdminPass != adminPassword) {
        cout << "[!] Access Denied: Incorrect Admin Password!\n";
        return;
    }

    ifstream inFile(filename);
    string user, hashVal;
    int count = 0;

    cout << "\n=======================================================================\n";
    cout << "                     REGISTERED USERS DIRECTORY                        \n";
    cout << "=======================================================================\n";
    cout << left << setw(15) << "Username" << " | " << "Password Hash (SHA-256)" << endl;
    cout << "-----------------------------------------------------------------------\n";

    if (inFile.is_open()) {
        while (inFile >> user >> hashVal) {
            cout << left << setw(15) << user << " | " << hashVal << endl;
            count++;
        }
        inFile.close();
    }

    if (count == 0) {
        cout << "[!] No users found in database.\n";
    } else {
        cout << "-----------------------------------------------------------------------\n";
        cout << "Total Users: " << count << endl;
    }
    cout << "=======================================================================\n";
}