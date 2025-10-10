#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1,50);
    int b = rnd.next(1,2000);
    int v;
    int r = rnd.next(0,1);
    if (r == 0) {
        // resp possivel
        do {
            v = rnd.next(0,b);
        } while ( (b-v)%n != 0);
    } else {
        // qlqr uma, provavel -1
        v = rnd.next(0,b);
    }
    printf("%d %d %d\n",n,b,v);
}
