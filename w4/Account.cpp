/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.h
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: ITISARANI MAITY       Date: 12-06-2025            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {

    void Account::cpyName(const char* src) {
        int maity;
        for (maity = 0; src && src[maity] && maity < NameMaxLen; maity++) {
            m_holderName[maity] = src[maity];
        }
        m_holderName[maity] = char(0);
    }

    bool Account::isValidNumber(int number) const {
        return number >= 10000 && number <= 99999;
    }

    Account::Account(const char* holderName) {
        m_holderName[0] = char(0);
        m_number = -1;
        m_balance = 0.0;
        if (holderName && holderName[0]) {
            cpyName(holderName);
            m_number = 0;
        }
    }

    Account::Account(const char* holderName, int number, double balance) {
        m_holderName[0] = char(0);
        m_number = -1;
        m_balance = 0.0;
        if (holderName && holderName[0] && isValidNumber(number)
            && balance > 0) {
            cpyName(holderName);
            m_number = number;
            m_balance = balance;
        }
    }

    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout.fill(' ');
            cout.width(NameMaxLen);
            cout.setf(ios::left);
            cout << m_holderName;
            cout.unsetf(ios::left);
            cout << " | ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << " ";
            cout.fill(' ');
            cout.width(30);
            cout.setf(ios::left);
            cout << m_holderName;
            cout.unsetf(ios::left);
            cout << " |  NEW  |         0.00 ";
        }
        else {
            cout << " Bad Account                    | ----- | ------------ ";
        }
        return cout;
    }

    // --- Member operator ---
    Account::operator bool() const {
        return m_number > 0;
    }

    Account::operator int() const {
        return m_number;
    }

    Account::operator double() const {
        return m_balance;
    }

    Account::operator const char* () const {
        return m_holderName;
    }

    char& Account::operator[](int index) {
        return m_holderName[index % NameMaxLen];
    }

    const char Account::operator[](int index) const {
        return m_holderName[index % NameMaxLen];
    }

    bool Account::operator~() const {
        return m_number == 0;
    }

    Account& Account::operator++() {
        if (*this) m_balance += 1.0;
        return *this;
    }

    Account Account::operator++(int) {
        Account temp = *this;
        if (*this) m_balance += 1.0;
        return temp;
    }

    Account& Account::operator--() {
        if (*this && m_balance >= 1.0) m_balance -= 1.0;
        return *this;
    }

    Account Account::operator--(int) {
        Account temp = *this;
        if (*this && m_balance >= 1.0) m_balance -= 1.0;
        return temp;
    }

    Account& Account::operator=(int number) {
        if (!*this && ~*this && isValidNumber(number)) {
            m_number = number;
        }
        else if (!isValidNumber(number)) {
            m_number = -1;
            m_holderName[0] = '\0';
            m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator=(double balance) {
        if (balance >= 0.0) {
            m_balance = balance;
        }
        else {
            m_number = -1;
            m_holderName[0] = '\0';
            m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator+=(double value) {
        if (*this && value >= 0.0) {
            m_balance += value;
        }
        return *this;
    }

    Account& Account::operator-=(double value) {
        if (*this && value >= 0.0 && m_balance >= value) {
            m_balance -= value;
        }
        return *this;
    }

    Account& Account::operator<<(Account& other) {
        if (this != &other && *this && other) {
            m_balance += other.m_balance;
            other.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& other) {
        if (this != &other && *this && other) {
            other.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }
}
