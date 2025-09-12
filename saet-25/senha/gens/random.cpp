#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>(1);
    int k = opt<int>(2);
    printf("%d %d\n", n, k);
    for (int i=0;i<n;i++)
        printf("%c", rnd.next(0,25)+'a');
    printf("\n");
    return 0;
}
