#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int r = rnd.next(1, 30);
    int x, y;
    do {
        x = rnd.next(-r,r);
        y = rnd.next(-r,r);
    } while (x*x + y*y >= r*r);

    printf("%d %d %d\n",r, x, y);
    return 0;
}
