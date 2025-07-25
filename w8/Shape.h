/***********************************************************************
// OOP244 Project/workshop, Shape.h
//
// File	Shape.h
// Author Itisarani Maity
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Itisarani Maity      25-7
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

namespace seneca {
    class Shape {
    public:
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& is) = 0;
        virtual ~Shape() = default;
    };

    inline std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        shape.draw(os);
        return os;
    }

    inline std::istream& operator>>(std::istream& is, Shape& shape) {
        shape.getSpecs(is);
        return is;
    }
}

#endif