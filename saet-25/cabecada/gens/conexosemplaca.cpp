#include "testlib.h"
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = 100;
    int M = 200;
    int Q = 100;

    printf("%d %d %d\n",N,M,Q);
    for (int i=2;i<=N;i++)
        printf("%d %d %d 0\n",i,rnd.next(1,i-1),rnd.next(1,1000000000));
    int faltam = M-(N-1);
    for (int i=0;i<faltam;i++) {
        int a = rnd.next(1,N);
        int b;
        do { b = rnd.next(1,N); } while (b==a);
        printf("%d %d %d 0\n",a,b,rnd.next(1,1000000000));
    }
    for (int i=0;i<Q;i++)
        printf("%d\n",rnd.next(1,N));

}
