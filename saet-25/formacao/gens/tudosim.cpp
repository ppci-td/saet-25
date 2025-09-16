#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1), f = opt<int>(2);
    printf("%d %d\n",n,f);
    for (int i=0;i<n;i++) {
        for (int j=0;j<f;j++)
            printf("S");
        printf("\n");
    }
}
