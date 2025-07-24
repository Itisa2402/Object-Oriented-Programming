/***********************************************************************
// OOP244 Project, Utils Module
// File	Utils.h
// Version 0.2
// Author: Your Name
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Your Name       2025-07-04      Added getInt functions for MS2
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

namespace seneca {
    class Utils {
    public:
        char* alocpy(const char* src) const;
        char* alocpy(char*& des, const char* src) const;
        char* strcpy(char* des, const char* src) const;
        int strlen(const char* str) const;
        bool isspace(char ch) const;
        bool isspace(const char* cstring) const;
        int getInt() const;
        int getInt(int min, int max) const;
    };
    extern Utils ut;
}

#endif // !SENECA_UTILS_H
