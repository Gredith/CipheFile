#include <iostream>
#include <string>
#include "core/FileManager.h"
using namespace std;

int main()
{
    try
    {
        FileManager::writeTextFile("test.txt", "Hola mundo");
        string text = FileManager::readTextFile("test.txt");
        cout << text << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
