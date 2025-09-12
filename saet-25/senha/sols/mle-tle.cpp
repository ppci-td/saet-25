#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[100010];
set<string> S;

int main() {

    scanf("%d %d",&n,&k);
    scanf("%s",s);
    S.clear();
    for (int i=0;i<n;i++) {
        string x;
        for (int j=0;j<k;j++) {
            x.push_back(s[(i+j)%n]);
            S.insert(x);
        }
    }

    printf("%lld\n",(long long int)S.size());

    return 0;
}
