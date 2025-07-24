/***********************************************************************
// Final Project Milestone 2
// Module: Menu
// File: Menu.cpp
// Author: Itisarani Maity
// ID: 170077234
// Email: imaity@myseneca.ca
// Description: Corrected Menu.cpp to match output exactly
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
        if (!content || ut.isspace(content) || indent > 4 || indentSize > 4 || (row >= 0 && row > (int)MaximumNumberOfMenuItems)) {
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
            unsigned totalSpaces = m_indent * m_indentSize;
            ostr.width(totalSpaces);
            ostr.fill(' ');
            ostr << "";

            if (m_row >= 0) {
                if (m_row < 10) ostr << ' ';
                ostr << m_row << "- ";
            }

            const char* ptr = m_content;
            while (*ptr && ut.isspace(*ptr)) ++ptr;
            ostr << ptr;
        }
        else {
            ostr << "??????????";
        }
        return ostr;
    }

    Menu::Menu(const char* title, const char* exit, unsigned indent, unsigned indentSize)
        : m_indent(indent),
        m_indentSize(indentSize),
        m_numItems(0),
        m_title(title, indent, indentSize, -1),
        m_exit(exit, indent, indentSize, 0),
        m_prompt("> ", indent, indentSize, -1) {
        for (size_t i = 0; i < MaximumNumberOfMenuItems; ++i) {
            m_items[i] = nullptr;
        }
    }

    Menu::~Menu() {
        for (size_t i = 0; i < m_numItems; ++i) {
            delete m_items[i];
        }
    }

    Menu& Menu::operator<<(const char* content) {
        if (m_numItems < MaximumNumberOfMenuItems) {
            m_items[m_numItems] = new MenuItem(content, m_indent, m_indentSize, (int)m_numItems + 1);
            if (*m_items[m_numItems]) {
                ++m_numItems;
            }
            else {
                delete m_items[m_numItems];
                m_items[m_numItems] = nullptr;
            }
        }
        return *this;
    }

    size_t Menu::select() const {
        if (m_title) {
            m_title.display() << endl;
        }
        for (size_t i = 0; i < m_numItems; ++i) {
            if (m_items[i]) m_items[i]->display() << endl;
        }
        m_exit.display() << endl;
        m_prompt.display();
        return (size_t)ut.getInt(0, (int)m_numItems);
    }

    Menu::operator bool() const {
        return m_numItems > 0;
    }

    size_t operator<<(std::ostream& ostr, const Menu& m) {
        if (&ostr == &cout) {
            return m.select();
        }
        return 0;
    }
}
