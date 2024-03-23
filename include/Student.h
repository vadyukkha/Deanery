#pragma once
#ifndef INCLUDE_STUDENT_H
#define INCLUDE_STUDENT_H

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

#include "Group.h"
class Group;

class Student {
 public:
   Student() = default;

   // main functions
   void createStudent(const int64_t& id, const std::string& fio);
   void enrollingStudent(Group* group) const;
   void addMarks(const uint16_t& mark);
   void addMarks(const std::vector<uint16_t>& marks);
   double getAverageGrade() const;

   // getters
   int64_t getId() const;
   std::string getFio() const;
   Group* getGroup() const;
   std::vector<uint16_t> getMarks() const;

   // setters
   void setGroup(Group* group);
   void setId(const int64_t& id);
   void setFio(const std::string& fio);
   void setMarks(const std::vector<uint16_t>& marks);

   // overerload operators
   Student &operator=(const Student &student) {
       id_ = student.id_;
       fio_ = student.fio_;
       group_ = student.group_;
       marks_ = student.marks_;
       return *this;
   }

 protected:
   int64_t id_;
   std::string fio_;
   Group *group_;
   std::vector<uint16_t> marks_;
};

#endif // INCLUDE_STUDENT_H
