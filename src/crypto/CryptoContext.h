#pragma once

#include <string>
#include <vector>

class CryptoContext
{
public:
    CryptoContext();

    std::vector<unsigned char> encrypt(const std::string &plaintext, const std::string &password);

    std::string decrypt(const std::vector<unsigned char> &ciphertext, const std::string &password);
};
