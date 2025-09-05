#include "rbx.h"
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  prepareOpts(argc, argv);

  int n = inf.readInt(1,getVar<int>("N.max"),"N");
  inf.readSpace();
  int m = inf.readInt(1,getVar<int>("N.max"),"M");
  inf.readEoln();
  for (int i=0;i<m;i++) {
        if (i) inf.readSpace();
        inf.readInt(1,getVar<int>("li.max"),"li");
  }
  inf.readEoln();
  inf.readInt(1,getVar<int>("L.max"),"L");
  inf.readEoln();
  inf.readEof();

  return 0;
}
