/***********************************************************************
// OOP244 Workshop 6 lab
// File	Numbers.cpp
// Version 1.0
// Author:- Itisarani Maity
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Numbers.h"

using namespace std;

namespace seneca {

    // Count number of lines in the file (number of doubles)
    int Numbers::numberCount() const {
        ifstream file(m_filename);
        int itisa = 0;
        char ch;
        while (file.get(ch)) {
            if (ch == '\n') {
                itisa++;
            }
        }
        return itisa;
    }

    // Load numbers from the file into m_numbers array
    bool Numbers::load() {
        bool success = false;
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);
            int i = 0;
            while (file && i < m_numCount) {
                file >> m_numbers[i];
                if (!file.fail()) {
                    i++;
                }
            }
            if (i == m_numCount) {
                success = true;
            }
            else {
                delete[] m_numbers;
                m_numbers = nullptr;
                setEmpty();
            }
        }
        return success;
    }

    // Save numbers to file (only if original)
    void Numbers::save() const {
        if (m_isOriginal && !isEmpty()) {
            ofstream file(m_filename);
            for (int i = 0; i < m_numCount; ++i) {
                file << m_numbers[i] << endl;
            }
        }
    }

    // Destructor
    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    // Copy Constructor
    Numbers::Numbers(const Numbers& other) {
        setEmpty();
        m_isOriginal = false;
        if (!other.isEmpty()) {
            m_numCount = other.m_numCount;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; ++i) {
                m_numbers[i] = other.m_numbers[i];
            }
        }
    }

    // Copy Assignment Operator
    Numbers& Numbers::operator=(const Numbers& other) {
        if (this != &other) {
            delete[] m_numbers;
            m_numbers = nullptr;
            m_numCount = 0;
            if (!other.isEmpty()) {
                m_numCount = other.m_numCount;
                m_numbers = new double[m_numCount];
                for (int i = 0; i < m_numCount; ++i) {
                    m_numbers[i] = other.m_numbers[i];
                }
            }
        }
        return *this;
    }

    // Add one number to the array (resizing)
    Numbers& Numbers::operator+=(double value) {
        if (!isEmpty()) {
            double* temp = new double[m_numCount + 1];
            for (int i = 0; i < m_numCount; ++i) {
                temp[i] = m_numbers[i];
            }
            temp[m_numCount] = value;
            delete[] m_numbers;
            m_numbers = temp;
            m_numCount++;
            sort();
        }
        return *this;
    }

    // Display function
    ostream& Numbers::display(ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Empty list";
        }
        else {
            ostr << fixed << setprecision(2);
            ostr << "=========================" << endl;
            if (m_isOriginal && m_filename) {
                ostr << m_filename << endl;
            }
            else {
                ostr << "*** COPY ***" << endl;
            }
            for (int i = 0; i < m_numCount; ++i) {
                ostr << m_numbers[i];
                if (i < m_numCount - 1) ostr << ", ";
            }
            ostr << endl;
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average:         " << average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }

    // Operator overloads
    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    }

    istream& operator>>(istream& istr, Numbers& N) {
        double val;
        istr >> val;
        if (!istr.fail()) {
            N += val;
        }
        return istr;
    }

}
