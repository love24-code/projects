#include <iostream>
#include <vector>
#include "library.h"
using namespace std;

int main() {
    vector<string> roster;
    int choice;

    while (true) {
        menu();
        cin >> choice;
        cin.ignore(); // clear newline from buffer

        if (choice == 1) {
            addPlayer(roster);
        }
        else if (choice == 2) {
            removePlayer(roster);
        }
        else if (choice == 3) {
            displayRoster(roster);
        }
        else if (choice == 4) {
            cout << "Thank you for using the program.\n";
            displayRoster(roster);
            break;
        }
        else {
            invalidChoice();
        }
    }

    return 0;
}
