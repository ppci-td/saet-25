#include <bits/stdc++.h>

using namespace std;

int n, m;
int v[100010];
int L;

int main() {

    scanf("%d %d", &n, &m);
    for (int i=0;i<m;i++)
        scanf("%d",v+i);
    scanf("%d",&L);

    int disponivel=0;
    for (int i=0;i<m;i++)
        if (v[i] > L)
            disponivel++;
    if (disponivel >= n)
        printf("SIM\n");
    else
        printf("NAO\n");

    return 0;
}
