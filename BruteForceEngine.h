#ifndef CPP_PROJECT_CION__BRUTEFORCEENGINE_H
#define CPP_PROJECT_CION__BRUTEFORCEENGINE_H


#include <string>
#include <atomic>

class BruteForceEngine {
private:
    int maxPassLength;
    std::atomic<long long> totalAttempts;
    std::atomic<bool> found;
    std::string foundPassword;

    void workerSearch(int startChar, int endChar, const std::string& targetPass);
    bool recursiveSearch(std::string current, const std::string& targetPass);

public:
    explicit BruteForceEngine(int length);
    void crackPassword(const std::string& targetPassword);
};


#endif //CPP_PROJECT_CION__BRUTEFORCEENGINE_H
