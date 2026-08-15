#include "BruteForceEngine.h"
#include "SHA256.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

BruteForceEngine::BruteForceEngine(int length)
    : maxPassLength(length), totalAttempts(0), found(false), foundPassword("") {}

bool BruteForceEngine::recursiveSearch(string current, const string& targetPass) {
    if (found.load()) return true;

    if (current.length() == maxPassLength) {
        totalAttempts++;
        if (SHA256::hash(current) == targetPass) {
            foundPassword = current;
            found.store(true);
            return true;
        }
        return false;
    }

    for (int ascii = 32; ascii <= 126; ++ascii) {
        if (found.load()) return true;
        if (recursiveSearch(current + (char)ascii, targetPass)) {
            return true;
        }
    }
    return false;
}

void BruteForceEngine::workerSearch(int startChar, int endChar, const string& targetPass) {
    for (int ascii = startChar; ascii <= endChar; ++ascii) {
        if (found.load()) break;
        string firstChar(1, (char)ascii);
        recursiveSearch(firstChar, targetPass);
    }
}

void BruteForceEngine::crackPassword(const string& targetPassword) {
    totalAttempts = 0;
    found = false;
    foundPassword = "";

    unsigned int numThreads = thread::hardware_concurrency();
    if (numThreads == 0) numThreads = 4;

    cout << "\n[+] Starting Multi-threaded Brute-Force operation..." << endl;
    cout << "[+]Password length: " << maxPassLength << " Character" << endl;
    cout << "[+] Number of active cores (Threads): " << numThreads << endl;

    auto startTime = chrono::high_resolution_clock::now();

    vector<thread> threads;
    int asciiStart = 32;
    int asciiEnd = 126;
    int totalChars = asciiEnd - asciiStart + 1;
    int charsPerThread = totalChars / numThreads;

    for (unsigned int i = 0; i < numThreads; ++i) {
        int start = asciiStart + (i * charsPerThread);
        int end = (i == numThreads - 1) ? asciiEnd : (start + charsPerThread - 1);

        threads.emplace_back(&BruteForceEngine::workerSearch, this, start, end, targetPassword);
    }

    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = endTime - startTime;

    if (found.load()) {
        cout << "\n==========================================" << endl;
        cout << " [✓] The code has been discovered.: " << foundPassword << endl;
        cout << " [✓] Total efforts: " << totalAttempts.load() << endl;
        cout << " [✓] Time spent: " << fixed << setprecision(3) << duration.count() << " seconds" << endl;
        cout << " [✓] Processing speed: " << static_cast<long long>(totalAttempts.load() / duration.count()) << " guesses/sec" << endl;
        cout << "==========================================" << endl;
    } else {
        cout << "\n[✗] Password not found in this range." << endl;
    }
}