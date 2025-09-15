#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[2048][2048];

inline bool match(int a, int b) {
    for (int i=0;i<m;i++)
        if (s[a][i]=='N' and s[b][i]=='N')
            return false;
    return true;
}

int main() {

    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%s",s[i]);
    int tot = 0;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (match(i,j))
                tot++;
    printf("%d\n",tot);

    return 0;
}
