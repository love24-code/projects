#include <iostream>
#include <string> 
#include "library.h"

using namespace std;

string headerLine;


void processFile(ifstream& input) {

    string headerLine;
    getline(input, headerLine); // Skip header

    Enrollment enrollment;
    Statistics stats{};  // initialize all values to 0

    while (input.peek() != EOF) {

        collect(input, enrollment);
        display(enrollment);

        stats.num_Majors++;

        // Highest % No College
        if (stats.num_Majors == 1 || 
            enrollment.percentNoCollege > stats.highestNoCollegePercent) {

            stats.highestNoCollegePercent = enrollment.percentNoCollege;
            stats.highestNoCollegeMajor = enrollment.major;
        }

        // Lowest % Some College
        if (stats.num_Majors == 1 || 
            enrollment.percentSomeCollege < stats.lowestSomeCollegePercent) {

            stats.lowestSomeCollegePercent = enrollment.percentSomeCollege;
            stats.lowestSomeCollegeMajor = enrollment.major;
        }

        // CSTEM totals
        if (enrollment.college == "CSTEM") {
            stats.totalCSTEMStudents += enrollment.num_Students;
            stats.totalCSTEMFirstGenStudents += enrollment.numFirstGenStudents;
        }
    }

    // Calculate CSTEM first-gen percentage
    if (stats.totalCSTEMStudents > 0) {
        stats.percentCSTEMFirstGen =
            static_cast<double>(stats.totalCSTEMFirstGenStudents)
            / stats.totalCSTEMStudents * 100;
    }

    display(stats);
}

