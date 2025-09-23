#include "testlib.h"
#include <assert.h>

using namespace std;

typedef pair<int, int> ii;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>(1), q = opt<int>(2);
    printf("%d %d\n",n,q);
    assert( (n%2) == 0 );
    // pequeno delta deslocado pra qlqr consulta dar menor=0 mas soma>0
#define DELTA 5
    for (int i=0;i<n/2+DELTA;i++)
        printf("(");
    for (int i=n/2+DELTA;i<n;i++)
        printf(")");
    printf("\n");
    int t = 1;
    while (q--) {
        if (t==2)
            printf("%d %d %d\n",t,1+rnd.next(0,10),n-rnd.next(0,10));
        else {
            // muda soh um
            int pos = rnd.next(0,n-1);
            printf("%d %d %d\n",t,pos,pos);
        }
        t = ((t-1)^1)+1;
    }
}
