#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int N = inf.readInt(1, 100000, "N");
  inf.readEoln();

  long long int ultimo;

  for(int i = 0; i < N; i++){
    int H = inf.readInt(0, 11, "H");
    inf.readSpace();
    int M = inf.readInt(0, 59, "M");
    inf.readSpace();
    int S = inf.readInt(0, 59, "S");
    inf.readEoln();
  }
  inf.readEof();
}
