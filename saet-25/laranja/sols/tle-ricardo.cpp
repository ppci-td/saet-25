// forca bruta, "esqueci" a pd :')
#include <bits/stdc++.h>

using namespace std;

int n;

int calc(int u, int bm) {
    if (u==3)
        return (bm==0 ? 1 : 0);
    int soma = 0;

    int x = bm;
    while (1) {
        if (__builtin_popcount(x) <= 4) {
            soma += calc(u+1, bm^x);
        }
        if (x == 0) break;
        x = (x-1)&bm;
    }

    return soma;
}

int main() {

    scanf("%d",&n);
    int l=0;
    for (int i=0;i<n;i++) {
        int g, c;
        scanf("%d %d", &g, &c);
        l += (g-c);
        assert(l>=0);
        if (l > 12)
            printf("-1\n");
        else
            printf("%d\n", calc(0, (1<<l)-1));
    }

    return 0;
}
