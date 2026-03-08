#include "library.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <fstream>


using namespace std;


void display(const College a[], unsigned n){
  int largest = 0;
  int smallest = 0;
  double total_cost = 0;
  cout<< setw(40) << left << "Name" << setw(10) << right<< "Cost" << setw(10) << "Acceptance Rate"<< endl;

  cout<< "==================================================================================================================================================" << endl;
for(unsigned i =0; i < n; i++){
  cout<< left<< setw(40) << a[i].name << setw(10) << right<< a[i].cost << setw(10)<<a[i].rate<< "%"<< endl;
if( a[i].cost > a[largest].cost){
  largest = i;
}
  if( a[i].cost < a[smallest].cost){
  smallest = i;
}
  total_cost += a[i].cost;
}
 total_cost = total_cost / n;
  cout<< "=================================================================================================================================================="<<endl;

cout<< "The most expensive college is: "<< a[largest].name << " with a cost of $"<< a[largest].cost << endl;

 cout<< "The least expensive college is: "<< a[smallest].name << " with a cost of $"<< endl;
  cout<< "The average cost of college is: $"<< fixed<< setprecision(2)<<total_cost << endl;
  
}



int search(const College a[], unsigned n, string name, string category){
int i = 0;
  for(i = 0; i < n; i++){
    if(a[i].name == name){
      break;
    }
    if(i ==n){
      return -1;
    }
    if (category != "cost" && category != "rate"){
      return -2;
      
    }
    if(category == "cost"){
      return a[i].cost;
    }
    else if(category == "rate"){
      return a[i].rate;
    }
    return -3;
  }
  return 0;
}
  void sort_by_name(College a[], unsigned n) {
    for (int j = n - 1; j > 0; j--) {
        for (int i = 0; i < j; i++) {
            if (a[i].name > a[i + 1].name) {
                swap(a[i], a[i + 1]); // swap the whole College struct
            }
        }
    }
}

void sort_by_cost(College a[], unsigned n){
  for (int j = 0; j <n-1; j++){
    int min_index = j;
    for(int i = j+1; i < n; i++){
      if (a[i].cost > a[min_index].cost){
        min_index = i;
      }
    }
    swap(a[j],a[min_index]);
  }
}

