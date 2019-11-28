#include "io.h"
#include "supowit.h"

int main(int argc, char** argv) {
  IO io;
  Supowit supowit(io.ReadFile(argv[1]));
  io.WriteFile(argv[2], supowit.MaxIndependentChords());

  return 0;
}
