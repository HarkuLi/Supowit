#ifndef SUPOWIT_INCLUDE_SUPOWIT_H_
#define SUPOWIT_INCLUDE_SUPOWIT_H_

#include <limits>
#include <memory>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

class Supowit {
  private:
    const unsigned short DP_TABLE_UNSET = std::numeric_limits<unsigned short>::max();
    std::vector<unsigned short> point_map;
    unsigned short** dp_table;
    void BuildDpTable();
    unsigned short MaxIndependentNum(unsigned short, unsigned short);
    unsigned short NumCase1(unsigned short, unsigned short);
    unsigned short NumCase2(unsigned short, unsigned short);
    unsigned short NumCase3(unsigned short, unsigned short);
    std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > > Chords(unsigned short, unsigned short);
    std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > > ChordsCase1(unsigned short, unsigned short);
    std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > > ChordsCase2(unsigned short, unsigned short);
    std::unique_ptr< std::set< std::pair<unsigned short, unsigned short> > > ChordsCase3(unsigned short, unsigned short);

  public:
    Supowit(const std::vector<unsigned short>&);
    ~Supowit();
    std::set< std::pair<unsigned short, unsigned short> > MaxIndependentChords();
};

#endif
