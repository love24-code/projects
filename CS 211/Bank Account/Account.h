//DO NOT CHANGE THIS FILE
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "TransactionStack.h"
#include <iostream>
using namespace std;

class Account {
  private:
    string name_;
    double balance_;
  public:
    Account(const string&);
    bool valid_deposit(double) const;
    bool valid_withdraw(double) const;
    Account& operator+=(double);
    Account& operator-=(double);
    friend ostream& operator<<(ostream&, const Account&);
    bool make_withdraw(double, TransactionStack&, TransactionStack&);
    bool make_deposit(double, TransactionStack&, TransactionStack&);
    void undo(TransactionStack&, TransactionStack&);
    void redo(TransactionStack&, TransactionStack&);


};

#endif

