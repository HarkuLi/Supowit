#include <vector>

#include "chord.h"
#include "supowit.h"

Supowit::Supowit(const std::vector<unsigned int>& point_map) {
  this->point_map = point_map;
}

std::set<Chord>* Supowit::MaxIndependentSet(unsigned int start, unsigned int end) {
  if (end == start) {
    return new std::set<Chord>();
  }

  unsigned int end_match = point_map[end];

  // Case 3
  if (end_match == start) {
    std::set<Chord>* rst = end - start == 1
      ? new std::set<Chord>() : MaxIndependentSet(start+1, end-1);
    rst->insert(Chord(start, end));
    return rst;
  }

  // Case 1
  if (end_match > end || end_match < start) {
    return MaxIndependentSet(start, end - 1);
  }

  // Case 2
  std::set<Chord>* chord_set_1 = MaxIndependentSet(start, end - 1);
  std::set<Chord>* chord_set_2 = MaxIndependentSet(start, end_match - 1);
  std::set<Chord>* chord_set_3 = MaxIndependentSet(end_match + 1, end - 1);
  
  if (chord_set_1->size() >= chord_set_2->size() + chord_set_3->size() + 1) {
    return chord_set_1;
  }

  for (const auto &chord : *chord_set_3) {
    chord_set_2->insert(Chord(chord.get_point_small(), chord.get_point_large()));
  }
  chord_set_2->insert(Chord(end_match, end));
  return chord_set_2;
}
