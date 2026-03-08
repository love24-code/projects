#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Enrollment {
    string major;
    string college;
    int num_Students;
    double percentNoCollege;
    double percentSomeCollege;
    int numFirstGenStudents;
};

struct Statistics {
    int num_Majors = 0;

    string highestNoCollegeMajor;
    double highestNoCollegePercent = 0.0;

    string lowestSomeCollegeMajor;
    double lowestSomeCollegePercent = 100.0;

    int totalCSTEMStudents = 0;
    int totalCSTEMFirstGenStudents = 0;

    double percentCSTEMFirstGen = 0.0;
};

void processFile(ifstream& input);
void collect(istream& input, Enrollment& enrollment);
void display(const Enrollment& enrollment);
void display(const Statistics& statistics);

#endif
