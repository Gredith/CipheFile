#include "ChaCha20Cipher.h"
#include <sodium.h>
#include <stdexcept>

std::vector<unsigned char> ChaCha20Cipher::encrypt(const std::string &plaintext, const std::vector<unsigned char> &key,
                                                   const std::vector<unsigned char> &salt)
{
    std::vector<unsigned char> nonce(crypto_aead_chacha20poly1305_ietf_NPUBBYTES);
    randombytes_buf(nonce.data(), nonce.size());

    std::vector<unsigned char> ciphertext(salt.size() + nonce.size() + plaintext.size() +
                                          crypto_aead_chacha20poly1305_ietf_ABYTES);

    // Formato: [salt | nonce | data]
    std::copy(salt.begin(), salt.end(), ciphertext.begin());
    std::copy(nonce.begin(), nonce.end(), ciphertext.begin() + salt.size());

    unsigned long long cipher_len;

    crypto_aead_chacha20poly1305_ietf_encrypt(ciphertext.data() + salt.size() + nonce.size(), &cipher_len,
                                              reinterpret_cast<const unsigned char *>(plaintext.data()),
                                              plaintext.size(), nullptr, 0, nullptr, nonce.data(), key.data());

    return ciphertext;
}

std::string ChaCha20Cipher::decrypt(const std::vector<unsigned char> &ciphertext, const std::vector<unsigned char> &key)
{
    const size_t salt_size = crypto_pwhash_SALTBYTES;
    const size_t nonce_size = crypto_aead_chacha20poly1305_ietf_NPUBBYTES;

    std::vector<unsigned char> nonce(ciphertext.begin() + salt_size, ciphertext.begin() + salt_size + nonce_size);
    std::vector<unsigned char> decrypted(ciphertext.size() - crypto_pwhash_SALTBYTES -
                                         crypto_aead_chacha20poly1305_ietf_NPUBBYTES -
                                         crypto_aead_chacha20poly1305_ietf_ABYTES);
    unsigned long long decrypted_len;

    if (crypto_aead_chacha20poly1305_ietf_decrypt(decrypted.data(), &decrypted_len, nullptr,
                                                  ciphertext.data() + salt_size + nonce_size,
                                                  ciphertext.size() - salt_size - nonce_size,
                                                  nullptr, 0, nonce.data(), key.data()) != 0)
    {
        throw std::runtime_error("Decryption failed");
    }

    return std::string(decrypted.begin(), decrypted.begin() + decrypted_len);
}

std::vector<unsigned char> ChaCha20Cipher::extractSalt(const std::vector<unsigned char> &ciphertext)
{
    return std::vector<unsigned char>(ciphertext.begin(), ciphertext.begin() + crypto_pwhash_SALTBYTES);
}
