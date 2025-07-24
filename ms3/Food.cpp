#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "Food.h"
#include "Utils.h"
#include "Menu.h"

using namespace std;

namespace seneca {

    Food::Food() : m_ordered(false), m_child(false), m_customize(nullptr) {}

    Food::Food(const Food& src) : Billable(src) {
        *this = src;
    }

    Food& Food::operator=(const Food& src) {
        if (this != &src) {
            Billable::operator=(src);
            m_ordered = src.m_ordered;
            m_child = src.m_child;
            ut.alocpy(m_customize, src.m_customize);
        }
        return *this;
    }

    Food::~Food() {
        delete[] m_customize;
    }

    ostream& Food::print(ostream& ostr) const {
        ostr.setf(ios::left);
        ostr.width(28);
        ostr.fill('.');
        ostr << (const char*)(*this);
        ostr.fill(' ');
        if (m_ordered) {
            ostr << (m_child ? "Child" : "Adult"); // ✅ FIXED: Removed width(6)
        }
        else {
            ostr << ".....";
        }
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr.width(7);
        ostr << right << price();
        ostr.unsetf(ios::right);
        if (m_customize && &ostr == &cout) {
            ostr << " >> ";
            for (int i = 0; i < 30 && m_customize[i]; i++) ostr << m_customize[i];
        }
        return ostr; // no endl to avoid extra newlines
    }

    bool Food::order() {
        Menu sizeMenu("Food Size Selection", "Back", 1, 5);
        sizeMenu << "Adult" << "Child";
        size_t sel = sizeMenu.select();
        if (sel == 0) {
            m_ordered = false;
            m_child = false;
            delete[] m_customize;
            m_customize = nullptr;
            return false;
        }
        m_ordered = true;
        m_child = (sel == 2);

        cout << "Special instructions" << endl << "> ";
        std::string line;
        std::getline(std::cin, line);
        if (!line.empty()) {
            ut.alocpy(m_customize, line.c_str());
        }
        else {
            delete[] m_customize;
            m_customize = nullptr;
        }
        return true;
    }

    bool Food::ordered() const {
        return m_ordered;
    }

    ifstream& Food::read(ifstream& file) {
        char name[100]{};
        double val = 0.0;
        if (file.getline(name, 100, ',') && file >> val) {
            file.ignore(1000, '\n');
            Billable::name(name);
            Billable::price(val);
            m_ordered = false;
            m_child = false;
            delete[] m_customize;
            m_customize = nullptr;
        }
        return file;
    }

    double Food::price() const {
        return m_ordered && m_child ? Billable::price() * 0.5 : Billable::price();
    }
}
