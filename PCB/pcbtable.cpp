
/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author ??? (TODO: your name)
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * The table is initalized to hold 'size' PCB pointers, all set to nullptr initially
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
   table.resize(size, nullptr);
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 * Deletes all PCB objects stored in the table to free memory and prevent memory leaks. 
 */
PCBTable::~PCBTable() {
   for (PCB* p : table)
      delete p;
   // Delete all the PCBs in the table
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx", or nullptr if index is invalid 
 */
PCB* PCBTable::getPCB(unsigned int idx) {
    if(idx >= table.size())
    return nullptr;
    return table[idx];
}

/**
 * @brief Add a PCB pointer to the PCBTable at index idx.
 *
 * If the index is valid, stores the PCB pointer at the given index.
 * If there is already a PCB at that index, it is replaced. 
 * @param pcb: the PCB to add
 * @param idx Index in the table where the PCB should be stored.
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
    if(idx >= table.size())
      return;
   table[idx] = pcb;
    // Add a PCB pointer to the PCBTable at index idx.
}
