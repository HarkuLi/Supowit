#include <fstream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "io.h"

std::vector<unsigned short> IO::ReadFile(std::string filename) {
  std::fstream fstream(filename, std::fstream::in);

  size_t point_num;
  fstream >> point_num;

  std::vector<unsigned short> point_map(point_num);
  size_t chord_num = point_num / 2;
  for (size_t i = 0; i < chord_num; ++i) {
    unsigned short point1, point2;
    fstream >> point1 >> point2;
    point_map[point1] = point2;
    point_map[point2] = point1;
  }

  fstream.close();

  return point_map;
}

void IO::WriteFile(std::string filename, const std::set< std::pair<unsigned short, unsigned short> >& chords) {
  std::fstream fstream(filename, std::fstream::out | std::fstream::trunc);

  fstream << chords.size() << std::endl;
  for (const auto& chord : chords) {
    fstream << chord.first << ' ' << chord.second << std::endl;
  }

  fstream.close();
}
