#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include "core/FileManager.h"
#include "crypto/CryptoContext.h"
using namespace std;

void printHex(const std::vector<unsigned char> &data)
{
    std::cout << "Contenido cifrado (hex):\n";
    for (unsigned char byte : data)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)byte << " ";
    }
    std::cout << std::dec << "\n";
}

int main(int argc, char *argv[])
{
    // try
    // {
    //     CryptoContext crypto;

    //     std::string password = "password_segura";
    //     std::string inputFile = "test.txt";
    //     std::string encryptedFile = "test.cip";
    //     std::string outputFile = "test_out.txt";

    //     // 1️⃣ Leer archivo original
    //     std::string plaintext = FileManager::readTextFile(inputFile);

    //     // 2️⃣ Cifrar
    //     auto encrypted = crypto.encrypt(plaintext, password);
    //     FileManager::writeBinaryFile(encryptedFile, encrypted);

    //     std::cout << "✔ Archivo cifrado correctamente\n";

    //     // 3️⃣ Leer archivo cifrado
    //     auto encryptedFromFile = FileManager::readBinaryFile(encryptedFile);

    //     // 4️⃣ Descifrar
    //     std::string decrypted = crypto.decrypt(encryptedFromFile, password);
    //     FileManager::writeTextFile(outputFile, decrypted);

    //     std::cout << "✔ Archivo descifrado correctamente\n";

    //     // 5️⃣ Verificación final
    //     if (plaintext == decrypted)
    //     {
    //         std::cout << "✅ PRUEBA EXITOSA: El contenido coincide\n";
    //     }
    //     else
    //     {
    //         std::cout << "❌ ERROR: El contenido no coincide\n";
    //     }
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "💥 Error: " << e.what() << '\n';
    // }

    try
    {
        if (argc != 4)
        {
            std::cerr << "Uso:\n"
                      << "  CipheFile encrypt <input.txt> <output.cip>\n"
                      << "  CipheFile decrypt <input.cip> <output.txt>\n";
            return 1;
        }

        std::string mode = argv[1];
        std::string inputPath = argv[2];
        std::string outputPath = argv[3];
        std::string password;
        std::cout << "Ingrese la contraseña: ";
        std::getline(std::cin, password);

        CryptoContext crypto;

        if (mode == "encrypt")
        {
            auto plaintext = FileManager::readTextFile(inputPath);
            auto encrypted = crypto.encrypt(plaintext, password);
            FileManager::writeBinaryFile(outputPath, encrypted);

            std::cout << "Archivo cifrado generado: " << outputPath << "\n";
            printHex(encrypted);
        }
        else if (mode == "decrypt")
        {
            auto encrypted = FileManager::readBinaryFile(inputPath);
            auto decrypted = crypto.decrypt(encrypted, password);
            FileManager::writeTextFile(outputPath, decrypted);

            std::cout << "Archivo descifrado generado: " << outputPath << "\n";
            std::cout << "Contenido descifrado:\n";
            std::cout << decrypted << "\n";
        }
        else
        {
            std::cerr << "Modo inválido. Use encrypt o decrypt.\n";
            return 1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
