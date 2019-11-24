#include <fstream>
#include <string>
#include <vector>

#include "io.h"

std::vector<unsigned int> IO::ReadFile(std::string filename) {
  std::fstream fstream;
  fstream.open(filename, std::fstream::in);

  size_t point_num;
  fstream >> point_num;

  std::vector<unsigned int> point_map(point_num);
  size_t chord_num = point_num / 2;
  for (size_t i = 0; i < chord_num; ++i) {
    unsigned int point1, point2;
    fstream >> point1 >> point2;
    point_map[point1] = point2;
    point_map[point2] = point1;
  }

  fstream.close();

  return point_map;
}
