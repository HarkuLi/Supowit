#include "chord.h"

Chord::Chord(unsigned int point_a, unsigned int point_b) {
  if (point_a > point_b) {
    point_large = point_a;
    point_small = point_b;
    return;
  }

  point_small = point_a;
  point_large = point_b;
}

unsigned int Chord::get_point_small() const {
  return point_small;
}

unsigned int Chord::get_point_large() const {
  return point_large;
}

bool operator<(const Chord& chord_1, const Chord& chord_2) {
  if (chord_1.point_small > chord_2.point_small) {
    return false;
  }

  if (chord_1.point_small < chord_2.point_small) {
    return true;
  }

  return chord_1.point_large < chord_2.point_large;
}

bool operator==(const Chord& chord_1, const Chord& chord_2) {
  return chord_1.point_small == chord_2.point_small
    && chord_1.point_large == chord_2.point_large;
}

std::ostream& operator<<(std::ostream& ostream, const Chord& chord) {
  return ostream << "("
    << chord.get_point_small()
    << ", "
    << chord.get_point_large()
    << ")";
}
