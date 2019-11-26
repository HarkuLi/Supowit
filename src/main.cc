#include <iostream>
#include <vector>

#include "io.h"
#include "supowit.h"

int main(int argc, char** argv) {
  IO io;
  std::vector<unsigned int> point_map = io.ReadFile(argv[1]);

  Supowit supowit(point_map);
  io.WriteFile(argv[2], supowit.MaxIndependentSet());

  return 0;
}
