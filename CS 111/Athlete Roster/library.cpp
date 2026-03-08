#include "library.h"
#include <iostream>
using namespace std;

void menu() {
    cout << "MENU\n";
    cout << "1 - Add a member\n";
    cout << "2 - Remove a member\n";
    cout << "3 - Show the roster\n";
    cout << "4 - Done Building roster\n";
}

void addPlayer(vector<string>& roster) {
    string name;
    cout << "Enter the name to add: ";
    getline(cin, name);
    roster.push_back(name);
    cout << name << " added.\n";
}

void removePlayer(vector<string>& roster) {
    string name;
    cout << "Enter the name to remove: ";
    getline(cin, name);
    for (size_t i = 0; i < roster.size(); i++) {
        if (roster[i] == name) {
            roster.erase(roster.begin() + i);
            cout << name << " removed.\n";
            return;
        }
    }
    cout << name << " not found in roster.\n";
}

void displayRoster(const vector<string>& roster) {
    cout << "Roster:\n";
    for (size_t i = 0; i < roster.size(); i++) {
        cout << i + 1 << ". " << roster[i] << "\n";
    }
}

void invalidChoice() {
    cout << "Please enter a valid choice.\n";
}
