/***********************************************************************
// OOP244 Project, Utils Module
// File	Utils.cpp
// Version 0.2
// Author: Itisarani Maity
// ID: 170077234
// Email: imaity@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Your Name       2025-07-04      Added getInt functions for MS2
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <sstream> // for stringstream
#include "Utils.h"

using namespace std;

namespace seneca {
    Utils ut;

    char* Utils::alocpy(const char* src) const {
        char* des{};
        return alocpy(des, src);
    }

    char* Utils::alocpy(char*& des, const char* src) const {
        delete[] des;
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }

    char* Utils::strcpy(char* des, const char* src) const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = '\0';
        return des;
    }

    int Utils::strlen(const char* str) const {
        int len = 0;
        while (str && str[len]) len++;
        return len;
    }

    bool Utils::isspace(char ch) const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) {
            cstring++;
        }
        return cstring && *cstring == 0;
    }

    int Utils::getInt() const {
        int value;
        bool done = false;
        while (!done) {
            std::string line;
            std::getline(std::cin, line);

            if (line.empty()) {
                std::cout << "You must enter a value: ";
            }
            else {
                std::stringstream ss(line);
                ss >> value;

                if (ss.fail()) {
                    std::cout << "Invalid integer: ";
                }
                else {
                    char extra;
                    if (ss >> extra) {
                        std::cout << "Only an integer please: ";
                    }
                    else {
                        done = true;
                    }
                }
            }
        }
        return value;
    }

    int Utils::getInt(int min, int max) const {
        int value;
        do {
            value = getInt();
            if (value < min || value > max) {
                std::cout << "Invalid value: [" << min << "<= value <= " << max << "], try again: ";
            }
        } while (value < min || value > max);
        return value;
    }
}
