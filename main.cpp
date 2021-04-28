#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <sstream>
#include "TextTable.h"
#include "note.h"
#include "mark.h"
#include "student.h"
#include "class.h"

inline void ignoreBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::vector<Mark> marks;
std::vector<Note> notes;
std::vector<Student> students;
std::vector<Class> classes;

void inputMark(Mark &mark) {
    ignoreBuffer();
    std::cout << "Subject: ";
    std::cin.getline(mark.subject, 20);
    std::cout << "Type: ";
    std::cin.getline(mark.type, 15);
    std::cout << "Value: ";
    std::cin >> mark.value;
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

void inputStudent(Student &student) {
    ignoreBuffer();
    std::cout << "First name: ";
    std::cin.getline(student.firstName, 25);
    std::cout << "Second name: ";
    std::cin.getline(student.secondName, 25);
    std::cout << "Last name: ";
    std::cin.getline(student.lastName, 25);
}

void inputClass(Class &class_) {
    std::cout << "Grade: ";
    std::cin >> class_.grade;
    std::cout << "Letter: ";
    std::cin >> class_.letter;
}

void printMenu() {
    std::cout << "---Options menu---" << std::endl;
    std::cout << "\t 0 ---> Exit the program" << std::endl;
    std::cout << "\t 1 ---> Input" << std::endl;
    std::cout << "\t 2 ---> Output" << std::endl;
    std::cout << "\t 3 ---> ****" << std::endl;
    std::cout << "\t 4 ---> Search by numeric criteria" << std::endl;
    std::cout << "\t 5 ---> Search by ID" << std::endl;
    std::cout << "\t 6 ---> Search by string" << std::endl;
    std::cout << "\t 7 ---> Numeric1" << std::endl;
    std::cout << "\t 8 ---> Sum" << std::endl;
    std::cout << "\t 9 ---> Sort by string" << std::endl;
    std::cout << "\t10 ---> Sort by number" << std::endl;
    std::cout << "\t11 ---> Append element" << std::endl;
    std::cout << "\t12 ---> Delete element" << std::endl;
    std::cout << "\t13 ---> Edit element" << std::endl;
}

void execute1() {
    short c;
    std::cout << "---Enter an object---" << std::endl;
    std::cout << "\t1 ---> Mark" << std::endl;
    std::cout << "\t2 ---> Note" << std::endl;
    std::cout << "\t3 ---> Student" << std::endl;
    std::cout << "\t4 ---> Class" << std::endl;
    std::cout << "Enter option: ";
    std::cin >> c;
    switch (c)
    {
    case 1:
        {
            Mark mark;
            inputMark(mark);
            marks.push_back(mark);
            break;
        }
    
    case 2:
        {
            Note note;
            inputNote(note);
            notes.push_back(note);
            break;
        }
    
    case 3:
        {
            Student student;
            inputStudent(student);
            students.push_back(student);
            break;
        }
    case 4: 
        {
            Class class_;
            inputClass(class_);
            classes.push_back(class_);
            break;
        }
    default:
        std::cout << "Invalid option!" << std::endl;
        return;
        break;
    }
}

void execute2() {
    TextTable marks_table;
    marks_table.add("ID");
    marks_table.add("Subject");
    marks_table.add("Type");
    marks_table.add("Value");
    marks_table.endOfRow();

    for (auto mark: marks) {
        std::stringstream id_stream;
        id_stream << mark.id;
        marks_table.add(id_stream.str());
        marks_table.add(mark.subject);
        marks_table.add(mark.type);
        std::stringstream value_stream;
        value_stream << mark.value;
        marks_table.add(value_stream.str());
        marks_table.endOfRow();
    }

    TextTable notes_table;
    notes_table.add("ID");
    notes_table.add("Subject");
    notes_table.add("Is Praise");
    notes_table.add("Message");
    notes_table.endOfRow();

    for (auto note: notes) {
        std::stringstream id_stream;
        id_stream << note.id;
        notes_table.add(id_stream.str());
        notes_table.add(note.subject);
        std::stringstream isPraise_stream;
        isPraise_stream << std::boolalpha << note.isPraise;
        notes_table.add(isPraise_stream.str());
        notes_table.add(note.message);
        notes_table.endOfRow();
    }

    TextTable students_table;
    students_table.add("ID");
    students_table.add("First name");
    students_table.add("Second name");
    students_table.add("Last name");
    students_table.endOfRow();

    for (auto student: students) {
        std::stringstream id_stream;
        id_stream << student.id;
        students_table.add(id_stream.str());
        students_table.add(student.firstName);
        students_table.add(student.secondName);
        students_table.add(student.lastName);
        students_table.endOfRow();
    }

    TextTable classes_table;
    classes_table.add("ID");
    classes_table.add("Grade");
    classes_table.add("Letter");
    classes_table.endOfRow();

    for (auto class_: classes) {
        std::stringstream id_stream;
        id_stream << class_.id;
        classes_table.add(id_stream.str());
        std::stringstream grade_stream;
        grade_stream << class_.grade;
        classes_table.add(grade_stream.str());
        std::stringstream letter_stream;
        letter_stream << class_.letter;
        classes_table.add(letter_stream.str());
        classes_table.endOfRow();
    }

    std::cout << "---Marks---" << std::endl;
    std::cout << marks_table;
    std::cout << "---Notes---" << std::endl;
    std::cout << notes_table;
    std::cout << "---Students---" << std::endl;
    std::cout << students_table;
    std::cout << "---Classes---" << std::endl;
    std::cout << classes_table;
}

int main() {
    short c;
    while (true) {
        printMenu();
        std::cout << "Enter option: ";
        std::cin >> c;
        switch (c)
        {
        case 0:
            std::cout << "Exiting..." << std::endl;
            return 0;
            break;
        
        case 1:
            execute1();
            break;
        
        case 2:
            execute2();
            break;

        default:
            std::cout << "Invalid option!" << std::endl;
            break;
        }
        std::cout << "Press any key to continue...";
        std::cin.ignore(1, '\n');
        std::getchar();
        std::ostringstream oss{};
        oss << std::cin.rdbuf();
        std::string all_chars{oss.str()};
        std::cout << all_chars;
    }
    return 0;
}