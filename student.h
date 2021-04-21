#pragma once

#include <vector>
#include "mark.h"
#include "note.h"


struct Student {
    static int nextID;

    int id;
    Student() {
        id = ++nextID;
    };

    char firstName[25];
    char secondName[25];
    char thirdName[25];
    std::vector<Mark> marks;
    std::vector<Note> notes;
};

int Student::nextID = 0;
