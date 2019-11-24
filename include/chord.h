#ifndef SUPOWIT_INCLUDE_CHORD_H_
#define SUPOWIT_INCLUDE_CHORD_H_

#include <iostream>
#include <vector>

class Chord {
  private:
    unsigned int point_small;
    unsigned int point_large;

  public:
    Chord(unsigned int, unsigned int);
    unsigned int get_point_small() const;
    unsigned int get_point_large() const;
    friend bool operator<(const Chord&, const Chord&);
    friend bool operator==(const Chord&, const Chord&);
    friend std::ostream &operator<<(std::ostream&, const Chord&);
};

#endif
