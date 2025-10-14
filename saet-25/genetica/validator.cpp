#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int N = inf.readInt(1,100000, "N"); inf.readSpace();
  int X = inf.readInt(0,100000, "X"); inf.readEoln();
  string S = inf.readToken(); inf.readEoln();
  assert( S.size() == N);
  inf.readEof();

  
}
