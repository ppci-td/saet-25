#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int MIN_N = getVar<int>("N.min"); // Read from package vars.
  int MAX_N = getVar<int>("N.max");
  int MIN_K = getVar<int>("K.min");
  int MAX_K = getVar<int>("K.max");

  int N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int K = inf.readInt(MIN_K, MAX_K, "K");
  inf.readEoln();
  for (int i=0;i<N;i++)
      inf.readChar();
  inf.readEoln();
  inf.readEof();
}
