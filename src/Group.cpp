// Copyright 2024 by Contributors
#include "../include/Group.h"
#include "../include/Student.h"

void Group::createGroup(const std::string& title, const std::string& spec) {
    title_ = title;
    spec_ = spec;
}

void Group::addStudent(const Student* student) {
    students_.push_back(const_cast<Student*>(student));
}

void Group::chooseHead() {
    if (students_.empty()) {
        std::cout << "Group is empty" << std::endl;
        return;
    }
    head_ = students_[0];
    for (size_t i = 1; i < students_.size(); i++) {
        if (students_[i]->getAverageMark() > head_->getAverageMark()) {
            head_ = students_[i];
        }
    }
}

Student* Group::searchStudent(const std::string& fio) {
    for (size_t i = 0; i < students_.size(); i++) {
        if (students_[i]->getFio() == fio) {
            return students_[i];
        }
    }
    return nullptr;
}

Student* Group::searchStudent(const int64_t& id) {
    for (size_t i = 0; i < students_.size(); i++) {
        if (students_[i]->getId() == id) {
            return students_[i];
        }
    }
    return nullptr;
}

double Group::getAverageGradeGroup() {
    double avg = 0;
    for (size_t i = 0; i < students_.size(); i++) {
        avg += students_[i]->getAverageMark();
    }
    return avg / students_.size();
}

void Group::removeStudent(const Student* student) {
    for (size_t i = 0; i < students_.size(); i++) {
        if (students_[i] == student) {
            students_.erase(students_.begin() + i);
            return;
        }
    }
}

std::string Group::getTitle() const {
    return title_;
}

std::string Group::getSpec() const {
    return spec_;
}

Student* Group::getHead() const {
    return head_;
}

std::vector<Student*> Group::getStudents() const {
    return students_;
}

void Group::setTitle(const std::string& title) {
    title_ = title;
}

void Group::setSpec(const std::string& spec) {
    spec_ = spec;
}

void Group::setHead(const Student* head) {
    head_ = const_cast<Student*>(head);
}

void Group::setStudents(const std::vector<Student*>& students) {
    students_ = students;
}

Group& Group::operator=(const Group& group) {
    title_ = group.title_;
    spec_ = group.spec_;
    students_ = group.students_;
    head_ = group.head_;
    return *this;
}

bool Group::isEmpty() const {
    return students_.empty();
}
