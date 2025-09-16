#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_R = getVar<int>("R.min"); // Read from package vars.
  int MAX_R = getVar<int>("R.max");
  int MIN_X = getVar<int>("X.min"); // Read from package vars.
  int MAX_X = getVar<int>("X.max");
  int MIN_Y = getVar<int>("Y.min"); // Read from package vars.
  int MAX_Y = getVar<int>("Y.max");

  int r = inf.readInt(MIN_R, MAX_R, "R");
  inf.readSpace();
  int x = inf.readInt(MIN_X, MAX_X, "X");
  inf.readSpace();
  int y = inf.readInt(MIN_Y, MAX_Y, "Y");
  inf.readEoln();
  inf.readEof();

  assert(x*x + y*y < r*r); // dentro do circulo, (nao borda)

}
