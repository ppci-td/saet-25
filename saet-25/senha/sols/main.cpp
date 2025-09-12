#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[200020];
int B1[200020], B2[200020], *bucket, *nbucket;
int L[200020], t, LCP[200020], pos[200020];

bool cmp(int u1, int u2) {
    if (t==1)
        return s[u1] < s[u2];
    if (bucket[u1] != bucket[u2])
        return bucket[u1] < bucket[u2];
    return bucket[min(u1+t/2,n-1)] < bucket[min(u2+t/2,n-1)];
}

int main() {

    scanf("%d %d",&n,&k);
    scanf("%s",s);
    // duplica
    for (int i=n;i<2*n;i++)
        s[i] = s[i-n];
    s[2*n]='\0';
    n = 2*n+1; // '\0' faz parte da string

    for (int i=0;i<n;i++) L[i]=i;
    bucket = B1, nbucket = B2;
    for (t=1;;t*=2) {
        // ordena sufixos com tamanho t
        sort(L,L+n,cmp);
        // rearranga os buckets
        int B=1;
        nbucket[L[0]] = 0;
        for (int i=1;i<n;i++)
            if (!cmp(L[i],L[i-1]) and !cmp(L[i-1],L[i]))
                nbucket[L[i]] = nbucket[L[i-1]];
            else
                nbucket[L[i]] = B++;
        if (B==n) break;
        int *aux = bucket;
        bucket = nbucket;
        nbucket = aux;
    }

    //pega LCP
    //pos = vetor inverso de L, diz a posicao de um suffixo no vetor ordenado
    for (int i=0;i<n;i++)
        pos[L[i]] = i;
    //constroi o vetor LCP
    int h=0;
    LCP[0] = 0;
    for (int i=0;i<n;i++) if (pos[i] > 0) {
        while (s[i+h] == s[ L[pos[i]-1]+h ]) h++;
        LCP[pos[i]] = h--;
        if (h < 0) h=0;
    }

    // res
    long long int res = 0;
    for (int i=0;i<n;i++) {
        int lim = min(k, n-L[i]-1 /*-1 desconsidera \0*/);
        if (LCP[i] < lim)
            res += (long long int)(lim-LCP[i]);
    }
    printf("%lld\n",res);

    return 0;
}
