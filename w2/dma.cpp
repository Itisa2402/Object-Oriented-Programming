/* Citation and Sources...
-----------------------------------------------------------
Workshop 2
Module: dma
Filename: dma.cpp
-----------------------------------------------------------
Author: Itisarani maity
Student number: 17077234
Email: imaity@myseneca.ca
Subject: OOP244-NDD
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.1    2025/30/5  Start code
V0.2    2025/30/5 clean up code and run

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "dma.h"
#include <new>   // For std::nothrow

namespace seneca {

    // Helper: Manual strlen replacement
    int str_len(const char* str) {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    // Helper: Manual strcpy replacement
    void str_cpy(char* dest, const char* src) { 
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    Samples* CreateSamples(const char* title) {
        Samples* s = new(std::nothrow) Samples;
        if (s) {
            int len = str_len(title);
            s->m_title = new(std::nothrow) char[len + 1];
            if (s->m_title) {
                str_cpy(s->m_title, title);
            }
            s->m_data = nullptr;
            s->m_size = 0;
        }
        return s;
    }

    void append(int*& data, int size, const int appendedData[], int dataSize) {
        int* newData = new(std::nothrow) int[size + dataSize];
        if (newData) {
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            for (int i = 0; i < dataSize; ++i) {
                newData[size + i] = appendedData[i];
            }
            delete[] data;
            data = newData;
        }
    }

    void add(Samples& S, const int data[], int size) {
        if (S.m_data == nullptr) {
            S.m_data = new(std::nothrow) int[size];
            if (S.m_data) {
                for (int i = 0; i < size; ++i) {
                    S.m_data[i] = data[i];
                }
                S.m_size = size;
            }
        }
        else {
            append(S.m_data, S.m_size, data, size);
            S.m_size += size;
        }
    }

    void freemem(Samples*& s) {
        if (s) {
            delete[] s->m_title;
            delete[] s->m_data;
            delete s;
            s = nullptr;
        }
    }

}
