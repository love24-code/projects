
#include <iostream> 
#include "readyqueue.h"

using namespace std; 





/**
 * @brief Constructor for the ReadyQueue class. 
 * Initializes an array of linked lists (queues) for each priority level (1-50).
 * Each entry is initially set to nullptr to indicate an empty queue. 
 * Initializes the count of PCBs in the queue to 0. 
 */
ReadyQueue::ReadyQueue() {
    for(int i = 0; i <= 50; i++){
        queue[i] = nullptr; 
        count = 0;
    }
}
/**
 * @brief Destructor 
 * 
 * Deletes all nodes in each priority-linked list to free memory. 
 * After deletion, all queues are set to nullptr and count is set to 0. 
 */
ReadyQueue::~ReadyQueue() {
    for(int i = 0; i <= 50; i++) {
        Node* cur = queue[i]; 
        while (cur) {
            Node* temp = cur;
            cur = cur->next; 
            delete temp;
        }
        queue[i] = nullptr;
    }
    count = 0;
}

/**
 * @brief Add a PCB representing a process into the ready queue. 
 * 
 * Inserts the PCB at the head of the linked list corresponding to its priority. 
 * The PCB's state is changed to READY, and the total count is incremented. 
 * 
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    int p = pcbPtr->getPriority(); 
    if(p < 1) p = 1;
    if(p > 50) p = 50;
    Node* node = new Node{pcbPtr, queue[p]};
    queue[p] = node; 
    pcbPtr->setState(ProcState::READY);
    count++;
}

/**
 * @brief Remove nad return teh PCB with the highest priority from the queue
 * 
 * The function scans the priority queues from 50 down to 1. 
 * It removes the first PCB found (highest priority) and changes its state to RUNNING. 
 * 
 * @return PCB*: the pointer to the PCB with the highest priority 
 */
PCB* ReadyQueue::removePCB() {
    for(int p = 50; p >= 1; p--) {
        if (queue[p]) {
            Node* node = queue[p]; 
            queue[p] = node->next; 
            PCB* pcb = node->pcb; 
            pcb->setState(ProcState::RUNNING);
            delete node; 
            count--; 
            return pcb;
        }
    }
    return nullptr; //empty queue

    //When removing a PCB from the queue, you must change its state to RUNNING.
}

/**
 * @brief Returns the number of elements in the queue.
 * 
 * @return int Number of elements in the ReadQueue
 */
int ReadyQueue::size() {
    return count; 
}

/**
 * @brief Display the PCBs in the queue. 
 * 
 * Prints the ID and priority of each PCB in descending priority order
 * Iretates through each linked list for priorities 50 down to 1. 
 */
void ReadyQueue:: displayAll() {
    cout << "ReadyQueue: " << endl; 
    for(int p = 50; p >= 1; p--) {
        Node* cur = queue[p]; 
        while(cur) {
            cout << "ID: " << cur->pcb->getID()
            << ", priotity: " <<cur->pcb->getPriority() << endl; 
            cur = cur->next; 
        }
    }
    cout <<endl; 
}
