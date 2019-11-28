#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "supowit.h"

Supowit::Supowit(const std::vector<unsigned short>& point_map) {
  if (point_map.size() >= DP_TABLE_UNSET) {
    throw std::length_error(
      "The number of points can't be equal or larger than "
      + std::to_string(DP_TABLE_UNSET)
      + '.'
    );
  }

  this->point_map = point_map;

  dp_table = new unsigned short*[point_map.size()];
  for (size_t i = 0; i < point_map.size(); ++i) {
    dp_table[i] = new unsigned short[point_map.size()];
    memset(dp_table[i], DP_TABLE_UNSET, sizeof(*(dp_table[i])) * point_map.size());
  }
}

Supowit::~Supowit() {
  for (int i = 0; i < point_map.size(); ++i) {
    delete[] dp_table[i];
  }
  delete[] dp_table;
}

std::set< std::pair<unsigned short, unsigned short> > Supowit::MaxIndependentChords() {
  BuildDpTable();
  return *Chords(0, point_map.size() - 1);
}

void Supowit::BuildDpTable() {
  MaxIndependentNum(0, point_map.size() - 1);
}

unsigned short Supowit::MaxIndependentNum(unsigned short start, unsigned short end) {
  if (dp_table[start][end] != DP_TABLE_UNSET) {
    return dp_table[start][end];
  }

  if (end == start) {
    return dp_table[start][end] = 0;
  }

  unsigned short end_match = point_map[end];
  unsigned short rst;

  if (end_match == start) {
    rst = NumCase3(start, end);
  } else if (end_match > end || end_match < start) {
    rst = NumCase1(start, end);
  } else {
    rst = NumCase2(start, end);
  }

  return dp_table[start][end] = rst;
}

// MIS(i, j) = MIS(i, j-1)
unsigned short Supowit::NumCase1(unsigned short start, unsigned short end) {
  return MaxIndependentNum(start, end - 1);
}

// MIS(i, j) = max(MIS(i, j-1), MIS(i, k-1) + MIS(k, j))
unsigned short Supowit::NumCase2(unsigned short start, unsigned short end) {
  unsigned short end_match = point_map[end];
  unsigned short mis1 = MaxIndependentNum(start, end - 1);
  unsigned short mis2 = MaxIndependentNum(start, end_match - 1);
  unsigned short mis3 = MaxIndependentNum(end_match, end);

  if (mis1 >= mis2 + mis3) {
    return mis1;
  }

  return mis2 + mis3;
}

// MIS(i, j) = MIS(i+1, j-1) + Chord(i, j)
unsigned short Supowit::NumCase3(unsigned short start, unsigned short end) {
  unsigned short rst = 1;
  if (end - start > 1) {
    rst += MaxIndependentNum(start+1, end-1);
  }
  return rst;
}

// must call BuildDpTable() before it
std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > > Supowit::Chords(
  unsigned short start,
  unsigned short end
) {
  if (end == start || dp_table[start][end] == 0) {
    return std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > >(new std::set< std::pair<unsigned short, unsigned short> >());
  }

  unsigned short end_match = point_map[end];

  if (end_match == start) {
    return ChordsCase3(start, end);
  }
  
  if (end_match > end || end_match < start) {
    return ChordsCase1(start, end);
  }

  return ChordsCase2(start, end);
}

std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > > Supowit::ChordsCase1(
  unsigned short start,
  unsigned short end
) {
  return Chords(start, end - 1);
}

std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > > Supowit::ChordsCase2(
  unsigned short start,
  unsigned short end
) {
  unsigned short end_match = point_map[end];
  unsigned short num1 = dp_table[start][end - 1];
  unsigned short num2 = dp_table[start][end_match - 1];
  unsigned short num3 = dp_table[end_match][end];

  if (num1 >= num2 + num3) {
    return Chords(start, end - 1);
  }

  auto chords2 = Chords(start, end_match - 1);
  auto chords3 = Chords(end_match, end);
  for (const auto& chord : *chords3) {
    chords2->insert(chord);
  }
  return std::move(chords2);
}

std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > > Supowit::ChordsCase3(
  unsigned short start,
  unsigned short end
) {
  std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > > rst;

  if (end - start > 1) {
    rst = Chords(start+1, end-1);
  } else {
    rst.reset(new std::set< std::pair<unsigned short, unsigned short> >());
  }
  rst->insert(std::make_pair(start, end));

  return std::move(rst);
}
