#include "../include/Student.h"

void Student::createStudent(const int64_t& id, const std::string& fio) {
    id_ = id;
    fio_ = fio;
}

void Student::enrollingStudent(Group *group) {
    this->group_ = group;
    group->addStudent(this);
}

void Student::addMarks(const uint16_t& mark) {
    marks_.push_back(mark);
}

void Student::addMarks(const std::vector<uint16_t>& marks) {
    for (size_t i = 0; i < marks.size(); i++) {
        marks_.push_back(marks[i]);
    }
}

double Student::getAverageGrade() const {
    double avg = std::accumulate(marks_.begin(), marks_.end(), 0.0) / marks_.size();
    return avg;
}

int64_t Student::getId() const {
    return id_;
}

std::string Student::getFio() const {
    return fio_;
}

Group* Student::getGroup() const {
    return group_;
}

std::vector<uint16_t> Student::getMarks() const {
    return marks_;
}

void Student::setGroup(Group *group) {
    group_ = group;
}

void Student::setId(const int64_t& id) {
    id_ = id;
}

void Student::setFio(const std::string& fio) {
    fio_ = fio;
}

void Student::setMarks(const std::vector<uint16_t>& marks) {
    marks_ = marks;
}

Student& Student::operator=(const Student& student) {
    id_ = student.id_;
    fio_ = student.fio_;
    group_ = student.group_;
    marks_ = student.marks_;
    return *this;
}
