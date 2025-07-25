/***********************************************************************
// OOP244 Project/workshop, Rectangle.h
//
// File	Rectangle.h
// Author Itisarani Maity
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Itisarani Maity      25-7
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {
    class Rectangle : public LblShape {
        int m_width{};
        int m_height{};
    public:
        Rectangle() = default;
        Rectangle(const char* label, int width, int height) : LblShape(label) {
            m_height = height < 3 ? 3 : height;
            int maityWidth = ut.strlen(label) + 2;
            m_width = width < maityWidth ? maityWidth : width;
        }
        void draw(std::ostream& os) const override {
            if (m_width > 0 && m_height > 0 && label()) {
                os << "+" << std::string(m_width - 2, '-') << "+" << std::endl;
                os << "|";
                os.width(m_width - 2);
                os.setf(std::ios::left);
                os.fill(' ');
                os << label();
                os.unsetf(std::ios::left);
                os << "|" << std::endl;
                for (int i = 0; i < m_height - 3; ++i) {
                    os << "|" << std::string(m_width - 2, ' ') << "|" << std::endl;
                }
                os << "+" << std::string(m_width - 2, '-') << "+";
            }
        }
        void getSpecs(std::istream& is) override {
            LblShape::getSpecs(is);
            is >> m_width;
            is.ignore();
            is >> m_height;
            is.ignore(1000, '\n');
        }
    };
}

#endif