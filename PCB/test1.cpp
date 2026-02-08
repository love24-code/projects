
/**
 * Assignment 1: queue of processes
 * @file test1.cpp
 * author: Denay Stokely 
 * @brief This file tests the correctness of your implementation of the readyQueue and pcbtable
 * 
 * 
 * 
 * Test1 performs a series of operations
 * 1. Creates a PCBTable of 50 processes with IDs and priorities from 1 to 50. 
 * 2. Adds selected processes to the ReadyQueue in arbitrary order. 
 * 3. removes the highest-priority process and displays the queue.
 * 4. Repeats additions and removals to test priority ordering. 
 * 5. Finally, removes all remaining processes one by one and displays their information. 
 * 
 * This test ensures that they ReadQueue correctly maintainsprocess priority and updates PCB states 
 */

 #include <iostream> 
 #include "readyqueue.h"
 #include "pcbtable.h"

 using namespace std; 

 int main(int argc, char* argv[]){
    //header information
    cout <<"CS 433 Programming assignment 1" <<endl; 
    cout << "course: CS433 (Operating Systems)" <<endl; 
    cout << "Discription: Program to implement a priority ready queue of processes" <<endl; 
    cout << "************Performing Test 1********************"<<endl; 
    cout << "================================="<< endl; 

    //Create ReadyQueue and PCBTable 
    ReadyQueue q1; 
    PCBTable table; 

    for (int i = 1; i <= 50; i++){
        //Initialize PCBTable with 50 PCBs
        //Add a new PCB with id = i, priority = i to the tableat index i 
        table.addNewPCB(i, i, i);
    }

    cout << "Add process 15, 6, 23, 39, 8 to q1. Display the content of q1" <<endl; 

    //Add processes 115, 6, 23, 39, and 8 to readyQueue in arbitrary order
    //to test that removePCB always return the highest-priority process
    q1.addPCB(table.getPCB(15));
    q1.addPCB(table.getPCB(6)); 
    q1.addPCB(table.getPCB(23)); 
    q1.addPCB(table.getPCB(39));
    q1.addPCB(table.getPCB(8)); 
    q1.displayAll(); 

    //Remove the highest-priority process and display the queue
    cout << "Remove the process with the highest priority from q1 and display q1." <<endl; 
    PCB* p = q1.removePCB(); 
    q1.displayAll();
    //Add processes 47, 1, 37, and  5 to the ReadyQueue
    cout <<"Add processes 47, 1, 37, and 5 into q1 and display q1" <<endl; 
    q1.addPCB(table.getPCB(47)); 
    q1.addPCB(table.getPCB(1)); 
    q1.addPCB(table.getPCB(37)); 
    q1.addPCB(table.getPCB(5)); 
    q1.displayAll();

    //Remove the highest-priority process again and display the queue
    cout << "Remove the process with the highest priority from q1 and display q1." <<endl; 
    p = q1.removePCB(); 
    q1.displayAll();

    //Add processes 47, 17, 39, 12, and 19 to the ReadyQueue
    cout << "Insert processes 47, 17, 39, 12 and 19 to q1 and display q1. " << endl; 
    q1.addPCB(table.getPCB(47)); 
    q1.addPCB(table.getPCB(17)); 
    q1.addPCB(table.getPCB(39)); 
    q1.addPCB(table.getPCB(12)); 
    q1.addPCB(table.getPCB(19)); 
    q1.displayAll();

    //remove all remaining processes one by one and display them 
    cout << "One by one remove the process with the highest-priority from the queue q1" <<endl; 
    while(q1.size() > 0)
    {
        p = q1.removePCB(); 
        p->display(); 
        //Display the ID, priority, and state of the removed process
    }
    return 0;
 }
