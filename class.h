#pragma once
#include <vector>
#include "student.h"


struct Class {
    static int nextID;

    int id;
    Class() {
        id = ++nextID;
    }
    int grade;
    char letter;
    std::vector<Student> students;
};

int Class::nextID = 0;