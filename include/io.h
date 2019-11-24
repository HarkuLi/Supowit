#ifndef SUPOWIT_INCLUDE_IO_H
#define SUPOWIT_INCLUDE_IO_H

#include <set>
#include <string>
#include <vector>
#include "chord.h"

class IO {
  public:
    std::vector<unsigned int> ReadFile(std::string);
};

#endif
