#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    srand(time(0));
    std::ifstream fileload;
    std::ofstream filesave_student;
    
    fileload.open("../bd/initial.txt");
    filesave_student.open("../bd/students.txt");

    std::string line;
    uint64_t id = 1;
    uint64_t id_group = 3;
    std::vector<uint16_t> marks;
    uint16_t mark;

    while (std::getline(fileload, line)) {
        if ((id - 1) % 29 == 0) id_group++;
        filesave_student << id << " " << line << " 23КНТ" << id_group << " ";

        for (size_t i = 0; i < 5; i++) {
            mark = rand() % 11;
            filesave_student << mark << " ";
        }

        filesave_student << std::endl;
        id++;
    }

    fileload.close();
    filesave_student.close();
    
    return 0;
}
