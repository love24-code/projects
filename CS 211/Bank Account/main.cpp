#include <iostream> 
#include <fstream>
#include "TransactionStack.h"
#include "Account.h"

using namespace std;



int main() {
    TransactionStack stack;
    Transaction newTransaction;

    Account account("Christian Troy Jackson");
    TransactionStack undo_stack;
    TransactionStack redo_stack;

    ifstream fin("transactions.dat");
    if (!fin.is_open()){
        cout << "File not found" << endl;
    } else {
        cout << account << endl;

        string transaction_type;
        double amount;

        while(fin >> transaction_type){
            if(transaction_type == "deposit" || transaction_type == "withdraw"){
                fin >> amount;
            }

            if(transaction_type == "deposit"){
                cout << "After processing deposit " << amount << ": ";
                if(account.make_deposit(amount, undo_stack, redo_stack)){
                    cout << account << endl;
                }
            }
            else if(transaction_type == "withdraw"){
                cout << "After processing withdraw " << amount << ": ";
                if(account.make_withdraw(amount, undo_stack, redo_stack)){
                    cout << account << endl;
                }
            }
            else if(transaction_type == "undo"){
                account.undo(undo_stack, redo_stack);
            }
            else if(transaction_type == "redo"){
                account.redo(undo_stack, redo_stack);
            }
        }

        cout << account << endl; // final account status
    } // <-- closes else
    fin.close();
    return 0;
} // <-- closes main
