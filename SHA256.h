#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <vector>
#include <cstdint>

class SHA256 {
public:
    static std::string hash(const std::string& input);

private:
    static const uint32_t K[64];
    static uint32_t rotr(uint32_t x, uint32_t n);
    static uint32_t sig0(uint32_t x);
    static uint32_t sig1(uint32_t x);
    static uint32_t SIG0(uint32_t x);
    static uint32_t SIG1(uint32_t x);
};

#endif // SHA256_H