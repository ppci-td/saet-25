#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {

    registerGen(argc, argv, 1);

/* ver meugerador.cpp no manual_tests
   srand(time(NULL) + clock());
    int n = rand()%100000 + 1;
    int m = rand()%100000 + 1;
    printf("%d %d\n", n, m);

    for (int i=0;i<m;i++) {
        if (i) printf(" ");
        printf("%d", rand()%1000000000 + 1);
    }
    printf("\n");
    printf("%d\n", rand()%1000000000 + 1);*/

    return 0;

}
