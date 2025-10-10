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
    int menor = 0x3f3f3f3f;
    // chuta horario final
    for (int f=0;f<MOD;f++) {
        int soma = 0;
        for (int i=0;i<n;i++) {
            int dif = v[i]-f; // p tras
            if (dif < 0) dif += MOD;
            soma += dif;
        }
        if (soma < menor)
            menor = soma;
    }
    printf("%d\n",menor);

    return 0;
}
