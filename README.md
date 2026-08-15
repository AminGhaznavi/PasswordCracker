# ⚡ High-Performance Multi-Threaded Password Cracker & Security Suite

A robust, multi-threaded C++17 password cracking engine and user management system integrated with **SHA-256 cryptographic hashing**. Built with a focus on core CPU optimization, concurrency safety, and scalable system design using **CMake**.

---

## 🔥 Key Features

* **🏎️ Multi-Threaded Brute-Force Engine:** Automatically detects native CPU hardware cores (`std::thread::hardware_concurrency`) and chunks the ASCII search space for maximum parallel execution.
* **🔒 SHA-256 Cryptographic Security:** Custom, zero-dependency C++ implementation of SHA-256 for secure password hashing and verification.
* **⚡ Atomic Concurrency:** Eliminates race conditions across worker threads using lock-free `std::atomic` state flags.
* **🛡️ Admin Security & Dashboard:** Privileged administrative portal with password protection (`amin86`) to list all registered users with their respective SHA-256 hashes or execute safe user eliminations.
* **🛑 Input & Registration Guard:** Built-in duplicate username prevention and UTF-8 cross-platform execution support.

---

## 🛠️ Built With

* **Language:** C++17
* **Build System:** CMake (v3.14+)
* **Hashing Algorithm:** SHA-256
* **Concurrency:** Standard Library Threading (`<thread>`, `<atomic>`)
* **IDE Recommended:** JetBrains CLion / VS Code

---

## 📁 Project Structure

```text
PasswordCracker/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── main.cpp
├── UserDatabase.h
├── UserDatabase.cpp
├── BruteForceEngine.h
├── BruteForceEngine.cpp
├── SHA256.h
└── SHA256.cpp
```

---

## 🚀 Getting Started

### Prerequisites
Ensure you have a C++17 compliant compiler installed (GCC, Clang, or MSVC) alongside CMake.

### Building & Execution

1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/YOUR_USERNAME/PasswordCracker.git](https://github.com/YOUR_USERNAME/PasswordCracker.git)
   cd PasswordCracker
   ```

2. **Configure & Build:**
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

3. **Run Application:**
   ```bash
   ./PasswordCracker
   ```

---

## 🌐 Vision & Roadmap (Upcoming Innovations)

We are actively evolving this tool into a full-fledged enterprise-grade security utility. Here is what is coming next:

- [x] **SHA-256 Cryptographic Integration** *(Completed)*
- [x] **Admin Dashboard & Database Auditing** *(Completed)*
- [ ] **🎨 Graphical User Interface (GUI):** Transitioning from CLI to a sleek, modern, desktop UI powered by **Qt** or **Dear ImGui** for real-time visualization of multi-core CPU cracking metrics and thread loads.
- [ ] **🌐 Centralized Network Database:** Migrating from local flat-file storage (`users_db.txt`) to a client-server architecture using **C++ Socket Programming** (TCP/IP) for global remote database synchronization.

---

## 📜 License

Distributed under the MIT License. Developed for educational and security research purposes.