// com segfree mas sem lazy
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

typedef struct {
    int soma, menor, maior;
    int ini, fim;
    int esq, dir;
} nodo;

int n, q, tipo, l, r;
char s[200020];
nodo M[400040];
int pQ=0;

int constroi(int ini, int fim) {
    int r = pQ++;
    M[r].ini = ini;
    M[r].fim = fim;
    if (ini==fim) {
        M[r].esq = M[r].dir = -1;
        M[r].soma = M[r].menor = M[r].maior = (s[ini]=='(' ? 1 : -1);
        return r;
    }
    int m = (ini+fim)/2;
    M[r].esq = constroi(ini,m);
    M[r].dir = constroi(m+1,fim);
    M[r].soma = M[M[r].esq].soma + M[M[r].dir].soma;
    M[r].menor = min(M[M[r].esq].menor, M[M[r].esq].soma + M[M[r].dir].menor);
    M[r].maior = max(M[M[r].esq].maior, M[M[r].esq].soma + M[M[r].dir].maior);
    return r;
}

ii query(int r, int ini, int fim) {
    if (M[r].ini > fim or M[r].fim < ini)
        return ii(0, 0x3f3f3f3f);
    if (ini <= M[r].ini and M[r].fim <= fim)
        return ii(M[r].soma, M[r].menor);
    ii a = query(M[r].esq,ini,fim);
    ii b = query(M[r].dir,ini,fim);
    ii ret;
    ret.first = a.first + b.first;
    ret.second = min(a.second, a.first + b.second);
    return ret;
}

void update(int r, int pos) {
    if (M[r].ini == M[r].fim) {
        M[r].soma = -M[r].soma;
        M[r].menor = M[r].maior = M[r].soma;
        return;
    }
    int m = (M[r].ini + M[r].fim)/2;
    if (pos <= m)
        update(M[r].esq, pos);
    else
        update(M[r].dir, pos);

    M[r].soma = M[M[r].esq].soma + M[M[r].dir].soma;
    M[r].menor = min(M[M[r].esq].menor, M[M[r].esq].soma + M[M[r].dir].menor);
    M[r].maior = max(M[M[r].esq].maior, M[M[r].esq].soma + M[M[r].dir].maior);
}

int main() {

    scanf("%d %d",&n, &q);
    scanf("%s",s);
    int raiz = constroi(0,n-1);
    while (q--) {
        scanf("%d %d %d", &tipo, &l, &r); l--; r--;
        if (tipo==1) {
            for (int i=l;i<=r;i++)
                update(raiz,i);
        } else {
            ii tt = query(raiz,l,r);
            if (tt == ii(0,0)) // soma=0 e menor=0
                printf("sim\n");
            else
                printf("nao\n");
        }
    }

    return 0;
}
