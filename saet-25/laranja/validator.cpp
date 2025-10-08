#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int N = inf.readInt(1, 10000, "N");
  inf.readEoln();

  for(int i = 0; i < N; i++){

    int G = inf.readInt(0, 100, "G");
    inf.readSpace();
    
    int C = inf.readInt(0, 100, "C");
    inf.readEoln();
    
  }
  inf.readEof();
}