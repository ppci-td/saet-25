#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int N = inf.readInt(3, 100000, "N");
  inf.readEoln();

  for(int i = 0; i < N; i++){

    int D = inf.readInt(1, 30, "D");
    inf.readSpace();
    
    int M = inf.readInt(1, 12, "M");
    inf.readSpace();

    int A = inf.readInt(1, 1000000000, "A");
    inf.readEoln();
  }
  inf.readEof();
}