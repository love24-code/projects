#include "library.h"

int menu() {
    int choice;
    cout << "MENU\n";
    cout << "1. Display songs by artist\n";
    cout << "2. Display songs by genre\n";
    cout << "3. Display songs by streams\n";
    cout << "4. Overall\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // remove leftover newline
    return choice;
}

void collect(istream& input, Song& s) {
    getline(input, s.credit, ' ');
    getline(input, s.title, ',');
    getline(input, s.artist, ',');
    for (int i = 0; i < 10; ++i) {
        input >> s.streams[i];
    }
    input.ignore(); // skip to next line
}

void collect_one(istream& input, Song& s) {
    getline(input, s.title, ',');
    getline(input, s.artist, ',');
    getline(input, s.genre, ',');
    for (int i = 0; i < 10; ++i) {
        input >> s.streams[i];
    }
    input.ignore(); // skip newline
}

void collect_all(istream& input, Song s[], int& n) {
    n = 0;
    while (input && n < 10) {
        collect_one(input, s[n]);
        n++;
    }
}

void display(Song s) {
    cout << s.title << "\n" << s.artist << "\n" << s.genre << endl;
    for (int i = 0; i < 10; ++i) {
        cout << setw(5) << s.streams[i];
        if (i == 4 || i == 9) cout << endl;
    }
}

void display_one(Song s) {
    display(s);
    cout << endl;
}

void display_all(const Song a[], int n) {
    for (int i = 0; i < n; ++i) {
        display_one(a[i]);
    }
}

unsigned songs_by_artist(const Song a[], int n, string artist) {
    unsigned count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].artist == artist) {
            count++;
        }
    }
    return count;
}

