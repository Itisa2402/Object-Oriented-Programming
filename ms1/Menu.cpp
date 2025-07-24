/***********************************************************************
// Final Project Milestone 1
// Module: Menu
// File: Menu.cpp
// Version 1.0
// Author: Itisarani Maity
// ID: 170077234
// Email: imaity@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/07/04  Completed MS1 - MenuItem implementation
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include "Menu.h"
#include "Utils.h"
#include "constants.h"

using namespace std;

namespace seneca {

    void MenuItem::setEmpty() {
        delete[] m_content;
        m_content = nullptr;
        m_indent = 0;
        m_indentSize = 0;
        m_row = -1;
    }

    MenuItem::MenuItem(const char* content, unsigned indent, unsigned indentSize, int row) {
        if (!content || ut.isspace(content) || indent > 4 || indentSize > 4 || row > (int)MaximumNumberOfMenuItems) {
            setEmpty();
        }
        else {
            m_content = ut.alocpy(content);
            m_indent = indent;
            m_indentSize = indentSize;
            m_row = row;
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        return m_content != nullptr;
    }

    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (*this) {
            for (unsigned itisa = 0; itisa < m_indent * m_indentSize; ++itisa) ostr << ' ';
            if (m_row >= 0) {
                ostr.width(2);
                ostr.setf(ios::right);
                ostr << m_row << "- ";
                ostr.unsetf(ios::right);
            }
            const char* maity = m_content;
            while (*maity && ut.isspace(*maity)) ++maity;
            ostr << maity;
        }
        else {
            ostr << "??????????";
        }
        return ostr;
    }

}
