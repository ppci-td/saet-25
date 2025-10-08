#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    ll n;
    scanf("%lld", &n);
    ll menor = 0x3f3f3f3f3f3f3f3fll;
    ll maior = 0;
    ll d, m, a, t1, t2;
    scanf("%lld %lld %lld", &d, &m, &a);
    t1 = 360*a + 30*m + d;
    for (ll i=1;i<n;i++) {
        scanf("%lld %lld %lld", &d, &m, &a);
        t2 = 360*a + 30*m + d;
        menor = min(menor, t2-t1);
        maior = max(maior, t2-t1);
        t1 = t2;
    }
    printf("%lld %lld\n",menor,maior);

    return 0;
}
