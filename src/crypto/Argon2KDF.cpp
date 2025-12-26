#include "Argon2KDF.h"
#include <sodium.h>
#include <stdexcept>

std::vector<unsigned char> Argon2KDF::generateSalt()
{
    std::vector<unsigned char> salt(crypto_pwhash_SALTBYTES);
    randombytes_buf(salt.data(), salt.size());

    return salt;
}

std::vector<unsigned char> Argon2KDF::deriveKey(const std::string &password, const std::vector<unsigned char> &salt)
{
    std::vector<unsigned char> key(crypto_aead_chacha20poly1305_ietf_KEYBYTES);
    if (crypto_pwhash(key.data(), key.size(), password.c_str(), password.length(), salt.data(),
                      crypto_pwhash_OPSLIMIT_MODERATE, crypto_pwhash_MEMLIMIT_MODERATE, crypto_pwhash_ALG_ARGON2ID13) != 0)
    {
        throw std::runtime_error("Key derivation failed");
    }

    return key;
}
