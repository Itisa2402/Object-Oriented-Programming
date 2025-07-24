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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "io.h"
#include "cstr.h"

using namespace std;

namespace seneca {

    void read(char* name) {
        cout << "Name\n";
        cout << "> ";
        cin >> name;
    }

    void print(long long phone) {
        cout << "(" << (phone / 10000000) % 1000 << ") "
            << (phone / 10000) % 1000 << "-"
            << phone % 10000;
    }

    void print(const PhoneRec& rec, size_t& row, const char* filter) {
        if (filter == nullptr ||
            strstr(rec.m_name, filter) != nullptr ||
            strstr(rec.m_lastName, filter) != nullptr) {

            cout << row << ": " << rec.m_name << " " << rec.m_lastName << " ";
            print(rec.m_phoneNumber);
            cout << endl;
            row++;
        }
    }

    bool read(PhoneRec& rec, FILE* fptr) {
        return fscanf(fptr, "%s %s %lld",
            rec.m_name, rec.m_lastName, &rec.m_phoneNumber) == 3;
    }

    void print(PhoneRec* recs[], size_t size, const char* filter) {
        size_t r = 1;
        for (size_t i = 0; i < size; i++) {
            print(*recs[i], r, filter);
        }
    }

    void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size) {
        for (size_t p = 0; p < size; p++) {
            ptrs[p] = &recs[p];
        }
    }

    void sort(PhoneRec* recs[], size_t size, bool sortByLastName) {
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = i + 1; j < size; j++) {
                const char* key1 = sortByLastName ? recs[i]->m_lastName : recs[i]->m_name;
                const char* key2 = sortByLastName ? recs[j]->m_lastName : recs[j]->m_name;
                if (strcmp(key1, key2) > 0) {
                    PhoneRec* temp = recs[i];
                    recs[i] = recs[j];
                    recs[j] = temp;
                }
            }
        }
    }

}