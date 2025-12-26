#pragma once

#include <string>
#include <vector>

class ChaCha20Cipher
{
public:
    static std::vector<unsigned char> encrypt(const std::string &plaintext, const std::vector<unsigned char> &key,
                                              const std::vector<unsigned char> &salt);

    static std::string decrypt(const std::vector<unsigned char> &ciphertext, const std::vector<unsigned char> &key);

    static std::vector<unsigned char> extractSalt(const std::vector<unsigned char> &ciphertext);
};
