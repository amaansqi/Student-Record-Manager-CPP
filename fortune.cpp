#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string fortuneFile = "fortunes.txt";

void addFortune() {
    ofstream file(fortuneFile, ios::app);
    if (!file) {
        cout << "Error opening fortune file.\n";
        return;
    }

    cin.ignore();
    string newFortune;
    cout << "Write a new fortune to add:\n> ";
    getline(cin, newFortune);

    file << newFortune << endl;
    file.close();

    cout << "Fortune added successfully!\n";
}

void getRandomFortune() {
    ifstream file(fortuneFile);
    if (!file) {
        cout << "No fortunes available. Add some first!\n";
        return;
    }

    vector<string> fortunes;
    string line;
    while (getline(file, line)) {
        if (!line.empty())
            fortunes.push_back(line);
    }
    file.close();

    if (fortunes.empty()) {
        cout << "No fortunes found.\n";
        return;
    }

    srand(time(0));
    int index = rand() % fortunes.size();

    cout << "\nYour Fortune:\n";
    cout << "------------------------------\n";
    cout << fortunes[index] << "\n";
    cout << "------------------------------\n";
}

void showAllFortunes() {
    ifstream file(fortuneFile);
    if (!file) {
        cout << "No fortunes found.\n";
        return;
    }

    string line;
    cout << "\nAll Saved Fortunes:\n";
    cout << "------------------------------\n";
    while (getline(file, line)) {
        if (!line.empty())
            cout << "- " << line << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\nFortune Cookie App\n";
        cout << "1. Get a Random Fortune\n";
        cout << "2. Add a New Fortune\n";
        cout << "3. Show All Fortunes\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: getRandomFortune(); break;
            case 2: addFortune(); break;
            case 3: showAllFortunes(); break;
            case 4: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
