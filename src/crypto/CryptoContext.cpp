#include "CryptoContext.h"
#include "Argon2KDF.h"
#include "ChaCha20Cipher.h"
#include <sodium.h>
#include <stdexcept>

CryptoContext::CryptoContext()
{
    if (sodium_init() < 0)
    {
        throw std::runtime_error("Failed to initialize libsodium");
    }
}

std::vector<unsigned char> CryptoContext::encrypt(const std::string &plaintext, const std::string &password)
{
    auto salt = Argon2KDF::generateSalt();
    auto key = Argon2KDF::deriveKey(password, salt);

    return ChaCha20Cipher::encrypt(plaintext, key, salt);
}

std::string CryptoContext::decrypt(const std::vector<unsigned char> &ciphertext, const std::string &password)
{
    auto salt = ChaCha20Cipher::extractSalt(ciphertext);
    auto key = Argon2KDF::deriveKey(password, salt);

    return ChaCha20Cipher::decrypt(ciphertext, key);
}