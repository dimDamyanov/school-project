#pragma once

struct Mark {
    static int nextID;

    int id;
    Mark() {
        id = ++nextID;
    }
    char subject[20];
    char type[15];
    float value;
};

int Mark::nextID = 0;