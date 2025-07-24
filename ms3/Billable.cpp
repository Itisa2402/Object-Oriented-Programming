#include <cstring>
#include <fstream>
#include "Billable.h"
#include "Utils.h"

using namespace std;

namespace seneca {
    void Billable::name(const char* name) {
        ut.alocpy(m_name, name);
    }

    void Billable::price(double value) {
        m_price = value;
    }

    Billable::Billable() {}

    Billable::Billable(const Billable& other) {
        *this = other;
    }

    Billable& Billable::operator=(const Billable& other) {
        if (this != &other) {
            ut.alocpy(m_name, other.m_name);
            m_price = other.m_price;
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
    }

    double Billable::price() const {
        return m_price;
    }

    Billable::operator const char* () const {
        return m_name;
    }

    double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        return (money += B.price());
    }
}
