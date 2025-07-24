#include <iostream>
#include <iomanip>
#include "Professor.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    Professor::Professor(const char* name, const char* subject, int numSections, size_t empNo, double salary)
        : Employee(name, empNo, salary), m_subject(ut.alocpy(subject)), m_numSections(numSections) {
    }

    Professor::~Professor() {
        delete[] m_subject;
    }

    double Professor::devPay() const {
        return salary() * 0.01 * m_numSections;
    }

    istream& Professor::read(istream& istr) {
        char temp[1024]{};
        Employee::read(istr);
        istr.ignore();  // skip comma
        istr.getline(temp, 1024, ',');
        ut.alocpy(m_subject, temp);
        istr >> m_numSections;
        return istr;
    }

    ostream& Professor::write(ostream& ostr) const {
        char subjectOut[21]{};
        if (m_subject) ut.strcpy(subjectOut, m_subject, 20);

        Employee::write(ostr);
        ostr << " ";

        ostr.setf(ios::left);
        ostr.width(21);
        ostr << subjectOut;
        ostr.unsetf(ios::left);
        ostr << "| ";

        ostr.setf(ios::right);
        ostr.width(5);
        ostr << m_numSections << " | ";

        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr.width(8);
        ostr << devPay() << " |";
        ostr.unsetf(ios::right | ios::fixed);

        return ostr;
    }

    ostream& Professor::title(ostream& ostr) const {
        return ostr << "| Name            | Emp No | $alary | Teaching Subject     | Sec # | $Dev Pay |";
    }

    ostream& operator<<(ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }

    istream& operator>>(istream& istr, Professor& P) {
        return P.read(istr);
    }

}
