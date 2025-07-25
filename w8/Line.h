/***********************************************************************
// OOP244 Project/workshop, Line.h
//
// File	Line.h
// Author Itisarani Maity
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Itisarani Maity      25-7
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"

namespace seneca {
    class Line : public LblShape {
        int m_length{};
    public:
        Line() = default;
        Line(const char* label, int length) : LblShape(label) {
            m_length = length < ut.strlen(label) ? ut.strlen(label) : length;
        }
        void draw(std::ostream& os) const override {
            if (m_length > 0 && label()) {
                os << label() << std::endl;
                os << std::string(m_length, '=');
            }
        }
        void getSpecs(std::istream& is) override {
            LblShape::getSpecs(is);
            is >> m_length;
            is.ignore(1000, '\n');
        }
    };
}

#endif