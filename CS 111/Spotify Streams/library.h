#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Song {
    string credit;
    string title;
    string artist;
    string genre;
    int streams[10];  // FIXED: Changed from string[] to int[]
};

int menu();

void collect(istream& input, Song& s);
void collect_one(istream& input, Song& s);
void collect_all(istream& input, Song s[], int& n);

void display(Song s);
void display_one(Song s);
void display_all(const Song a[], int n);

unsigned songs_by_artist(const Song a[], int n, string artist);

#endif

