
/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author ??? (TODO: your name)
 * @brief This is the header file for the PCBTable class, an array(list) of all PCB elements in the system..
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#pragma once
#include <vector>
#include "pcb.h"

/**
 * @brief PCTable is an array of all PCB's in the system
 * 
 */
class PCBTable {
private:
std::vector<PCB*> table;
    // choose a data structure for the PCBTable. 
    // You can use an array of PCB pointers, e.g. vector<PCB *>. 

public:
    /**
     * @brief Construct a new PCBTable object of the given size (number of PCBs)
     *
     * The table is initalized with 'size' entries, all set to nullptr.
     * 
     * @param size: the capacity of the PCBTable
     */
    PCBTable(int size = 100);

    /**
     * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
     *
     * Deletes all PCB objects stored in the table to free memory and prevent leaks.

     */
    ~PCBTable();

    /**
     * @brief Get the PCB at index "idx" of the PCBTable.
     *
     * @param idx: the index of the PCB to get
     * @return PCB*: pointer to the PCB at index "idx", or nullptr if index is out of bounds.
     */
    PCB* getPCB(unsigned int idx);

    /**
     * @brief Overload of the operator [] that returns the PCB at idx
     *
     * @param idx
     * @return PCB*
     */
    PCB *operator[](unsigned int idx) {
        return getPCB(idx);
    }

    /**
     * @brief Add a PCB pointer to the PCBTable at index idx.
     *
     * If a PCB already exists at this index, it will be replaced. 
     * Does nothing if index is out of bounds. 
     * 
     * @param pcb: the PCB pointer to add
     * @param idx: Index in the table where the PCB should be stored.
     */
    void addPCB(PCB *pcb, unsigned int idx);

    /**
     * @brief Add a new PCB to the PCBTable.
     * 
     * The new PCB is created with the given ID and prirority. Its initial state is NEW.
     * It is added at the specified index
     * 
     * @param pid Id of the new PCB
     * @param priority The priority of the new PCB (1-50)
     * @param idx The index of the new PCB in the PCBTable
     */
    void addNewPCB(unsigned int pid, unsigned int priority, unsigned int idx) {
        PCB *pcb = new PCB(pid, priority);
        addPCB(pcb, idx);
    }
};
