// Copyright 2024 by Contributors
#pragma once
#ifndef INCLUDE_STUDENT_H
#define INCLUDE_STUDENT_H

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

class Group;

class Student {
 public:
    Student() = default;
    ~Student() = default;

    /* main functions */
    // создание студента с указанием ИД и ФИО
    void createStudent(const int64_t& id, const std::string& fio);
    // зачисление в группу студента
    void addToGroup(Group* group);
    // добавление оценки студенту
    void addMarks(const uint16_t& mark);
    // добавление нескольких оценок студенту
    void addMarks(const std::vector<uint16_t>& marks);
    // вычисление средней оценки студента
    double getAverageMark() const;
    // проверка студента на старосту
    bool isHeadOfGroup() const;

    /* getters */
    // получение индивидуального номера студента
    int64_t getId() const;
    // получение фамилии имени отчества студента
    std::string getFio() const;
    // получение группы студента
    Group* getGroup() const;
    // получение оценок студента
    std::vector<uint16_t> getMarks() const;

    /* setters */
    // установка группы студента
    void setGroup(Group* group);
    // установка индивидуального номера студента
    void setId(const int64_t& id);
    // установка фамилии имени отчества студента
    void setFio(const std::string& fio);
    // установка оценок студента
    void setMarks(const std::vector<uint16_t>& marks);

    /* overerload operators */
    Student &operator=(const Student &student);

 private:
    int64_t id_;
    std::string fio_;
    Group *group_;
    std::vector<uint16_t> marks_;
};

#endif  // INCLUDE_STUDENT_H
