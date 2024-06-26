// Copyright 2024 by Contributors
#include <iostream>
#include "../include/Group.h"

void output(const Student* student) {
    if (student != nullptr) {
        std::cout << student->getFio() << std::endl;
    }
    else {
        std::cout << "Undefinded" << std::endl;
    }
}

int main() {
    Group group;
    group.setSpec("ИМИКН");
    group.setTitle("23КНТ6");

    Student student1, student2, student3;
    student1.createStudent(1, "Ivanov Ivan Ivanovich");
    student2.createStudent(2, "Petrov Petr Petrovich");
    student3.createStudent(3, "Sidorov Sidor Sidorovich");
    student1.addToGroup(&group);
    student2.addToGroup(&group);
    student3.addToGroup(&group);
    student1.addMarks({5, 4, 3, 5, 4, 5, 3, 4, 5, 4});
    student2.addMarks({4, 3, 5, 4, 5, 3, 4, 5, 4, 5});
    student3.addMarks({3, 4, 5, 3, 4, 5, 4, 5, 4, 5});

    group.setStudents({&student1, &student2, &student3});
    group.setHead(&student1);

    std::cout << "Group title: " << group.getTitle() << std::endl;
    std::cout << "Group spec: " << group.getSpec() << std::endl;
    std::cout << "Group head: " << group.getHead()->getFio() << std::endl;
    std::cout << "Group students: " << std::endl;
    for (const auto& student : group.getStudents()) {
        std::cout << "\t" << student->getFio() << std::endl;
    }
    double averageGrade = group.getAverageGradeGroup();
    std::cout << "Average grade of the group: " << averageGrade << std::endl << std::endl;

    Group group2;
    group2.createGroup("23КНТ5", "ИМИКН");
    group2.addStudent(&student1);
    group2.addStudent(&student2);
    group2.addStudent(&student3);
    group2.chooseHead();
    group2.removeStudent(&student2);
    
    std::cout << "Group title: " << group2.getTitle() << std::endl;
    std::cout << "Group spec: " << group2.getSpec() << std::endl;
    std::cout << "Group head: " << group2.getHead()->getFio() << std::endl;
    std::cout << "Group students: " << std::endl;
    Student* find_student = group2.searchStudent("Ivanov Ivan Ivanovich");
    output(find_student);
    find_student = group2.searchStudent("Petrov Petr Petrovich");
    output(find_student);
    find_student = group2.searchStudent("Sidorov Sidor Sidorovich");
    output(find_student);
    find_student = group2.searchStudent(1);
    output(find_student);
    find_student = group2.searchStudent(2);
    output(find_student);
    find_student = group2.searchStudent(3);
    output(find_student);
    
    return 0;
}
