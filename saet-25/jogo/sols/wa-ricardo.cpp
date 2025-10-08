// 360*ano nao cabe num int
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    int menor = 0x7fffffff;
    int maior = 0;
    int d, m, a, t1, t2;
    scanf("%d %d %d", &d, &m, &a);
    t1 = 360*a + 30*m + d;
    for (int i=1;i<n;i++) {
        scanf("%d %d %d", &d, &m, &a);
        t2 = 360*a + 30*m + d;
        menor = min(menor, t2-t1);
        maior = max(maior, t2-t1);
        t1 = t2;
    }
    printf("%d %d\n",menor,maior);

    return 0;
}
