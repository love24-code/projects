//DO NOT CHANGE THIS FILE
#include "Account.h"
#include "TransactionStack.h"
#include <iomanip>
using namespace std;

//This constrcutor creates an Account object using the provided name.
//The initial balance for a new account is set to $0.
Account::Account(const string& name) {
  this->name_ = name;
  this->balance_ = 0;

}

//This function returns true if an amount is appropriate for a deposit request.
bool Account::valid_deposit(double amount) const {
  return amount > 0;
}

//This function returns true if an amount is apporiate for a withdraw request.
bool Account::valid_withdraw(double amount) const {
  return amount > 0 && amount <= this->balance_;
}

//This function makes a deposit to the invoking Account object.
//It assumes that the deposit_amount is valid.
Account& Account::operator+=(double deposit_amount) {
  this->balance_ += deposit_amount;
  return *this;
}

//This function makes a withdrawal from the invoking Account object.
//It assumes that the withdrawal_amount is valid.
Account& Account::operator-=(double withdrawal_amount) {
  this->balance_ -= withdrawal_amount;
  return *this;
}

//This function displays the name and balance of an account.
ostream& operator<<(ostream& output, const Account& a) {
  output << fixed << showpoint << setprecision(2);
  output << a.name_ << ", your balance is $" << a.balance_ << ".";
  return output;
}

bool Account :: make_withdraw(double amount, TransactionStack& undo_stack, TransactionStack& redo_stack){
  if(!valid_withdraw(amount)){
  cout<< "Invalid withdrawl amount"<< endl;
  return false;
  }
  *this -= amount;
  undo_stack.push("withdraw", amount);
  redo_stack.clear();
  return true;
}
bool Account::make_deposit(double amount, TransactionStack& undo_stack, TransactionStack& redo_stack) {
    if (!valid_deposit(amount)) {
        cout << "Invalid deposit amount" << endl;
        return false;
    }
    *this += amount;            // increase balance
    undo_stack.push("deposit", amount);
    redo_stack.~TransactionStack(); // clear redo stack
    return true;
}

void Account::undo(TransactionStack& undo_stack, TransactionStack& redo_stack){
    Transaction* t = undo_stack.top();
    if(t == nullptr){
        cout << "No transactions to undo." << endl;
        return;
    }

    if(t->transaction_type == "deposit"){
        *this -= t->amount;
        redo_stack.push("deposit", t->amount);
    } else if(t->transaction_type == "withdraw"){
        *this += t->amount;
        redo_stack.push("withdraw", t->amount);
    }

    undo_stack.pop();
}

void Account::redo(TransactionStack &undo_stack, TransactionStack &redo_stack) {
    Transaction* t = redo_stack.top();
    if(!t) return;

    if(t->transaction_type == "deposit"){
        *this += t->amount;
        undo_stack.push("deposit", t->amount);
    } else if(t->transaction_type == "withdraw"){
        *this -= t->amount;
        undo_stack.push("withdraw", t->amount);
    }

    redo_stack.pop();
}

