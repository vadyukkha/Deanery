// Copyright 2024 by Contributors
#include <iostream>
#include <limits>
#include "../include/Deanary.h"

int main() {
    Deanery deanery;
    bool exitFlag = false;

    while (!exitFlag) {
        std::cout << "========== Deanery Management System ==========" << std::endl;
        std::cout << "1. Load students and groups from files" << std::endl;
        std::cout << "2. Save students and groups to files" << std::endl;
        std::cout << "3. Add random marks to students" << std::endl;
        std::cout << "4. Display statistics" << std::endl;
        std::cout << "5. Save statistics to file" << std::endl;
        std::cout << "6. Transfer student to another group" << std::endl;
        std::cout << "7. Deduct students with low performance" << std::endl;
        std::cout << "8. Display data" << std::endl;
        std::cout << "9. Save data in JSON" << std::endl;
        std::cout << "10. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        uint16_t choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                deanery.loadGroupsFromFile();
                deanery.loadStudentsFromFile();
                std::cout << "Data loaded successfully." << std::endl;
                break;
            case 2:
                deanery.saveStudentsToFile();
                deanery.saveGroupsToFile();
                std::cout << "Data saved successfully." << std::endl;
                break;
            case 3:
                deanery.addRandomMarks();
                std::cout << "Random marks added successfully." << std::endl;
                break;
            case 4:
                deanery.getStatistics();
                break;
            case 5:
                deanery.saveStatistics();
                std::cout << "Statistics saved successfully." << std::endl;
                break;
            case 6: {
                int64_t id;
                std::string title;
                std::cout << "Enter student ID: ";
                std::cin >> id;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter target group title: ";
                std::getline(std::cin, title);
                deanery.studentTransfer(id, title);
                break;
            }
            case 7:
                deanery.deductionStudent();
                std::cout << "Students with low performance successfully deducted." << std::endl;
                break;
            case 8:
                deanery.displayData();
                break;
            case 9:
                deanery.saveDataInJSON();
                std::cout << "Data saved successfully to data_save.json" << std::endl;
                break;
            case 10:
                exitFlag = true;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 8." << std::endl;
                break;
        }

        std::cout << "===============================================" << std::endl << std::endl;
    }

    return 0;
}
