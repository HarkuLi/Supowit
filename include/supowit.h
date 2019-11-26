#ifndef SUPOWIT_INCLUDE_SUPOWIT_H_
#define SUPOWIT_INCLUDE_SUPOWIT_H_

#include <set>
#include <vector>

#include "chord.h"

class Supowit {
  private:
    std::vector<unsigned int> point_map;
    std::set<unsigned int>*** dp_table;
    std::set<unsigned int> MaxIndependentSetPartial(unsigned int, unsigned int);
    std::set<unsigned int> Case1(unsigned int, unsigned int);
    std::set<unsigned int> Case2(unsigned int, unsigned int);
    std::set<unsigned int> Case3(unsigned int, unsigned int);

  public:
    Supowit(const std::vector<unsigned int>&);
    ~Supowit();
    std::set<Chord> MaxIndependentSet();
};

#endif
