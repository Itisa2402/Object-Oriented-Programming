/***********************************************************************
// Final Project Milestone 1
// Module: Menu
// File: Menu.h
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
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
namespace seneca {
    class MenuItem {
        char* m_content{};
        unsigned m_indent{};
        unsigned m_indentSize{};
        int m_row{};
        void setEmpty();
    public:
        MenuItem(const char* content, unsigned indent, unsigned indentSize, int row);
        ~MenuItem();
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };
}

#endif // SENECA_MENU_H
