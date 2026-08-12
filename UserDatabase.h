#ifndef CPP_PROJECT_CION__USERDATABASE_H
#define CPP_PROJECT_CION__USERDATABASE_H


#include <string>

class UserDatabase {
private:
    std::string filename;
    const std::string adminPassword = "amin86";

public:
    explicit UserDatabase(const std::string& dbFile);
    bool userExists(const std::string& username);
    bool saveUser(const std::string& username, const std::string& password);
    std::string getPassword(const std::string& username);
    bool deleteUser(const std::string& username, const std::string& inputAdminPass);
};


#endif //CPP_PROJECT_CION__USERDATABASE_H
