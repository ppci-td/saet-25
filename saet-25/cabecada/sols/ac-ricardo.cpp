#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll M[128][128];
ll n, m, q;

#define EPS 1e-7
ll cmpf(double a, double b) {
    if (fabs(a-b)<EPS) return 0;
    return a < b ? -1 : 1;
}

int main() {

    memset(M,0x3f,sizeof(M));
    scanf("%lld %lld %lld", &n, &m, &q);
    for (ll i=0;i<m;i++) {
        ll a, b, w;
        double p;
        scanf("%lld %lld %lld %lf", &a, &b, &w, &p); a--; b--;
        if (cmpf(p, 2.275)>=0 or cmpf(p,0)==0) {
            M[a][b] = min(M[a][b], w);
            M[b][a] = min(M[b][a], w);
        }
    }
    for (ll i=0;i<n;i++) M[i][i]=0;

    // fw
    for (ll k=0;k<n;k++)
        for (ll i=0;i<n;i++)
            for (ll j=0;j<n;j++)
                if (M[i][k] + M[k][j] < M[i][j])
                    M[i][j] = M[i][k] + M[k][j];
    ll atu=0;
    while (q--) {
        scanf("%lld", &m); m--;
        if (M[atu][m] == 0x3f3f3f3f3f3f3f3f)
            printf("-1\n");
        else {
            printf("%lld\n",M[atu][m]);
            atu = m;
        }
    }

    return 0;
}
