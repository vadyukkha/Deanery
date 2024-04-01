// Copyright 2024 by Contributors
#include "../include/Student.h"

int main() {
    Student student;
    Group group_23cst6;
    group_23cst6.createGroup("23КНТ6", "ИМИКН");
    Group *p_group = &group_23cst6;

    student.setId(1);
    student.setFio("Ivanov Ivan Ivanovich");
    student.setGroup(p_group);
    student.setMarks({5, 4, 3, 5, 4, 5, 3, 4, 5, 4});

    std::cout << "Student ID: " << student.getId() << std::endl;
    std::cout << "Student FIO: " << student.getFio() << std::endl;
    std::cout << "Student Group: " << student.getGroup()->getTitle() << std::endl;
    std::cout << "Student Marks: ";
    for (const auto& mark : student.getMarks()) {
        std::cout << mark << " ";
    }
    std::cout << std::endl;
    std::cout << "Student Average Grade: " << student.getAverageGrade() << std::endl;

    Student student2;
    student2.createStudent(2, "Petrov Petr Petrovich");
    student2.enrollingStudent(p_group);
    student2.addMarks({4, 3, 5, 4, 5, 3, 4, 5, 4, 5});

    std::cout << "Student ID: " << student2.getId() << std::endl;
    std::cout << "Student FIO: " << student2.getFio() << std::endl;
    std::cout << "Student Group: " << student2.getGroup()->getTitle() << std::endl;
    std::cout << "Student Marks: ";
    for (const auto& mark : student2.getMarks()) {
        std::cout << mark << " ";
    }
    std::cout << std::endl;
    std::cout << "Student Average Grade: " << student2.getAverageGrade() << std::endl;

    return 0;
}