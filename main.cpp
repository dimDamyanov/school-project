#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include "TextTable.h"
#include "note.h"
#include "mark.h"
#include "student.h"
#include "class.h"

inline void ignoreBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void inputNote(Note &note) {
    std::cout << "Is praise (0 or 1): ";
    std::cin >> note.isPraise;
    ignoreBuffer();
    std::cout << "Subject: ";
    std::cin.getline(note.subject, 20);
    std::cout << "Message: ";
    std::cin.getline(note.message, 75);
}

void inputMark(Mark &mark) {
    ignoreBuffer();
    std::cout << "Subject: ";
    std::cin.getline(mark.subject, 20);
    std::cout << "Type: ";
    std::cin.getline(mark.type, 15);
    std::cout << "Value: ";
    std::cin >> mark.value;
}

int main() {
    Note note;
    Mark mark;
    inputNote(note);
    inputMark(mark);
    TextTable t;
    t.add("ID");
    t.add("IsPraise");
    t.add("Subject");
    t.add("Message");
    t.endOfRow();
    t.add(std::to_string(note.id));
    t.add(std::to_string(note.isPraise));
    t.add(note.subject);
    t.add(note.message);
    t.endOfRow();
    std::cout << t << std::endl;
    TextTable t1;
    t1.add("ID");
    t1.add("Subject");
    t1.add("Type");
    t1.add("Value");
    t1.endOfRow();
    t1.add(std::to_string(mark.id));
    t1.add(mark.subject);
    t1.add(mark.type);
    t1.add(std::to_string(mark.value));
    t1.endOfRow();
    std::cout << t1;
    return 0;
}