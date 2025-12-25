#include "core/FileManager.h"

#include <fstream>
#include <iterator>

std::string FileManager::readTextFile(const std::string &path)
{
    std::ifstream file(path);
    if (!file)
    {
        throw std::runtime_error("No se pudo abrir el archivo");
    }

    return std::string(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());
}

void FileManager::writeTextFile(const std::string &path,
                                const std::string &content)
{
    std::ofstream file(path);
    if (!file)
    {
        throw std::runtime_error("No se pudo escribir el archivo");
    }
    file << content;
}
