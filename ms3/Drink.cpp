    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include "Drink.h"
    #include "Utils.h"
    #include "Menu.h"

    using namespace std;

    namespace seneca {
        Drink::Drink() : m_size(0) {}

        ostream& Drink::print(ostream& ostr) const {
            ostr.setf(ios::left);
            ostr.width(28);
            ostr.fill('.');
            ostr << (const char*)(*this);
            ostr.fill(' ');
            switch (m_size) {
            case 'S': ostr << "SML.."; break;
            case 'M': ostr << "MID.."; break;
            case 'L': ostr << "LRG.."; break;
            case 'X': ostr << "XLR.."; break;
            default:  ostr << "....."; break;
            }
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr.width(7);
            ostr << right << price();
            ostr.unsetf(ios::right);
            return ostr; // Removed endl to control line breaks manually
        }

        bool Drink::order() {
            Menu sizeMenu("Drink Size Selection", "Back", 1, 5);
            sizeMenu << "Small" << "Medium" << "Large" << "Extra Large";
            size_t sel = sizeMenu.select();
            switch (sel) {
            case 1: m_size = 'S'; break;
            case 2: m_size = 'M'; break;
            case 3: m_size = 'L'; break;
            case 4: m_size = 'X'; break;
            default: m_size = 0; break;
            }
            return m_size != 0;
        }

        bool Drink::ordered() const {
            return m_size != 0;
        }

        ifstream& Drink::read(ifstream& file) {
            char name[100]{};
            double val = 0.0;
            if (file.getline(name, 100, ',') && file >> val) {
                file.ignore(1000, '\n');
                Billable::name(name);
                Billable::price(val);
                m_size = 0;
            }
            return file;
        }

        double Drink::price() const {
            double base = Billable::price();
            switch (m_size) {
            case 'S': return base * 0.5;
            case 'M': return base * 0.75;
            case 'X': return base * 1.5;
            default:  return base;
            }
        }
    }