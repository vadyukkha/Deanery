#include "../include/Group.h"

void Group::createGroup(const std::string& title, const std::string& spec) {
    title_ = title;
    spec_ = spec;
}

void Group::addStudent(const Student* student) {
    students_.push_back(const_cast<Student*>(student));
}

void Group::electionHeadman() {
    if (students_.empty()) {
        std::cout << "Group is empty" << std::endl;
        return;
    }
    head_ = students_[0];
    for (size_t i = 1; i < students_.size(); i++) {
        if (students_[i]->getAverageGrade() > head_->getAverageGrade()) {
            head_ = students_[i];
        }
    }
}

bool Group::searchStudent(const std::string& fio) {
    for (size_t i = 0; i < students_.size(); i++) {
        if (students_[i]->getFio() == fio) {
            return true;
        }
    }
    return false;
}

bool Group::searchStudent(const int64_t& id) {
    for (size_t i = 0; i < students_.size(); i++) {
        if (students_[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

double Group::getAverageGradeGroup() {
    double avg = 0;
    for (size_t i = 0; i < students_.size(); i++) {
        avg += students_[i]->getAverageGrade();
    }
    return avg / students_.size();
}

void Group::deleteStudent(const Student* student) {
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
