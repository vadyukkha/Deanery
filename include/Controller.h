#pragma once
#ifndef INCLUDE_CONTROLLER_H
#define INCLUDE_CONTROLLER_H

#include <iostream>
#include <memory>

class Deanery;

class Controller {
  public:
    Controller();
    ~Controller() = default;

    void run();
  private:
    std::unique_ptr<Deanery> deanery_;
};

#endif  // INCLUDE_CONTROLLER_H
