#include <iostream>
#include <set>
#include <vector>
#include "chord.h"
#include "io.h"
#include "supowit.h"

int main(int argc, char** argv) {
  IO io;
  std::vector<unsigned int> point_map = io.ReadFile(argv[1]);

  Supowit supowit(point_map);
  std::set<Chord>* rst = supowit.MaxIndependentSet(0, point_map.size() - 1);

  for (const auto &chord : *rst) {
    std::cout << chord << std::endl;
  }

  return 0;
}
