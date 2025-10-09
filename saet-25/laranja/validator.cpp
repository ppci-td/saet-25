#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int N = inf.readInt(1, 10000, "N");
  inf.readEoln();

  int l=0;
  for(int i = 0; i < N; i++){

    int G = inf.readInt(0, 100, "G");
    inf.readSpace();
    
    int C = inf.readInt(0, 100, "C");
    inf.readEoln();
    
    l += (G-C);
    assert( l >= 0 ); // garantir que nao sera negativo
  }
  inf.readEof();
}
