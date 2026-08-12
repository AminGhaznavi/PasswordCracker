#include "UserDatabase.h"
#include <fstream>
#include <cstdio>

using namespace std;

UserDatabase::UserDatabase(const string& dbFile) : filename(dbFile) {}

bool UserDatabase::userExists(const string& username) {
    ifstream inFile(filename);
    string user, pass;
    if (inFile.is_open()) {
        while (inFile >> user >> pass) {
            if (user == username) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
    }
    return false;
}

bool UserDatabase::saveUser(const string& username, const string& password) {
    if (userExists(username)) {
        return false;
    }

    ofstream outFile(filename, ios::app);
    if (!outFile.is_open()) return false;

    outFile << username << " " << password << "\n";
    outFile.close();
    return true;
}

string UserDatabase::getPassword(const string& username) {
    ifstream inFile(filename);
    string user, pass;
    if (inFile.is_open()) {
        while (inFile >> user >> pass) {
            if (user == username) {
                inFile.close();
                return pass;
            }
        }
        inFile.close();
    }
    return "";
}

bool UserDatabase::deleteUser(const string& username, const string& inputAdminPass) {
    if (inputAdminPass != adminPassword) {
        return false;
    }

    if (!userExists(username)) {
        return false;
    }

    ifstream inFile(filename);
    ofstream tempFile("temp_db.txt");

    string user, pass;
    bool deleted = false;

    if (inFile.is_open() && tempFile.is_open()) {
        while (inFile >> user >> pass) {
            if (user == username) {
                deleted = true;
                continue;
            }
            tempFile << user << " " << pass << "\n";
        }
        inFile.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp_db.txt", filename.c_str());
    }

    return deleted;
}