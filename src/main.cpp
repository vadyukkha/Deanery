#include "../include/Deanary.h"

int main() {
    Deanery deanery;
    deanery.loadGroupsFromFile();
    deanery.loadStudentsFromFile();
    
    deanery.displayData();

    deanery.addRandomMarks();

    deanery.getStatistics();

    deanery.studentTransfer(1, "23КНТ6");

    deanery.deductionStudent();

    deanery.saveStudentsToFile();

    deanery.saveGroupsToFile();

    return 0;
}
