#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[100010];
set<long long int> S;

int main() {

    scanf("%d %d",&n,&k);
    scanf("%s",s);
    S.clear();
    for (int i=0;i<n;i++) {
        long long int x=0;
        for (int j=0;j<k;j++) {
            x = 31ll*x + (s[(i+j)%n]-'a'+1);
            S.insert(x);
        }
    }

    printf("%lld\n",(long long int)S.size());

    return 0;
}
