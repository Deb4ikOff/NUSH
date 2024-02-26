#include "tools.h"

#include <iostream>
#include <cstdint>
#include <sstream>
#include <cstring>


using namespace Tools;

class Processor {
    private:
        void append(std::stringstream &s, uint16_t &x);
    public:
        std::stringstream logs;
        std::string encode(std::string msg, std::string key);
        std::string decode(std::string msg, std::string key);
};


void Processor::append(std::stringstream &s, uint16_t &x) {
    if (x >= 0x0010) {
        if (x >= 0x0100) {
            if (x >= 0x1000) s << std::hex << x;
            else s << std::hex << "0" << x;
        } else s << std::hex << "00" << x;
    }else s << std::hex << "000" << x;
}


std::string Processor::encode(std::string msg, std::string key) {
    // Первоначальные субблоки
    uint16_t a = msg[0] * 256 + msg[1];
    uint16_t b = msg[2] * 256 + msg[3];
    uint16_t c = msg[4] * 256 + msg[5];
    uint16_t d = msg[6] * 256 + msg[7];

    a += (a & 0xff) > 0x7f ? 0x100 : 0;
    b += (b & 0xff) > 0x7f ? 0x100 : 0;
    c += (c & 0xff) > 0x7f ? 0x100 : 0;
    d += (d & 0xff) > 0x7f ? 0x100 : 0;

    this->logs << "First subblocks" << std::endl;
    this->logs << "a\tb\tc\td" << std::endl;
    this->logs << std::hex << a << "\t" << b << "\t" << c << "\t" << d << "\n\n";

    // Расширение ключа
    uint16_t k[8] = {
        (uint16_t)(key[0] * 256 + key[1]),
        (uint16_t)(key[2] * 256 + key[3]),
        (uint16_t)(key[4] * 256 + key[5]),
        (uint16_t)(key[6] * 256 + key[7]),
        (uint16_t)(key[8] * 256 + key[9]),
        (uint16_t)(key[10] * 256 + key[11]),
        (uint16_t)(key[12] * 256 + key[13]),
        (uint16_t)(key[14] * 256 + key[15])
    };

    this->logs << "Extended key" << std::endl;
    this->logs << "KS0\tKS1\tKS2\tKS3\tKF0\tKF1\tKF2\tKF3" << std::endl;
    this->logs << std::hex << k[4] << "\t" << k[5] << "\t" << k[6] << "\t" << k[7] << "\t" << k[3] << "\t" << k[2] << "\t" << k[1] << "\t" << k[0] << "\n\n";


    // Превоначальное преобразование XOR
    a ^= k[4]; b ^= k[5]; c ^= k[6]; d ^= k[7];

    // 9 раундов по 4 итерации
    for (int round = 0; round < 9; round++) {
        for (int iter = 0; iter < 4; iter++) {
            Result R;
            switch (iter) {
                case 0:
                    R = iteration(round, iter, a, b, c, d, k[round % 8], 0);
                    a = R.Y1; b = R.Y2; c = R.Y3; d = R.Y4;
                    break;
                
                case 1:
                    R = iteration(round, iter, b, c, d, a, k[round % 8], 0);
                    b = R.Y1; c = R.Y2; d = R.Y3; a = R.Y4;
                    break;

                case 2:
                    R = iteration(round, iter, c, d, a, b, k[round % 8], 0);
                    c = R.Y1; d = R.Y2; a = R.Y3; b = R.Y4;
                    break;

                case 3:
                    R = iteration(round, iter, d, a, b, c, k[round % 8], 0);
                    d = R.Y1; a = R.Y2; b = R.Y3; c = R.Y4;
                    break;
            }
        }
    }
    // Финальное преобразование
    a ^= k[3]; b ^= k[2]; c ^= k[1]; d ^= k[0];

    this->logs << a << "\t" << b << "\t" << c << "\t" << d << "\t" << "\n\n";

    std::stringstream ss;
    append(ss, a);
    append(ss, b);
    append(ss, c);
    append(ss, d);

    if (a < 0x0100 || b < 0x0100 || c < 0x0100 || d < 0x0100) this->logs << "LESS THAN 0x100\n\n";

    //switch (a)

    this->logs << "Created: " << ss.str() << std::dec << "\t len: " << ss.str().length() << "\n\n";

    return ss.str();
}


