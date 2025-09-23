#include "testlib.h"
#include <assert.h>

using namespace std;

typedef pair<int, int> ii;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>(1), q = opt<int>(2);
    printf("%d %d\n",n,q);
    assert( (n%2) == 0 );
    for (int i=0;i<n/2;i++)
        printf("(");
    for (int i=n/2;i<n;i++)
        printf(")");
    printf("\n");
    int t = 1;
    while (q--) {
        printf("%d %d %d\n",t,1,n);
        t = ((t-1)^1)+1;
    }
}
