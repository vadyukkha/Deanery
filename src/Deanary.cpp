#include "../include/Deanary.h"

void Deanery::loadStudentsFromFile() {
    std::ifstream file;
    file.open("../bd/students.txt");
    if (!file.is_open()) {
        std::cout << "File students.txt not found" << std::endl;
        return;
    }

    std::string line;
    std::string fio, title, name, surname, patronymic;
    int64_t id;

    while(std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> id >> surname >> name >> patronymic >> title;
        fio = surname + " " + name + " " + patronymic;
        std::vector<uint16_t> marks;
        uint16_t mark;
        while (iss >> mark) {
            marks.push_back(mark);
        }
        Student *student = new Student;
        student->createStudent(id, fio);
        for (const auto& group : groups_) {
            if (group->getTitle() == title) {
                student->setGroup(group);
                student->setMarks(marks);
                group->addStudent(student);
                break;
            }
        }
    }
    file.close();
}

void Deanery::loadGroupsFromFile() {
    std::ifstream file;
    file.open("../bd/groups.txt");
    if (!file.is_open()) {
        std::cout << "File groups.txt not found" << std::endl;
        return;
    }

    std::string line;
    std::string title, spec, name, surname, patronymic, head;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> title >> spec >> surname >> name >> patronymic;
        head = surname + " " + name + " " + patronymic;
        Group *group = new Group;
        group->createGroup(title, spec);
        Student *headman = new Student;
        headman->createStudent(0, head);
        group->setHead(headman);
        groups_.push_back(group);
    }
    file.close();
}

void Deanery::addRandomMarks() {
    srand(time(0));
    for (const auto& group : groups_) {
        for (const auto& student : group->getStudents()) {
            student->addMarks(rand() % 11);
        }
    }
}

