#ifndef SUPOWIT_INCLUDE_IO_H
#define SUPOWIT_INCLUDE_IO_H

#include <set>
#include <string>
#include <utility>
#include <vector>

class IO {
  public:
    std::vector<unsigned short> ReadFile(std::string);
    void WriteFile(std::string, const std::set< std::pair<unsigned short, unsigned short> >&);
};

#endif
