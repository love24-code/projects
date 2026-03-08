#include "library.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
string filename;

int main() {
    ifstream fin("input.dat");
    if (!fin.is_open()) {
        cerr << "Cannot open input.dat\n";
        return 1;
    }

    Couples couples[20];
    int n = 0;

    while (fin && n < 20) {
        collect(fin, couples[n]);
        n++;
    }

    for (int i = 0; i < n; ++i) {
        display(couples[i]);
    }

    fin.close();
    return 0;
}
