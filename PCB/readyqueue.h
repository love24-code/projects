
/*
 * Assignment 1: Priority queue of Processes 
 * @file readyqueue.h
 * @author Denay Stokely 
 * @brief ReadyQueue is a queue of PCBs that are in the READY state to be scheduled to run. 
 * It should be a priority queue such that the process with the highest priority can be selected next. 
 * @version 0.1
 */


 #pragma once
 #include "pcb.h"
 #include <iostream>
 using namespace std; 
 /**
  * @brief A queue of PCB's that are in the READY state to be scheduled to run. 
  * It should be a priority queue such that the process with the highest priority can be selected next. 
  */
 class ReadyQueue {
    private: 
    struct Node {
        PCB* pcb; 
        Node* next;
    };
    Node* queue[51]; //priority queues 1..50
    int count;       //number of PCBs in the ready queue
public:
/**
 * @brief Construct a new Ready Queue object 
 * 
 */
ReadyQueue(); 

/**
 * @brief Destructor
 */
~ReadyQueue();

//You may add add additional member functions, but don't change the definitions of the following four member functions. 

/**
 * brief Add a PCB representing a process into the ready queue.
 * 
 * Inserts the PCB at the head of the linked list corresponding to its priority. 
 * The PCB's state is set to READY and the total count is incremented
 * 
 * @param pcbPtr: the pointer to the PCB to be added
 */
void addPCB(PCB* pcbPtr); 

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 * 
 * Scans from priority 50 down to 1, removes the first PCB found sets its state to RUNNING, decrements the count, and returns the PCB. 
 * 
 * @return int: the number of PCBs in the queue
 */
PCB* removePCB();

/**
 * @brief Returns the number of elements in the queue. 
 * 
 * @return int: the number of PCBs in the queue
 */
int size();

/**
 * @brief Display the PCBs in the queue.
 * 
 * Prints the ID and priority of each PCB in decending priority order.
 */
void displayAll();

 };
