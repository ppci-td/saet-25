#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_N = getVar<int>("N.min"); // Read from package vars.
  int MAX_N = getVar<int>("N.max");
  int MIN_B = getVar<int>("B.min"); // Read from package vars.
  int MAX_B = getVar<int>("B.max");
  int MIN_V = getVar<int>("V.min"); // Read from package vars.
  int MAX_V = getVar<int>("V.max");

  int N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int B = inf.readInt(MIN_B, MAX_B, "B");
  inf.readSpace();
  int V = inf.readInt(MIN_V, MAX_V, "V");
  assert(V <= B);
  inf.readEoln();
  inf.readEof();
}
