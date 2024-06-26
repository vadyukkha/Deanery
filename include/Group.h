// Copyright 2024 by Contributors
#pragma once
#ifndef INCLUDE_GROUP_H
#define INCLUDE_GROUP_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Student;

class Group {
 public:
    Group() = default;
    ~Group() = default;

    /* main functions */
    // создание группы с указанием названия
    void createGroup(const std::string& title, const std::string& spec);
    // добавление студента
    void addStudent(const Student* student);
    // избрание старосты
    void chooseHead();
    // поиск студента по ФИО
    Student* searchStudent(const std::string& fio);
    // поиск студента по Ид
    Student* searchStudent(const int64_t& id);
    // вычисление среднего балла в группе
    double getAverageGradeGroup();
    // исключение студента из группы
    void removeStudent(const Student* student);
    // проверка на пустоту
    bool isEmpty() const;

    /* getters */
    // получение названия группы
    std::string getTitle() const;
    // получение специальности группы
    std::string getSpec() const;
    // получение старосты группы
    Student* getHead() const;
    // получение всех студентов группы
    std::vector<Student*> getStudents() const;

    /* setters */
    // установка названия группы
    void setTitle(const std::string& title);
    // установка специальности группы
    void setSpec(const std::string& spec);
    // установка старосты группы
    void setHead(const Student* head);
    // установка студентов группы
    void setStudents(const std::vector<Student*>& students);

    /* overerload operators */
    Group &operator=(const Group &group);

 private:
    std::string title_;
    std::string spec_;
    std::vector<Student*> students_;
    Student *head_;
};

#endif  // INCLUDE_GROUP_H
