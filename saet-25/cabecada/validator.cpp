#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int N = inf.readInt(2, 100, "N"); inf.readSpace();
  int M = inf.readInt(1, 200, "M"); inf.readSpace();
  int Q = inf.readInt(1, 100, "Q"); inf.readEoln();

  for(int i = 0; i < M; i++){
    int X = inf.readInt(1, N, "X"); inf.readSpace();
    int Y = inf.readInt(1, N, "Y"); inf.readSpace();
    int D = inf.readInt(1, 1000000000, "D"); inf.readSpace();
    double H = inf.readDouble(0, 10, "H"); inf.readEoln();
  }
  for(int i = 0; i < Q; i++){
    int A = inf.readInt(1,N, "A"); inf.readEoln();
  } 
  inf.readEof();
}
