#include "library.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Enter a file name: " << endl;
  string file_name;
  cin >> file_name;

  ifstream input(file_name);
  if (!input.is_open()) {
    cout << "File could not be opened. \n";
    return 1;
  }

  processFile(input);

  input.close();
  return 0;
}

