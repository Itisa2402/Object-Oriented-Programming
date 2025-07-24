/* Citation and Sources...
-----------------------------------------------------------
Workshop 2
Module: dma
Filename: dma.h
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
#ifndef SENECA_DMA_H
#define SENECA_DMA_H

namespace seneca {

    struct Samples {
        char* m_title;
        int* m_data;
        int m_size;
    };

    Samples* CreateSamples(const char* title);
    void add(Samples& S, const int data[], int size);
    void append(int*& data, int size, const int appendedData[], int dataSize);
    void freemem(Samples*& s);

}

#endif // SENECA_DMA_H
