#pragma once
#ifndef INCLUDE_DEANARY_H
#define INCLUDE_DEANARY_H

#include "Group.h"
#include "Student.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

class Deanery {
 public:
   Deanery() = default;

   // main functions
   void loadStudentsFromFile();
   void loadGroupsFromFile();
   void addRandomMarks();
   void getStatistics() const;
   void saveStatistics() const;
   void studentTransfer(const int64_t& id, const std::string& title);
   void deductionStudent();
   void saveStudentsToFile() const;
   void saveGroupsToFile() const;
   void displayData() const;
   std::vector<Group*> getGroups() const;

 private:
   std::vector<Group*> groups_;
};

#endif // INCLUDE_DEANARY_H
