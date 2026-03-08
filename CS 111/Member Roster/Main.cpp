#include <iostream>
#include <algorithm>
#include <limits> // for numeric_limits

using namespace std;

const int MAX_MEMBERS = 100; // Maximum number of members in the roster

// Helper to clear leftover input from stream
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Helper to find member index, returns -1 if not found
int findMember(const string roster[], int size, const string& name) {
    for (int i = 0; i < size; ++i) {
        if (roster[i] == name) {
            return i;
        }
    }
    return -1;
}

int main() {
    string roster[MAX_MEMBERS];
    int rosterSize = 0;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add member\n";
        cout << "2. Drop member\n";
        cout << "3. Show roster\n";
        cout << "4. Exit\n";

        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            clearInputBuffer();
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            continue;
        }

        clearInputBuffer(); // Always clear buffer after reading choice

        switch (choice) {
            case 1: { // Add member
                if (rosterSize >= MAX_MEMBERS) {
                    cout << "Roster is full. Cannot add more members.\n";
                    break;
                }

                string name;
                cout << "Enter the name of the member to add: ";
                getline(cin, name);

                if (name.empty()) {
                    cout << "Name cannot be empty.\n";
                    break;
                }

                if (findMember(roster, rosterSize, name) != -1) {
                    cout << "Member already exists.\n";
                } else {
                    roster[rosterSize++] = name;
                    sort(roster, roster + rosterSize);
                    cout << "Member added.\n";
                }
                break;
            }

            case 2: { // Drop member
                string name;
                cout << "Enter the name of the member to drop: ";
                getline(cin, name);

                if (name.empty()) {
                    cout << "Name cannot be empty.\n";
                    break;
                }

                int index = findMember(roster, rosterSize, name);
                if (index == -1) {
                    cout << "Member not found.\n";
                } else {
                    for (int i = index; i < rosterSize - 1; ++i) {
                        roster[i] = roster[i + 1];
                    }
                    --rosterSize;
                    cout << "Member dropped.\n";
                }
                break;
            }

            case 3: { // Show roster
                if (rosterSize == 0) {
                    cout << "Roster is empty.\n";
                } else {
                    cout << "\nRoster:\n";
                    for (int i = 0; i < rosterSize; ++i) {
                        cout << roster[i] << "\n";
                    }
                }
                break;
            }

            case 4: { // Exit
                cout << "Exiting program.\n";
                cout << "\nFinal Roster (Reversed Alphabetical Order):\n";
                for (int i = rosterSize - 1; i >= 0; --i) {
                    cout << roster[i] << "\n";
                }
                return 0;
            }

            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}
