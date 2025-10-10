#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, b, v;
    scanf("%d %d %d", &n, &b, &v);
    assert(v<=b);
    if ( (b-v)%n == 0)
       printf("%d\n", (b-v)/n);
    else
        printf("-1\n");

    return 0;
}
