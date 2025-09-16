#include <bits/stdc++.h>

using namespace std;

int n, m;
int bm[100010];
char s[16];

int main() {

    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++) {
        scanf("%s",s);
        int mbm=0;
        for (int j=0;j<m;j++)
            if (s[j]=='S')
                mbm |= (1<<j);
        bm[i] = mbm;
    }

    long long int tot = 0;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if ( (bm[i]|bm[j]) == ((1<<m)-1) )
                tot++;
    printf("%lld\n",tot);

    return 0;
}
