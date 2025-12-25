#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager
{
public:
  static std::string readTextFile(const std::string &path);
  static void writeTextFile(const std::string &path, const std::string &content);
};

#endif
