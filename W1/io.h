/* Citation and Sources...
-----------------------------------------------------------
Workshop 1
Module: io
Filename: io.cpp
-----------------------------------------------------------
Author: Itisarani Maity
Student number: 170077234
Email: imaity@myseneca.ca
Subject: OOP244 NDD
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SENECA_IO_H
#define SENECA_IO_H

#include <cstdio>
#include <cstddef>

namespace seneca {

    struct PhoneRec {
        char m_name[16];
        char m_lastName[26];
        long long m_phoneNumber;
    };


    void read(char* name);
    void print(long long phone);
    void print(const PhoneRec& rec, size_t& row, const char* filter = nullptr);
    bool read(PhoneRec& rec, FILE* fptr);
    void print(PhoneRec* recs[], size_t size, const char* filter = nullptr);
    void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size);
    void sort(PhoneRec* recs[], size_t size, bool sortByLastName);

}

#endif

