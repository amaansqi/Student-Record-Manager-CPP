#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

// Utility to split a CSV line
Student parseLine(const string& line) {
    stringstream ss(line);
    string token;
    Student s;

    getline(ss, token, ',');
    s.id = stoi(token);

    getline(ss, token, ',');
    s.name = token;

    getline(ss, token, ',');
    s.age = stoi(token);

    return s;
}

int getLastID() {
    ifstream file("data.txt");
    string line;
    int lastID = 0;
    while (getline(file, line)) {
        Student s = parseLine(line);
        lastID = s.id;
    }
    return lastID;
}

void writeData() {
    ofstream file("data.txt", ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string name;
    int age;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;

    int newID = getLastID() + 1;
    file << newID << "," << name << "," << age << endl;

    file.close();
    cout << "Data saved successfully with ID #" << newID << "\n";
}

void readData() {
    ifstream file("data.txt");
    if (!file) {
        cout << "No data found!\n";
        return;
    }

    string line;
    cout << "\n--- Student Records ---\n";
    cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(10) << "Age" << "\n";
    cout << "------------------------------------------\n";
    while (getline(file, line)) {
        Student s = parseLine(line);
        cout << left << setw(10) << s.id << setw(25) << s.name << setw(10) << s.age << "\n";
    }
    file.close();
}

void searchData() {
    ifstream file("data.txt");
    if (!file) {
        cout << "No data to search.\n";
        return;
    }

    string target;
    cout << "Enter student name to search: ";
    cin.ignore();
    getline(cin, target);

    string line;
    bool found = false;
    while (getline(file, line)) {
        Student s = parseLine(line);
        if (s.name == target) {
            cout << "Found: ID #" << s.id << " | Name: " << s.name << " | Age: " << s.age << "\n";
            found = true;
        }
    }
    if (!found) cout << "No student found with that name.\n";

    file.close();
}

void deleteData() {
    int delID;
    cout << "Enter student ID to delete: ";
    cin >> delID;

    ifstream file("data.txt");
    ofstream temp("temp.txt");

    string line;
    bool deleted = false;
    while (getline(file, line)) {
        Student s = parseLine(line);
        if (s.id != delID) {
            temp << line << endl;
        } else {
            deleted = true;
        }
    }

    file.close();
    temp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (deleted)
        cout << "Record deleted successfully.\n";
    else
        cout << "No record found with ID #" << delID << ".\n";
}

int main() {
    int choice;
    do {
        cout << "\n==== Student Record Manager ====\n";
        cout << "1. Add New Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search by Name\n";
        cout << "4. Delete by ID\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: writeData(); break;
            case 2: readData(); break;
            case 3: searchData(); break;
            case 4: deleteData(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
