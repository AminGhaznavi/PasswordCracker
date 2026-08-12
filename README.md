# ⚡ High-Performance Multi-Threaded Password Cracker

A lightweight, multi-threaded C++ password cracking and user management system built with **C++17** and **CMake**. Designed for high throughput and optimal CPU core utilization.

---

## 🔥 Key Features

* **🏎️ Multi-Threaded Brute-Force Engine:** Automatically detects system CPU core count (`std::thread::hardware_concurrency`) and splits the ASCII search space across all available cores for maximum performance.
* **⚡ Atomic Concurrency:** Safe state management using `std::atomic` variables to eliminate data races and cleanly halt threads upon password discovery.
* **👤 User Database Management:** Local persistent user creation and password lookup.
* **🛑 Duplicate Username Prevention:** Rejects duplicate user registrations to ensure database integrity.
* **🛡️ Admin Security:** Restricted user deletion requiring administrator authorization.
* **🌐 Cross-Platform Encoding:** Full UTF-8 support for consistent console execution across Windows and Linux environments.

---

## 🛠️ Built With

* **Language:** C++17
* **Build System:** CMake (v3.14+)
* **Threading:** Standard Library Threads (`<thread>`, `<atomic>`)
* **IDE Recommended:** JetBrains CLion / VS Code

---

## 📁 Project Structure

```
PasswordCracker/
├── CMakeLists.txt
├── README.md
└── src/
    ├── main.cpp
    ├── UserDatabase.h
    ├── UserDatabase.cpp
    ├── BruteForceEngine.h
    └── BruteForceEngine.cpp
```

---

## 🚀 Getting Started

### Prerequisites
Make sure you have a C++17 compliant compiler installed (GCC, Clang, or MSVC) alongside CMake.

### Building and Running

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/YOUR_USERNAME/PasswordCracker.git](https://github.com/YOUR_USERNAME/PasswordCracker.git)
   cd PasswordCracker
   ```

2. **Configure and Build:**
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

3. **Run the Application:**
   ```bash
   ./PasswordCracker
   ```

---

## 🗺️ Roadmap (Upcoming Features)

We are actively developing and enhancing this project! The following features are scheduled for integration:

- [ ] **🔒 SHA-256 Hashing Integration:** Upgrade password storage from plain text to secure SHA-256 cryptographic hashes.
- [ ] **📋 Admin Dashboard - View All Users:** Allow authenticated admins to view the full registered user directory.
- [ ] **🌐 Centralized Network Database:** Transition from local text storage (`users_db.txt`) to a centralized cloud/server model using Socket Programming or REST APIs so all clients access a shared database worldwide.

---

## 📜 License

Distributed under the MIT License. Feel free to modify and adapt for educational purposes.
