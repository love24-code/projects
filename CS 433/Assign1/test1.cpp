
/**
 * Assignment 1: priority queue of processes
 * @file test1.cpp
 * @author
 * @brief This file tests the correctness of your implementation of the readyqueue and pcbtable
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 *
 * Test1 performs a series of operations
 * 1. Creates a PCBTable of 50 processes with IDs and priorities from 1 to 50. 
 * 2. Adds selected processes to the ReadQueue in arbitrary order. 
 * 3. Removes the highest-priority process and displays the queue.
 * 4. Repeats additions and removals to test priority ordering. 
 * 5. Finally, removes all remaining processes one by one and displays their information.
 * 
 * This test ensures that the ReadQueue correctly maintains process priority and updates PCB states. 
 */

#include <iostream>
#include "readyqueue.h"
#include "pcbtable.h"

using namespace std;

int main(int argc, char* argv[]) {
    //header information
    std::cout << "CS 433 Programming assignment 1" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : Program to implement a priority ready queue of processes" << std::endl;
    std::cout << "************Performing Test 1********************" << std::endl;
    std::cout << "=================================" << std::endl;

//Create ReadyQueue and PCBTable 
    ReadyQueue q1;
    PCBTable table;

    for (int i = 1; i <= 50; i++) {
       //Initalize PCBTable with 50 PCBs
       // Add a new PCB with id = i, priority = i to the table at index i
        table.addNewPCB(i, i, i);
    }

    std::cout << "Add process 15, 6, 23, 39 and 8 to q1. Display the content of q1" << std::endl;
   
    //Add processes 15, 6, 23, 39, and 8 to ReadyQueue in arbitrary order
    // To test that removePCB always returns the highest-priority process
    q1.addPCB(table.getPCB(15));
    q1.addPCB(table.getPCB(6));
    q1.addPCB(table.getPCB(23));
    q1.addPCB(table.getPCB(39));
    q1.addPCB(table.getPCB(8));
    q1.displayAll();

// Remove the highest-priority process and display the queue
    std::cout << "remove the process with the highest priority from q1 and display q1." << std::endl;
    PCB* p = q1.removePCB();
    q1.displayAll();
//Add processes 47, 1, 37, and 5 to the ReadyQueue
    std::cout << "add processes 47, 1, 37 and 5 into q1 and display q1" << std::endl;
    q1.addPCB(table.getPCB(47));
    q1.addPCB(table.getPCB(1));
    q1.addPCB(table.getPCB(37));
    q1.addPCB(table.getPCB(5));
    q1.displayAll();
    
    //Remove the highest-priority process again and display the queue
    std::cout << "remove the process with the highest priority from q1 and display q1." << std::endl;
    p = q1.removePCB();
    q1.displayAll();
    
//Add processes 47, 17, 39, 12, and 19 to the ReadyQueue
    std::cout << "Insert processes 47, 17, 39, 12 and 19  to q1 and display q1." << std::endl;
    q1.addPCB(table.getPCB(47));
    q1.addPCB(table.getPCB(17));
    q1.addPCB(table.getPCB(39));
    q1.addPCB(table.getPCB(12));
    q1.addPCB(table.getPCB(19));
    q1.displayAll();
    
//Remove all remaining processes one by one and display them 
    std::cout << "One by one remove the process with the highest priority from the queue q1" << std::endl;
    while(q1.size() > 0)
    {
        p = q1.removePCB();
        p->display();
        //Display the ID, priority, and state of the removed process
    }
    return 0;
}



