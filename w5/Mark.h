/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File	Mark.h
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
#ifndef SENECA_MARK_H
#define SENECA_MARK_H
#include <iostream>
#include <fstream>

const char GPA = 'G';
const char MARK = 'M';
const char GRADE = 'R';

namespace seneca {
    class Mark {
        char m_grade[3]{};
        double m_value;
        char m_type;
        bool isValid() const;

    public:
        Mark(int value = 0, char type = 'M');
        Mark(double value);

        Mark& operator+=(const Mark& other);
        Mark& operator-=(const Mark& other);
        Mark operator+(const Mark& other) const;
        Mark operator-(const Mark& other) const;
        Mark& operator/=(int other);
        Mark operator/(int other) const;
        Mark& operator=(int value);
        Mark& operator=(char type);
        double raw() const;
        operator int() const;
        operator double() const;
        operator const char* () const;
        operator bool() const;
        std::ostream& display(std::ostream& os = std::cout) const;

        friend double operator/(double value, const Mark& M);
        friend int operator/(int value, const Mark& M);
    };

    std::ostream& display(const Mark& m, char type, std::ostream& os = std::cout);
    std::ostream& operator<<(std::ostream& os, const Mark& m);
    std::istream& operator>>(std::istream& is, Mark& m);
    std::ifstream& operator>>(std::ifstream& ifs, Mark& m);
    double operator+(double value, const Mark& M);
    int operator+(int value, const Mark& M);
    double operator-(double value, const Mark& M);
    int operator-(int value, const Mark& M);
}

#endif // !SENECA_MARK_H
