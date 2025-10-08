// de um em um

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    ll n;
    scanf("%lld", &n);
    ll menor = 0x3f3f3f3f3f3f3f3fll;
    ll maior = 0;
    ll d1, m1, a1,d2,m2,a2;
    scanf("%lld %lld %lld", &d1, &m1, &a1);
    for (ll i=1;i<n;i++) {
        scanf("%lld %lld %lld", &d2, &m2, &a2);
        ll passos = 0;
        while (d1 != d2 or m1 != m2 or a1 != a2)
        {
            passos++;
            d1++;
            if (d1==31) {
                d1=1;
                m1++;
                if (m1==13) {
                    m1=1;
                    a1++;
                }
            }
        }
        menor = min(menor, passos);
        maior = max(maior, passos);
    }
    printf("%lld %lld\n",menor,maior);

    return 0;
}
