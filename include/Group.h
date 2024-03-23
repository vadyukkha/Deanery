#pragma once
#ifndef INCLUDE_GROUP_H
#define INCLUDE_GROUP_H

#include <iostream>
#include <vector>
#include <string>

#include "Student.h"
class Student;

class Group {
 public:
   Group() = default;

   // main functions
   void createGroup(const std::string& name, const std::string& spec);
   void addStudent(const Student* student);
   void electionHeadman();
   bool searchStudent(const std::string& fio);
   bool searchStudent(const int64_t& id);
   double getAverageGradeGroup();
   void deleteStudent(const Student* student);

   // getters
   std::string getTitle() const;
   std::string getSpec() const;
   Student* getHead() const;
   std::vector<Student*> getStudents() const;

   // setters
   void setTitle(const std::string& title);
   void setSpec(const std::string& spec);
   void setHead(Student* head);
   void setStudents(const std::vector<Student*>& students);

 protected:
   std::string title_;
   std::string spec_;
   std::vector<Student*> students_;
   Student *head_;
};

#endif // INCLUDE_GROUP_H
