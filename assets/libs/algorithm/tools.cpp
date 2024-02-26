#include "tools.h"

namespace Tools
{
int Table_C[9][4] = {
    {0xAC25, 0x8A93, 0x243D, 0x262E},
    {0xF887, 0xC4F2, 0x8E36, 0x9FA1},
    {0x7DC0, 0x6A29, 0x6D84, 0x34BD},
    {0xA267, 0xCC15, 0x04FE, 0xB94A},
    {0xDF24, 0x40EF, 0x96DA, 0x905F},
    {0xD631, 0xAA62, 0x4D15, 0x70CB},
    {0x7533, 0x45FC, 0x5337, 0xD25E},
    {0xA926, 0x1C7B, 0x5F12, 0x4ECC},
    {0x3C86, 0x28DB, 0xFC01, 0x7CB1}
};

int Table_S[9][4] = {
    { 4,  7, 11,  8},
    { 7, 14,  5,  4},
    { 8,  2,  9,  4},
    {13,  1, 14,  6},
    { 7, 12,  5,  1},
    { 2,  4, 12,  3},
    { 9,  2, 11, 13},
    {12,  3,  6, 11},
    { 7, 15,  4, 14}
};

char Table_logic[9][4] = {
    {'&','|','&','|',},
    {'|','|','|','|',},
    {'&','|','|','&',},
    {'|','&','|','|',},
    {'|','|','&','&',},
    {'&','&','&','|',},
    {'&','|','|','|',},
    {'&','|','&','&',},
    {'|','|','&','|',}
};


uint16_t shift(uint16_t num, int step) {
    return (num >> step) | ((num << (16 - step)));
}


Result iteration(int round, int iter, uint16_t X1, uint16_t X2, uint16_t X3, uint16_t X4, uint16_t KRn, uint8_t operation) {
    uint16_t temp, Y1, Y2, Y3, Y4;
    uint16_t k = KRn + Table_C[round][iter];

    switch (operation) {
        case 0:
            Y3 = shift(X2 + (X3 ^ k), Table_S[round][iter]);
            if (Table_logic[round][iter] == '&') temp = Y3 & X4;
            else temp = Y3 | X4;
            Y1 = X1 + temp;

            Y2 = X2;
            Y4 = X4;
            break;
        
        case 1:
            Y4 = X4;
            Y2 = X2;

            if (Table_logic[round][iter] == '&') temp = X3 & X4;
            else temp = X3 | X4;
            Y1 = X1 - temp;

            Y3 = (shift(X3, (16 - Table_S[round][iter])) - X2) ^ k;
            break;
    }

    return {Y1, Y2, Y3, Y4};
}
}
