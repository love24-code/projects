#include <iostream>
#include <string>

using namespace std;

struct College {
  string name;
  int cost;
  int rate;
};

void display(const College a[], unsigned n);
int search(const College a[], unsigned n, string name, string category);
void sort_by_name(College a[], unsigned n);
void sort_by_cost(College a[], unsigned n);
void sort_by_rate(College a[], unsigned n);
