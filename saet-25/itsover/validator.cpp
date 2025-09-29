#include "rbx.h"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, 1000, "N");
    inf.readEoln();

    for (int i = 0; i < N; i++) {
      
        int M = inf.readInt(1, 1000, "M");
        inf.readEoln();
        
        for (int j = 0; j < M; j++) {
                if(j == M-1) inf.readInt(1, 100000, "A");
                else{
                    inf.readInt(1, 100000, "A");
                    inf.readSpace();
                }
        }

        inf.readEoln();
    }

    inf.readEof();
}
