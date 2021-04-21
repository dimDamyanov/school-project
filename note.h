#pragma once

struct Note {
    static int nextID;

    int id;
    Note() {
        id = ++nextID;
    }
    bool isPraise;
    char subject[20];
    char message[75];
};

int Note::nextID = 0;