#include <bits/stdc++.h>

using namespace std;

int M[128][128];
int n, m, q;

#define EPS 1e-7
int cmpf(double a, double b) {
    if (fabs(a-b)<EPS) return 0;
    return a < b ? -1 : 1;
}

int main() {

    memset(M,0x3f,sizeof(M));
    scanf("%d %d %d", &n, &m, &q);
    for (int i=0;i<m;i++) {
        int a, b, w;
        double p;
        scanf("%d %d %d %lf", &a, &b, &w, &p); a--; b--;
        if (cmpf(p, 2.275)>=0 or cmpf(p,0)==0) {
            M[a][b] = min(M[a][b], w);
            M[b][a] = min(M[b][a], w);
        }
    }
    for (int i=0;i<n;i++) M[i][i]=0;

    // fw
    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (M[i][k] + M[k][j] < M[i][j])
                    M[i][j] = M[i][k] + M[k][j];
    int atu=0;
    while (q--) {
        scanf("%d", &m); m--;
        if (M[atu][m] == 0x3f3f3f3f)
            printf("-1\n");
        else {
            printf("%d\n",M[atu][m]);
            atu = m;
        }
    }

    return 0;
}