void Deanery::getStatistics() const {
    std::cout << "Statistics:" << std::endl;
    for (const auto& group : groups_) {
        std::cout << "Group:\t\t\t" << group->getTitle() << std::endl;
        std::cout << "Spec:\t\t\t" << group->getSpec() << std::endl;
        std::cout << "Headman:\t\t" << group->getHead()->getFio() << std::endl;
        std::cout << "Average grade:\t" << group->getAverageGradeGroup() << std::endl << std::endl;

        for (const auto& student : group->getStudents()) {
            std::cout << "[" << group->getTitle() << "] >> " 
                << "Student:\t\t" << student->getFio() << std::endl;

            auto print = [](const std::vector<uint16_t>& v) {
                for (const auto& el : v) {std::cout << el << " ";} std::cout << std::endl;};

            std::cout << "[" << group->getTitle() << "] >> "
                << "All grades:\t\t";
            print(student->getMarks());

            std::cout << "[" << group->getTitle() << "] >> "
                << "Average grade:\t" << student->getAverageGrade() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "-------------------" << std::endl;
    }
}

void Deanery::studentTransfer(const int64_t& id, const std::string& title) {
    Student *student = nullptr;
    for (const auto& group : groups_) {
        for (const auto& st : group->getStudents()) {
            if (st->getId() == id) {
                student = st;
                break;
            }
        }
    }

    if (student == nullptr) {
        std::cout << "Student not found" << std::endl;
        return;
    }

    Group *new_group = nullptr;
    for (const auto& group : groups_) {
        if (group->getTitle() == title) {
            new_group = group;
            break;
        }
    }

    if (new_group == nullptr) {
        std::cout << "Group not found" << std::endl;
        return;
    }

    student->getGroup()->deleteStudent(student);
    student->setGroup(new_group);
    new_group->addStudent(student);
    std::cout << "Student successfully transferred" << std::endl;
}

void Deanery::deductionStudent() {
    uint32_t count = 0;
    for (const auto& group : groups_) {
        for (const auto& student : group->getStudents()) {
            if (student->getAverageGrade() < 4.0) {
                group->deleteStudent(student);
                count++;
            }
        }
    }
    std::cout << "Number of deduction students:\t" << count << std::endl;
}

void Deanery::saveStudentsToFile() const {
    std::ofstream file;
    file.open("../bd/students.txt");
    if (!file.is_open()) {
        std::cout << "File students.txt not found" << std::endl;
        return;
    }

    for (const auto& group : groups_) {
        for (const auto& student : group->getStudents()) {

            file << student->getId() << " " << student->getFio() << " " 
                << student->getGroup()->getTitle() << " ";
            auto saveMarksInFile = [&file](const std::vector<uint16_t>& v) {for (const auto& el : v) {file << el << " ";} file << std::endl;};
            saveMarksInFile(student->getMarks());
        }
    }
    std::cout << "Data saved in file students.txt" << std::endl;
    file.close();
}

void Deanery::saveGroupsToFile() const {
    std::ofstream file;
    file.open("../bd/groups.txt");
    if (!file.is_open()) {
        std::cout << "File groups.txt not found" << std::endl;
        return;
    }

    for (const auto& group : groups_) {
        file << group->getTitle() << " " << group->getSpec() << " " <<
            group->getHead()->getFio() << std::endl;
    }
    std::cout << "Data saved in file groups.txt" << std::endl;
    file.close();
}

void Deanery::displayData() const {
    std::cout << "Data:" << std::endl;
    for (const auto& group : groups_) {
        std::cout << "Title of Group:\t" << group->getTitle() << std::endl;
        for (const auto& student : group->getStudents()) {

            std::cout << student->getId() << " " << student->getFio() << " " 
                << student->getGroup()->getTitle() << " ";
            auto printMarks = [](const std::vector<uint16_t>& v) {for (const auto& el : v) {std::cout << el << " ";} std::cout << std::endl;};
            printMarks(student->getMarks());
        }
        std::cout << std::endl;
    }
}

std::vector<Group*> Deanery::getGroups() const {
    return groups_;
}

void Deanery::setGroup(const std::vector<Group*> groups) {
    groups_ = groups;
} 

void Deanery::saveStatistics() const {
    std::ofstream file;
    file.open("../bd/output_statistics.txt");
    if (!file.is_open()) {
        std::cout << "File statistics.txt not found" << std::endl;
        return;
    }

    for (const auto& group : groups_) {
        file << "Group:\t\t\t" << group->getTitle() << std::endl;
        file << "Spec:\t\t\t" << group->getSpec() << std::endl;
        file << "Headman:\t\t" << group->getHead()->getFio() << std::endl;
        file << "Average grade:\t" << group->getAverageGradeGroup() << std::endl << std::endl;

        for (const auto& student : group->getStudents()) {
            file << "[" << group->getTitle() << "] >> " 
                << "Student:\t\t" << student->getFio() << std::endl;

            auto print = [&file](const std::vector<uint16_t>& v) {
                for (const auto& el : v) {file << el << " ";} file << std::endl;};

            file << "[" << group->getTitle() << "] >> "
                << "All grades:\t\t";
            print(student->getMarks());

            file << "[" << group->getTitle() << "] >> "
                << "Average grade:\t" << student->getAverageGrade() << std::endl;
            file << std::endl;
        }
        file << "-------------------" << std::endl;
    }
    std::cout << "Data saved in file statistics.txt" << std::endl;
    file.close();
}

void Deanery::saveDataInJSON() const {
    json data_save_json;
    for (const Group* group : groups_) {
        json group_json;
        group_json["name"] = group->getTitle();
        group_json["spec"] = group->getSpec();
        group_json["headman"] = group->getHead()->getFio();
        group_json["students"] = json::array();
        for (const Student* student : group->getStudents()) {
            json student_json;
            student_json["id"] = student->getId();
            student_json["name"] = student->getFio();
            student_json["group"] = student->getGroup()->getTitle();
            student_json["avg"] = student->getAverageGrade();
            student_json["marks"] = json::array();
            for (int mark : student->getMarks()) {
                student_json["marks"].push_back(mark);
            }
            group_json["students"].push_back(student_json);
        }
        data_save_json.push_back(group_json);
    }
    std::ofstream file_out("../bd/data_save.json");
    file_out << data_save_json.dump(2);
    file_out.close();
}