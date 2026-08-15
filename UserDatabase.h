#ifndef USER_DATABASE_H
#define USER_DATABASE_H

#include <string>

class UserDatabase {
private:
    std::string filename;
    const std::string adminPassword = "amin86";

public:
    explicit UserDatabase(const std::string& dbFile);
    bool userExists(const std::string& username);
    bool saveUser(const std::string& username, const std::string& plainPassword);
    std::string getPasswordHash(const std::string& username);
    bool deleteUser(const std::string& username, const std::string& inputAdminPass);
    void listUsers(const std::string& inputAdminPass);
};

#endif // USER_DATABASE_H