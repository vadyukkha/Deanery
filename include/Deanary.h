// Copyright 2024 by Contributors
#pragma once
#ifndef INCLUDE_DEANARY_H
#define INCLUDE_DEANARY_H

#include "Group.h"
#include "Student.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "../include/json/include/nlohmann/json.hpp"

using json = nlohmann::json;

class Deanery {
 public:
    Deanery() = default;

    /* main functions */
    // создание студентов на основе данных из файла
    void loadStudentsFromFile();
    // создание групп на основе данных из файла
    void loadGroupsFromFile();
    // сохранение студентов в файл
    void saveStudentsToFile() const;
    // сохранение группы студентов в файл
    void saveGroupsToFile() const;
    // получение статистики по успеваемости студентов с выводом в консоль
    void getStatistics() const;
    // получение статистики по успеваемости студентов с сохранение в файл
    void saveStatistics() const;
    // добавление случайных оценок студентам
    void addRandomMarks();
    // перевод студентов из группы в группу
    void studentTransfer(const int64_t& id, const std::string& title);
    // отчисление студентов за неуспеваемость
    void deductionStudent();
    // вывод данных на консоль
    void displayData() const;
    // сохранение данных в json
    void saveDataInJSON() const;

    /* getters */
    // получение групп
    std::vector<Group*> getGroups() const;

    /* setters */
    // установка групп
    void setGroup(const std::vector<Group*> groups);

 private:
    std::vector<Group*> groups_;
};

#endif  // INCLUDE_DEANARY_H
