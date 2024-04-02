// Copyright 2024 by Contributors
#include <iostream>
#include <limits>
#include "../include/Deanary.h"

int main() {
    Deanery deanery;
    bool exitFlag = false;
    bool checksave = false;
    bool checkload = false;

    while (!exitFlag) {
        std::cout << "========== Deanery Management System ==========" << std::endl;
        std::cout << "1. Load students and groups from files" << std::endl;
        std::cout << "2. Save students and groups to files" << std::endl;
        std::cout << "3. Add random marks to students" << std::endl;
        std::cout << "4. Display statistics" << std::endl;
        std::cout << "5. Save statistics to file" << std::endl;
        std::cout << "6. Transfer students to another groups" << std::endl;
        std::cout << "7. Deduct students with low performance" << std::endl;
        std::cout << "8. Display data" << std::endl;
        std::cout << "9. Save data in JSON" << std::endl;
        std::cout << "10. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        uint16_t choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (!checkload) {
                    deanery.loadGroupsFromFile();
                    deanery.loadStudentsFromFile();
                    checkload = true;
                    std::cout << "Data loaded successfully." << std::endl;
                    break;
                } else {
                    std::cout << "You already loaded data." << std::endl;
                    break;
                }
            case 2:
                deanery.saveStudentsToFile();
                deanery.saveGroupsToFile();
                checksave = true;
                std::cout << "Data saved successfully." << std::endl;
                break;
            case 3:
                deanery.addRandomMarksToAll();
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
                int64_t n;
                std::cout << "Enter number of transfer students: ";
                std::cin >> n;
                while (n > 0) {
                    int64_t id;
                    std::string title;
                    std::cout << "Enter student ID: ";
                    std::cin >> id;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Enter target group title: ";
                    std::getline(std::cin, title);
                    deanery.moveStudents(id, title);
                    n--;
                }
                break;
            }
            case 7:
                deanery.fireStudents();
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
                if (!checksave) {
                    char answer;
                    std::cout << "Are you sure exit without saving file? [y/n]" << std::endl;
                    std::cin >> answer;
                    if (answer == 'n') {
                        deanery.saveStudentsToFile();
                        deanery.saveGroupsToFile();
                        checksave = true;
                        std::cout << "Data saved successfully." << std::endl;
                    }
                    exitFlag = true;
                    break;
                }
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 10." << std::endl;
                break;
        }

        std::cout << "===============================================" << std::endl << std::endl;
    }

    return 0;
}
