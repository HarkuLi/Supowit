#include <set>
#include <vector>

#include "chord.h"
#include "supowit.h"

Supowit::Supowit(const std::vector<unsigned int>& point_map) {
  this->point_map = point_map;

  dp_table = new std::set<unsigned int>**[point_map.size()];
  for (size_t i = 0; i < point_map.size(); ++i) {
    dp_table[i] = new std::set<unsigned int>*[point_map.size()];
  }
}

Supowit::~Supowit() {
  for (size_t i = 0; i < point_map.size(); ++i) {
    for (size_t j = 0; j < point_map.size(); ++j) {
      delete dp_table[i][j];
    }
    delete[] dp_table[i];
  }
  delete[] dp_table;
}

std::set<Chord> Supowit::MaxIndependentSet() {
  std::set<unsigned int> point_set = MaxIndependentSetPartial(0, point_map.size() - 1);
  std::set<Chord> rst;

  for (const auto& point : point_set) {
    rst.insert(Chord(point, point_map[point]));
  }
  return rst;
}

std::set<unsigned int> Supowit::MaxIndependentSetPartial(unsigned int start, unsigned int end) {
  if (dp_table[start][end] != NULL) {
    return *dp_table[start][end];
  }

  if (end == start) {
    return std::set<unsigned int>();
  }

  unsigned int end_match = point_map[end];
  std::set<unsigned int> rst;

  if (end_match == start) {
    rst = Case3(start, end);
  } else if (end_match > end || end_match < start) {
    rst = Case1(start, end);
  } else {
    rst = Case2(start, end);
  }

  dp_table[start][end] = new std::set<unsigned int>(rst);
  return rst;
}

// MIS(i, j) = MIS(i, j-1)
std::set<unsigned int> Supowit::Case1(unsigned int start, unsigned int end) {
  return MaxIndependentSetPartial(start, end - 1);
}

// MIS(i, j) = max(MIS(i, j-1), MIS(i, k-1) + MIS(k, j))
std::set<unsigned int> Supowit::Case2(unsigned int start, unsigned int end) {
  unsigned int end_match = point_map[end];
  std::set<unsigned int> point_set_1 = MaxIndependentSetPartial(start, end - 1);
  std::set<unsigned int> point_set_2 = MaxIndependentSetPartial(start, end_match - 1);
  std::set<unsigned int> point_set_3 = MaxIndependentSetPartial(end_match, end);

  if (point_set_1.size() >= point_set_2.size() + point_set_3.size()) {
    return point_set_1;
  }

  for (const auto &point : point_set_3) {
    point_set_2.insert(point);
  }
  return point_set_2;
}

// MIS(i, j) = MIS(i+1, j-1) + Chord(i, j)
std::set<unsigned int> Supowit::Case3(unsigned int start, unsigned int end) {
  std::set<unsigned int> rst;
  if (end - start > 1) {
    rst = MaxIndependentSetPartial(start+1, end-1);
  }
  rst.insert(start);

  return rst;
}
