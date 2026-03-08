#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
using namespace std;

// Function declarations
void menu();
void addPlayer(vector<string>& roster);
void removePlayer(vector<string>& roster);
void displayRoster(const vector<string>& roster);
void invalidChoice();

#endif
