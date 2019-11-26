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

std::set<unsigned int> Supowit::MaxIndependentSet(unsigned int start, unsigned int end) {
  if (dp_table[start][end] != NULL) {
    return *dp_table[start][end];
  }

  if (end == start) {
    return std::set<unsigned int>();
  }

  unsigned int end_match = point_map[end];
  std::set<unsigned int> rst;

  // Case 3
  if (end_match == start) {
    if (end - start > 1) {
      rst = MaxIndependentSet(start+1, end-1);
    }
    rst.insert(start);
    dp_table[start][end] = new std::set<unsigned int>(rst);
    return rst;
  }

  // Case 1
  if (end_match > end || end_match < start) {
    rst = MaxIndependentSet(start, end - 1);
    dp_table[start][end] = new std::set<unsigned int>(rst);
    return rst;
  }

  // Case 2
  std::set<unsigned int> point_set_1 = MaxIndependentSet(start, end - 1);
  std::set<unsigned int> point_set_2 = MaxIndependentSet(start, end_match - 1);
  std::set<unsigned int> point_set_3 = MaxIndependentSet(end_match, end);

  if (point_set_1.size() >= point_set_2.size() + point_set_3.size()) {
    dp_table[start][end] = new std::set<unsigned int>(point_set_1);
    return point_set_1;
  }

  for (const auto &point : point_set_3) {
    point_set_2.insert(point);
  }
  dp_table[start][end] = new std::set<unsigned int>(point_set_2);
  return point_set_2;
}
