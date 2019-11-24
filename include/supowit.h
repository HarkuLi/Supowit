#ifndef SUPOWIT_INCLUDE_SUPOWIT_H_
#define SUPOWIT_INCLUDE_SUPOWIT_H_

#include <set>
#include <vector>

#include "chord.h"

class Supowit {
  private:
    std::vector<unsigned int> point_map;

  public:
    Supowit(const std::vector<unsigned int>&);
    std::set<Chord>* MaxIndependentSet(unsigned int, unsigned int);
};

#endif
