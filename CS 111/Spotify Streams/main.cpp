#include <iostream>
#include <fstream>
#include "library.h"

using namespace std;

int main() {
    Song songs[10];
    int num_songs = 0;
    ifstream input("input.dat");

    if (!input.is_open()) {
        cerr << "Could not open input.dat\n";
        return 1;
    }

    collect_all(input, songs, num_songs);
    input.close();

    int choice = menu();

    switch (choice) {
        case 1:
            cout << "\n--- Songs by Artist ---\n";
            display_all(songs, num_songs);
            break;
        case 2:
            cout << "\n--- Songs by Genre ---\n";
            display_all(songs, num_songs);
            break;
        case 3:
            cout << "\n--- Songs by Streams ---\n";
            display_all(songs, num_songs);
            break;
        case 4:
            cout << "\n--- Overall ---\n";
            display_all(songs, num_songs);
            break;
        
        default:
            cout << "Invalid menu option.\n";
            break;
    }

    return 0;
}

