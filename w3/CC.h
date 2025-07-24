/*
-----------------------------------------------------------
Workshop 03
Module: CC
Filename: CC.h
-----------------------------------------------------------
Author: ITISARANI MAITY
Student number: 170077234
Email: imaity@myseneca.ca
Subject: OOP244NDD
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#ifndef SENECA_CC_H
#define SENECA_CC_H

#include <iostream>

namespace seneca {

    class CC {
        char* m_name{};
        unsigned long long m_number{};
        short m_cvv{};
        short m_expMon{};
        short m_expYear{};

        void aloCopy(const char* name);
        void dealloc();
        bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;
        void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
        void prnNumber(unsigned long long no) const;

    public:
        CC(); // default constructor
        CC(const char* name, unsigned long long number, short cvv); // 3-arg constructor
        CC(const char* name, unsigned long long number, short cvv, short expMon, short expYear); // 5-arg constructor
        ~CC(); // destructor

        void set();
        bool isEmpty() const;
        void set(const char* name, unsigned long long number, short cvv, short expMon, short expYear);
        void display() const;
    };

}

#endif // !SENECA_CC_H
