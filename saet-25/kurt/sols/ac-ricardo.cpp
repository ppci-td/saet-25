#include <bits/stdc++.h>
#define ll long long int
#define MOD 43200 // segundos em 12 hrs

using namespace std;

ll n;
ll v[100010];
multiset<ll> S;

int main() {

    scanf("%lld", &n);
    S.clear();
    for (ll i=0;i<n;i++) {
        ll h, m, s;
        scanf("%lld %lld %lld", &h, &m, &s);
        v[i] = 3600*h + 60*m + s;
        S.insert(v[i]);
    }
    // comeca com alvo 0
    ll menor = 0;
    for (ll i=0;i<n;i++)
        menor += v[i];
    // outros
    ll respatual = menor;
    for (ll alvo=1;alvo<MOD;alvo++) {
        respatual -= n; // -- em td mnd
        while (!S.empty() and (*S.begin())<alvo) {
            respatual += MOD; // + 12 h
            ll u = *S.begin();
            S.erase(S.begin());
            S.insert(u+MOD);
        }
        if (respatual < menor)
            menor = respatual;
    }

    printf("%lld\n",menor);

    return 0;
}
