#pragma once

#include <string>
#include <vector>

class FileManager
{
public:
  static std::string readTextFile(const std::string &path);
  static void writeTextFile(const std::string &path, const std::string &content);

  static std::vector<unsigned char> readBinaryFile(const std::string &path);
  static void writeBinaryFile(const std::string &path, const std::vector<unsigned char> &data);
};
