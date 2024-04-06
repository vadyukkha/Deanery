// Copyright 2024 by Contributors
#include "../include/Deanary.h"

int main() {
    Deanery deanery;
    deanery.loadGroupsFromFile();
    deanery.loadStudentsFromFile();

    deanery.displayData();

    deanery.addRandomMarksToAll();

    deanery.getStatistics();

    deanery.moveStudents(1, "23КНТ6");

    deanery.fireStudents();
    
    deanery.saveStatistics();

    deanery.saveStudentsToFile();

    deanery.saveGroupsToFile();
    return 0;
}
