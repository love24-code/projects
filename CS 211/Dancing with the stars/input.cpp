#include "library.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>


using namespace std;

void collect(ifstream& fin, Couples& c) {
    string line;
    if (!getline(fin, line)) return;  // end of file

    stringstream ss(line);
    string temp;

    // Read partners
    getline(ss, c.partner1, ',');
    getline(ss, c.partner2, ',');

    c.num_weeks = 0;
    // Read up to 9 week scores
    while (getline(ss, temp, ',') && c.num_weeks < 9) {
        try {
            c.week_scores[c.num_weeks] = stoi(temp);
            c.num_weeks++;
        } catch (...) {
            break;  // reached "Eliminated" or invalid entry
        }
    }
}
void display(const Couples& c) {
    cout << left;
    cout << setw(20) << c.partner1;
    cout << setw(20) << c.partner2;

    for (int i = 0; i < c.num_weeks; ++i) {
        cout << setw(6) << c.week_scores[i];
    }
    cout << endl;
}

void collect_song (ifstream& input, Song_and_Dance& c);

void display(Couples c) {
    cout << left;
    cout << setw(20) << c.partner1 << "\t";
    cout << setw(20) << c.partner2 << "\t";

    for (int i = 0; i < 9; ++i) {
        cout << setw(3) << c.week_scores[i] << "\t";
    }
    cout << endl;
}
