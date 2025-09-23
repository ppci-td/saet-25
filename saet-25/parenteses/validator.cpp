#include "rbx.h"
#include "testlib.h"
#include <assert.h>

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_N = getVar<int>("N.min"); // Read from package vars.
  int MAX_N = getVar<int>("N.max");
  int MIN_Q = getVar<int>("Q.min"); // Read from package vars.
  int MAX_Q = getVar<int>("Q.max");

  int N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int Q = inf.readInt(MIN_Q, MAX_Q, "Q");
  inf.readEoln();
  for (int i=0;i<N;i++) {
      char c = inf.readChar();
      assert(c=='(' or c==')');
  }
  inf.readEoln();
  while (Q--) {
        int t = inf.readInt(1,2,"t");
        inf.readSpace();
        int l = inf.readInt(1,N,"l");
        inf.readSpace();
        int r = inf.readInt(l,N,"r");
        inf.readEoln();
  }

  inf.readEof();
}
