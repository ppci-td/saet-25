#include <assert.h>
#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_N = getVar<int>("N.min"); // Read from package vars.
  int MAX_N = getVar<int>("N.max");
  int MIN_F = getVar<int>("F.min"); // Read from package vars.
  int MAX_F = getVar<int>("F.max");

  int n = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int f = inf.readInt(MIN_F, MAX_F, "F");
  inf.readEoln();
  for (int i=0;i<n;i++) {
      for (int j=0;j<f;j++) {
          char l = inf.readChar();
          assert(l=='S' or l=='N');
      }
      inf.readEoln();
  }
  inf.readEof();
}
