// fazendo gerador proprio pq o do rbx proibe chamar srand
#include <bits/stdc++.h>

using namespace std;

int main() {

    srand(time(NULL) + clock());
    int n = rand()%100000 + 1;
    int m = rand()%100000 + 1;
    printf("%d %d\n", n, m);

    for (int i=0;i<m;i++) {
        if (i) printf(" ");
        printf("%d", rand()%1000000000 + 1);
    }
    printf("\n");
    printf("%d\n", rand()%1000000000 + 1);

    return 0;
}
