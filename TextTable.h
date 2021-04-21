#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

class TextTable {
public:
    enum class Alignment {
        LEFT, RIGHT
    };
    typedef std::vector<std::string> Row;

    TextTable();

    void setAlignment(unsigned i, Alignment alignment);

    void add(std::string const &content);

    void endOfRow();

    void setup() const;

    std::string ruler() const;

    int correctDistance(std::string s) const;

private:
    char horizontal;
    char vertical;
    char corner;
    bool has_ruler;
    Row current;
    std::vector<Row> rows;
    std::vector<unsigned> mutable width;
    std::map<unsigned, Alignment> mutable alignment;

    std::string repeat(unsigned n, char c) const;

    unsigned columns() const;

    unsigned glyphLength(std::string s) const;

    void determineWidths() const;

    void setupAlignment() const;

    friend std::ostream & operator<<(std::ostream &ostream, TextTable const &textTable);
};

TextTable::TextTable() {
    horizontal = '-';
    vertical = '|';
    corner = '+';
    has_ruler = true;
}

void TextTable::setAlignment(unsigned int i, Alignment _alignment) {
    alignment[i] = _alignment;
}

void TextTable::add(const std::string &content) {
    current.push_back(content);
}

void TextTable::endOfRow() {
    rows.push_back(current);
    current.clear();
}

void TextTable::setup() const {
    determineWidths();
    setupAlignment();
}

std::string TextTable::ruler() const {
    std::string result;
    result += corner;
    for (auto _width = width.begin(); _width != width.end(); ++_width) {
        result += repeat(*_width, horizontal);
        result += corner;
    }

    return result;
}

int TextTable::correctDistance(std::string s) const {
    return static_cast<int>(s.size()) - static_cast<int>(glyphLength(s));
}

std::string TextTable::repeat(unsigned int n, char c) const {
    std::string result;
    for( ; n > 0; --n) {
        result += c;
    }
    return result;
}

unsigned TextTable::columns() const {
    return rows[0].size();
}

unsigned TextTable::glyphLength(std::string s) const {
    unsigned int byteLength = s.length();
    unsigned int u = 0;
    const char *c_str = s.c_str();
    unsigned glyphLength = 0;

    while (u < byteLength) {
        u += std::mblen(&c_str[u], byteLength);
        glyphLength++;
    }

    return glyphLength;
}

void TextTable::determineWidths() const {
    width.assign(columns(), 0);
    for (auto rowIterator = rows.begin(); rowIterator != rows.end(); ++rowIterator) {
        Row const &row = *rowIterator;
        for (unsigned i = 0; i < row.size(); ++i) {
            width[i] = width[i] > glyphLength(row[i]) ? width[i] : glyphLength(row[i]);
            width[i] += 1;
        }
    }
}

void TextTable::setupAlignment() const {
    for (unsigned i = 0; i < columns(); ++i) {
        if (alignment.find(i) == alignment.end()) {
            alignment[i] = Alignment::LEFT;
        }
    }
}

std::ostream & operator<<(std::ostream &ostream, TextTable const &textTable) {
    textTable.setup();
    if (textTable.has_ruler)
        ostream << textTable.ruler() << "\n";

    for (auto rowIterator = textTable.rows.begin(); rowIterator != textTable.rows.end(); ++rowIterator) {
        TextTable::Row const &row = *rowIterator;
        ostream << textTable.vertical;
        for (unsigned i = 0; i < row.size(); ++i) {
            auto alignment = textTable.alignment[i] == TextTable::Alignment::LEFT ? std::left : std::right;
            ostream << std::setw(textTable.width[i] + textTable.correctDistance(row[i])) << alignment << row[i];
            ostream << textTable.vertical;
        }
        ostream << "\n";
        if (textTable.has_ruler) {
            ostream << textTable.ruler() << "\n";
        }
    }

    return ostream;
}