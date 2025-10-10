#include <bits/stdc++.h>

#define MOD 43200 // segundos em 12 hrs

using namespace std;

int n;
int v[100010];

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        int h, m, s;
        scanf("%d %d %d", &h, &m, &s);
        v[i] = 3600*h + 60*m + s;
    }
    sort(v,v+n);
//    n = unique(v,v+n)-v;
    int menor = 0x3f3f3f3f;
    // mts opcoes?
    for (int x0=0;x0<MOD;x0++) {
        int soma = x0;
        for (int i=1;i<n;i++) {
            int xi = (v[i]-v[0]+x0+MOD)%MOD;
            soma += xi;
        }
        if (soma < menor)
            menor = soma;
    }
    printf("%d\n",menor);

    return 0;
}
