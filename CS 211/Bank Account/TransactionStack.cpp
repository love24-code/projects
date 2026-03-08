#include "TransactionStack.h"

TransactionStack:: TransactionStack(){
  top_=nullptr;
}

void TransactionStack::push(const string&transaction_type, double amount){
  Transaction *newTransaction = new Transaction;
  newTransaction->transaction_type = transaction_type;
  newTransaction->amount = amount;
  newTransaction->under = top_;
  top_ = newTransaction;
}

TransactionStack:: ~TransactionStack(){
  while(this->top_ != nullptr){
    Transaction* temp = this->top_;
    this-> top_ = this->top_->under;
    delete temp;
  }
}

Transaction* TransactionStack::top() const{
  return top_;
}

void TransactionStack::pop(){
  if(!top_){
    return;
  }
  Transaction* temp = top_;

  top_ = top_ ->under;
    delete temp;
}

void TransactionStack::clear(){
    while(top_){
        pop();
    }
}

ostream& operator<<(ostream& out, const TransactionStack& obj){
    Transaction* ptr = obj.top_;
    while(ptr){
        out << ptr->transaction_type << " " << ptr->amount << endl;
        ptr = ptr->under;
    }
    return out;
}

