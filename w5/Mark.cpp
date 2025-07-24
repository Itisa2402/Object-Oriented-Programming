/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File	Mark.cpp
// Version 1.0
// Date	2025/06/12
// Author	partially done by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: ITISARANI MAITY    Date: 04-07-2025           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include "Mark.h"
using namespace std;

namespace seneca {
    bool Mark::isValid() const {
        return (m_value >= 0 && m_value <= 100);
    }

    Mark::Mark(int value, char type) {
        *this = type;
        m_value = double(value);
    }

    Mark::Mark(double value) {
        m_type = MARK;
        m_value = value;
    }

    Mark& Mark::operator+=(const Mark& M) {
        m_value += M.m_value;
        return *this;
    }

    Mark& Mark::operator-=(const Mark& M) {
        m_value -= M.m_value;
        return *this;
    }

    Mark Mark::operator+(const Mark& M) const {
        return Mark(*this) += M;
    }

    Mark Mark::operator-(const Mark& M) const {
        return Mark(*this) -= M;
    }

    Mark& Mark::operator/=(int other) {
        m_value /= other;
        return *this;
    }

    Mark Mark::operator/(int other) const {
        return Mark(m_value / other);
    }

    Mark& Mark::operator=(int value) {
        m_value = value;
        return *this;
    }

    Mark& Mark::operator=(char type) {
        m_type = MARK;
        if (type == GRADE || type == GPA) {
            m_type = type;
        }
        return *this;
    }

    double Mark::raw() const {
        return m_value;
    }

    Mark::operator int() const {
        return isValid() ? int(round(m_value)) : -1;
    }

    Mark::operator double() const {
        return isValid() ? m_value * 0.04 : -1.0;
    }

    Mark::operator const char* () const {
        char* grade = const_cast<char*>(m_grade);
        int value = int(*this);
        grade[0] = grade[1] = grade[2] = '\0';

        if (value < 0 || value > 100) grade[0] = 'X';
        else if (value >= 90) grade[0] = 'A', grade[1] = '+';
        else if (value >= 80) grade[0] = 'A';
        else if (value >= 75) grade[0] = 'B', grade[1] = '+';
        else if (value >= 70) grade[0] = 'B';
        else if (value >= 65) grade[0] = 'C', grade[1] = '+';
        else if (value >= 60) grade[0] = 'C';
        else if (value >= 55) grade[0] = 'D', grade[1] = '+';
        else if (value >= 50) grade[0] = 'D';
        else grade[0] = 'F';
        return m_grade;
    }

    Mark::operator bool() const {
        return isValid();
    }

    ostream& Mark::display(ostream& os) const {
        if (!isValid()) {
            os << (m_type == GRADE ? "**" : "***");
        }
        else {
            os << fixed << setprecision(1);
            if (m_type == GPA) {
                os << setw(3) << double(*this);
            }
            else if (m_type == MARK) {
                os << right << setw(3) << setfill('_') << int(*this) << setfill(' ');
            }
            else if (m_type == GRADE) {
                os << left << setw(3) << static_cast<const char*>(*this);
            }
        }
        return os;
    }


    ostream& display(const Mark& m, char type, ostream& os) {
        Mark temp = m;
        os << temp;
        if (type != MARK) {
            temp = type;
            os << ": " << temp;
        }
        return os;
    }

    ostream& operator<<(ostream& os, const Mark& m) {
        return m.display(os);
    }

    istream& operator>>(istream& is, Mark& m) {
        int value;
        string line;
        while (true) {
            is >> ws;
            if (!(is >> value)) {
                is.clear();
                getline(is, line);
                cout << "Invalid integer, try again.\n> ";
                continue;
            }
            char next = is.peek();
            if (next != '\n' && next != ' ') {
                getline(is, line);
                cout << "Invalid trailing characters. Please enter only an integer.\n> ";
                continue;
            }
            if (value < 0 || value > 100) {
                getline(is, line);
                cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
                continue;
            }
            m = value;
            break;
        }
        return is;
    }

    ifstream& operator>>(ifstream& ifs, Mark& m) {
        int val;
        char type;
        char comma;
        ifs >> val >> comma >> type;
        if (ifs && comma == ',') {
            m = val;
            m = type;
        }
        return ifs;
    }

    double operator+(double value, const Mark& M) {
        return value + M.raw();
    }

    int operator+(int value, const Mark& M) {
        return value + int(M);
    }

    double operator-(double value, const Mark& M) {
        return value - M.raw();
    }

    int operator-(int value, const Mark& M) {
        return value - int(M);
    }

    double operator/(double value, const Mark& M) {
        return value / M.m_value;
    }

    int operator/(int value, const Mark& M) {
        return value / int(round(M.m_value));
    }
}
