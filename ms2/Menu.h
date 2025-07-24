/***********************************************************************
// Final Project Milestone 2
// Module: Menu
// File: Menu.h
// Version 1.0
// Author: Itisarani Maity
// ID: 170077234
// Email: imaity@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Date      Reason
// 2025/07/04  Completed MS2 - Menu implementation
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "constants.h"

namespace seneca {
    class Menu;

    class MenuItem {
        char* m_content{};
        unsigned m_indent{};
        unsigned m_indentSize{};
        int m_row{};
        void setEmpty();
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        MenuItem() = delete;
    public:
        MenuItem(const char* content, unsigned indent, unsigned indentSize, int row);
        ~MenuItem();
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
        friend class Menu;
    };

    class Menu {
        unsigned m_indent{};
        unsigned m_indentSize{};
        size_t m_numItems{};
        MenuItem m_title;
        MenuItem m_exit;
        MenuItem m_prompt;
        MenuItem* m_items[MaximumNumberOfMenuItems]{};
    public:
        Menu(const char* title, const char* exit = "Exit", unsigned indent = 0, unsigned indentSize = 3);
        ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        Menu& operator<<(const char* content);
        size_t select() const;
        operator bool() const;
    };

    size_t operator<<(std::ostream& ostr, const Menu& m);
}
#endif // SENECA_MENU_H