std::string Processor::decode(std::string msg, std::string key) {
    uint64_t N = std::stoull(msg, nullptr, 16); // 64-битный блок данных
    // Первоначальные субблоки
    uint16_t a = (N & 0xffff'0000'0000'0000) / 0x0001'0000'0000'0000;
    uint16_t b = (N & 0x0000'ffff'0000'0000) / 0x0000'0001'0000'0000;
    uint16_t c = (N & 0x0000'0000'ffff'0000) / 0x0000'0000'0001'0000;
    uint16_t d = (N & 0x0000'0000'0000'ffff);

    this->logs << "First subblocks" << std::endl;
    this->logs << "a\tb\tc\td" << std::endl;
    this->logs << std::hex << a << "\t" << b << "\t" << c << "\t" << d << "\n\n";

    // Расширение ключа
    uint16_t k[8] = {
        (uint16_t)(key[0] * 256 + key[1]),
        (uint16_t)(key[2] * 256 + key[3]),
        (uint16_t)(key[4] * 256 + key[5]),
        (uint16_t)(key[6] * 256 + key[7]),
        (uint16_t)(key[8] * 256 + key[9]),
        (uint16_t)(key[10] * 256 + key[11]),
        (uint16_t)(key[12] * 256 + key[13]),
        (uint16_t)(key[14] * 256 + key[15])
    };

    this->logs << "Extended key" << std::endl;
    this->logs << "KS0\tKS1\tKS2\tKS3\tKF0\tKF1\tKF2\tKF3" << std::endl;
    this->logs << std::hex << k[4] << "\t" << k[5] << "\t" << k[6] << "\t" << k[7] << "\t" << k[3] << "\t" << k[2] << "\t" << k[1] << "\t" << k[0] << "\n\n";


    // Обратное преобразование
    a ^= k[3]; b ^= k[2]; c ^= k[1]; d ^= k[0];

    // 9 раундов по 4 итерации
    for (int round = 8; round >= 0; round--) {
        for (int iter = 3; iter >= 0; iter--) {
            Result R;
            switch (iter) {
                case 0:
                    R = iteration(round, iter, a, b, c, d, k[round % 8], 1);
                    a = R.Y1; b = R.Y2; c = R.Y3; d = R.Y4;
                    break;
                
                case 1:
                    R = iteration(round, iter, b, c, d, a, k[round % 8], 1);
                    b = R.Y1; c = R.Y2; d = R.Y3; a = R.Y4;
                    break;

                case 2:
                    R = iteration(round, iter, c, d, a, b, k[round % 8], 1);
                    c = R.Y1; d = R.Y2; a = R.Y3; b = R.Y4;
                    break;

                case 3:
                    R = iteration(round, iter, d, a, b, c, k[round % 8], 1);
                    d = R.Y1; a = R.Y2; b = R.Y3; c = R.Y4;
                    break;
            }
        }
    }

    // Финальное преобразование XOR
    a ^= k[4]; b ^= k[5]; c ^= k[6]; d ^= k[7];
    this->logs << a << "\t" << b << "\t" << c << "\t" << d << "\t" << "\n\n";

    std::stringstream ss;
    append(ss, a);
    append(ss, b);
    append(ss, c);
    append(ss, d);

    if (a < 0x0100 || b < 0x0100 || c < 0x0100 || d < 0x0100) this->logs << "LESS THAN 0x100\n\n";

    this->logs << "Created: " << ss.str() << std::dec << "\t len: " << ss.str().length() << "\n\n";

    std::string total_result;
    std::string res = ss.str();
    int len = ss.str().length();
    for (int i = 0; i < len; i+=2) {
        std::string tmp = std::string(1, res[i]) + res[i+1];
        total_result += char(std::stoi(tmp, nullptr, 16));
    }


    return total_result;
}
