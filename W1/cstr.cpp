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
#include "cstr.h"
namespace seneca {
    // Concatenates the src string to the end of des string.
   // Assumes des has enough space to hold the result.
    char* strcat(char* des, const char* src) {
        size_t len = strlen(des);
        size_t i = 0;
        while (des && src && src[i]) {
            des[i + len] = src[i];
            i++;
        }
        des[i + len] = char(0); // Null-terminate the result
        return des;
    }

    // Converts an uppercase ASCII character to lowercase.
    // If ch is not uppercase, returns it unchanged.
    char tolower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += ('a' - 'A');
        }
        return ch;
    }

    // Converts all characters in src to lowercase and copies them into des.
    // Assumes des has enough space. Null-terminated.
    char* tolower(char* des, const char* src) {
        size_t i = 0;
        for (; des && src && src[i]; i++) {
            des[i] = tolower(src[i]);
        }
        des[i] = char(0);
        return des;
    }

    // Converts all characters in the input string `str` to lowercase in place.
    // Modifies the original string and returns the same pointer.
    char* tolower(char* str) {
        for (size_t i = 0; str && str[i]; i++) {
            str[i] = tolower(str[i]); // Uses the char version of tolower()
        }
        return str;
    }


    // Compares two C-style strings lexicographically.
    // Returns 0 if equal, <0 if s1 < s2, >0 if s1 > s2.
    int strcmp(const char* s1, const char* s2) {
        size_t i{};
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

    // Compares up to 'len' characters of two strings lexicographically.
    // Returns 0 if equal up to len, or first differing character diff.
    int strcmp(const char* s1, const char* s2, size_t len) {
        size_t i{};
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
            i++;
        }
        return s1[i] - s2[i];
    }

    // Copies src into des including null terminator.
    // Returns des. Assumes des has enough space.
    char* strcpy(char* des, const char* src) {
        size_t i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0);
        return des;
    }

    // Copies up to 'len' characters from src to des.
    // Always null-terminates des. Safer than std::strncpy.
    // Returns des.
    char* strcpy(char* des, const char* src, size_t len) {
        size_t i;
        for (i = 0; i < len && src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = 0; // Ensures null-termination
        return des;
    }

    // Copies up to 'len' characters from src to des (like std::strncpy).
    // May not null-terminate if src is longer than len.
    // Returns des.
    char* strncpy(char* des, const char* src, size_t len) {
        size_t i = 0;
        while (i < len - 1 && src[i]) {
            des[i] = src[i];
            i++;
        }
        des[i] = src[i]; // Final char copied or null terminator
        return des;
    }

    // Returns the length of the C-style string str (excluding null).
    size_t strlen(const char* str) {
        size_t len{};
        for (len = 0; str && str[len]; len++);
        return len;
    }

    // Finds the first occurrence of toFind in str.
    // Returns pointer to the first match or nullptr if not found.
    const char* strstr(const char* str, const char* toFind) {
        const char* faddress = nullptr;
        size_t
            i,
            find_len = strlen(toFind),
            store_len = strlen(str);
        for (i = 0; find_len <= store_len && i <= store_len - find_len && strcmp(&str[i], toFind, find_len); i++);
        if (find_len <= store_len && i <= store_len - find_len) {
            faddress = &str[i];
        }
        return faddress;
    }

    // Returns true if ch is an alphabetic character (A-Z or a-z).
    bool isalpha(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    // Returns true if ch is a whitespace character.
    bool isspace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

}