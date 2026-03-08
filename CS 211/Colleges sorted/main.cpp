#include "library.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
  const int SIZE = 10;
  int i= 0;
  ifstream fin;
  College e;
  College a[SIZE];
  fin.open("California.csv");
  if(!fin.is_open()){
    cout << "File not found" << endl;
  }
  else{
    cout<< "File is open successfully" << endl;
  }
  string test;
getline(fin, e.name, ',');
  fin >> e.cost;
  fin.ignore();
  fin >> e.rate;
  fin.ignore();
  a[i] = e;
  i++;
  while (!fin.eof()){
    getline(fin, e.name, ',');
    fin >> e.cost;
    fin.ignore();
    fin >> e.rate;
    fin.ignore();
    a[i] = e;
    i++;
    cout << endl;
  }

  fin.close();

  display(a,i);

  cout << "The acceptance rate of Univeristy of California Los Angeles is "<< endl;
  cout<< search(a, i, "University of California Los Angeles", "cost") << "%"<<endl;

  cout << "The acceptance rate of University of California San Diego is: $"<< endl;
  cout<< search(a, i, "University of California San Diego", "rate") << "%"<<endl;

sort_by_name(a,i);
  display(a, i);
 sort_by_cost(a,i);
  display(a, i);
 sort_by_rate(a,i);
  display(a, i);
  
  return 0;
}

