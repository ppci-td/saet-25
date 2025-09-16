#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n, m;
char s[12];
ll qnts[(1<<10)];

int main() {

    memset(qnts,0,sizeof(qnts));
    scanf("%lld %lld",&n,&m);
    for (ll i=0;i<n;i++) {
        scanf("%s",s);
        ll mbm=0;
        for (ll j=0;j<m;j++)
            if (s[j]=='S')
                mbm|=(1<<j);
        qnts[mbm]++;
    }
    ll tot = 0;
    for (ll i=0;i<(1<<m);i++)
        for (ll j=0;j<(1<<m);j++)
            if ( (i|j) == ((1<<m)-1) )
                tot += qnts[i]*qnts[j];

    printf("%lld\n",tot/2ll);
    return 0;
}
