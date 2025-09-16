#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[12];
int qnts[(1<<10)];

int main() {

    memset(qnts,0,sizeof(qnts));
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++) {
        scanf("%s",s);
        int mbm=0;
        for (int j=0;j<m;j++)
            if (s[j]=='S')
                mbm|=(1<<j);
        qnts[mbm]++;
    }
    int tot = 0;
    for (int i=0;i<(1<<m);i++)
        for (int j=i+1;j<(1<<m);j++)
            if ( (i|j) == ((1<<m)-1) )
                tot += qnts[i]*qnts[j];

    // corner case: bm = (1<<m)-1
    int brabos = qnts[(1<<m)-1];
    tot += (brabos*(brabos-1))/2ll;

    printf("%d\n",tot);
    return 0;
}
