#ifndef TOOLS_H
#define TOOLS_H

#include <cstdint>
#include <iostream>

extern int Table_C[9][4];
extern int Table_S[9][4];
extern char Table_logic[9][4];


struct Result {
    uint16_t Y1;
    uint16_t Y2;
    uint16_t Y3;
    uint16_t Y4;
};


namespace Tools {
    uint16_t shift(uint16_t num, int step);
    Result iteration(int round, int iter, uint16_t X1, uint16_t X2, uint16_t X3, uint16_t X4, uint16_t KRn, uint8_t operation);
};


#endif // TOOLS_H