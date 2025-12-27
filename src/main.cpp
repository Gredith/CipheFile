#include <iostream>
#include <string>
#include <cassert>
#include "core/FileManager.h"
#include "crypto/CryptoContext.h"
using namespace std;

int main()
{
    // try
    // {
    //     FileManager::writeTextFile("test.txt", "Hola mundo");
    //     string text = FileManager::readTextFile("test.txt");
    //     cout << text << endl;
    // }
    // catch (const exception &e)
    // {
    //     cerr << e.what() << endl;
    // }

    try {
        CryptoContext crypto;

        string original = "Mensaje secreto de prueba";
        string password = "password123";

        auto encrypted = crypto.encrypt(original, password);
        auto decrypted = crypto.decrypt(encrypted, password);

        assert(original == decrypted);

        cout << "Crypto test passed successfully.\n";
        cout << "Original: " << original << "\nDecrypted: " << decrypted << endl;
        cout << "Encrypted: " << string(encrypted.begin(), encrypted.end()) << endl;
    }
    catch (const exception& ex) {
        cerr << "Crypto test failed: " << ex.what() << '\n';
        return 1;
    }
    
    return 0;
}
