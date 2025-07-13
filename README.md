# Student Record Manager (C++ File Handling Project)

This is a console-based C++ application that allows users to manage student records using file handling. The project demonstrates key file I/O operations such as writing to a file, reading from a file, searching records, and deleting records — all with a user-friendly menu system.

## 🚀 Features

- 📥 Add new student data with **auto-generated unique ID**
- 📋 Display all student records in a **formatted table**
- 🔍 Search for a student by **name**
- ❌ Delete a student record using their **ID**
- 🧾 Data stored persistently in `data.txt`

## 🛠 Technologies Used

- **C++** for logic and file handling
- **File Streams** (`fstream`) for reading/writing files
- **Standard I/O** for user interaction

## 📂 Files in this Repository

- `student_manager.cpp` – Main source code for the project
- `README.md` – Project documentation (you’re reading it)
- `data.txt` – Automatically created during execution to store records

## 💻 How to Run

### 🧱 Prerequisites

Ensure you have a C++ compiler installed:
- GCC (Linux/Windows via MinGW)
- Code::Blocks, Dev-C++, or any IDE with C++ support

### 🔧 Compilation and Execution

**Using terminal/command prompt:**

```bash
g++ -o student_manager student_manager.cpp
./student_manager
