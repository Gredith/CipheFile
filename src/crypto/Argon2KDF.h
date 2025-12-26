#pragma once

#include <string>
#include <vector>

class Argon2KDF
{
public:
    static std::vector<unsigned char> generateSalt();

    static std::vector<unsigned char> deriveKey(const std::string &password, const std::vector<unsigned char> &salt);
};