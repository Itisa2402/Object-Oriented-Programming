/***********************************************************************
// OOP244 Project/workshop, LblShape.h
//
// File	LblShape.h
// Author Itisarani Maity
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Itisarani Maity      25-7            
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include "Shape.h"
#include "Utils.h"

namespace seneca {
    class LblShape : public Shape {
        char* m_label{};
    protected:
        const char* label() const { return m_label; }
    public:
        LblShape() = default;
        LblShape(const char* label) { ut.alocpy(m_label, label); }
        ~LblShape() override { delete[] m_label; }

        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;

        void getSpecs(std::istream& is) override {
            char temp[81];
            is.getline(temp, 81, ',');
            ut.alocpy(m_label, temp);
        }
    };
}

#endif