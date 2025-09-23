#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

typedef struct {
    int soma, menor, maior;
    int ini, fim;
    int flag;
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
    M[r].flag = 0;
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

void unflag(int r) {
    if (M[r].flag==0) return;
    M[r].soma = -M[r].soma;
    int aux = M[r].menor;
    M[r].menor = -M[r].maior;
    M[r].maior = -aux;
    M[r].flag = 0;
    if (M[r].esq != -1) M[M[r].esq].flag ^= 1;
    if (M[r].dir != -1) M[M[r].dir].flag ^= 1;
}

ii query(int r, int ini, int fim) {
    unflag(r);
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

void update(int r, int ini, int fim) {
    unflag(r);
    if (M[r].ini > fim or M[r].fim < ini) return;
    if (ini <= M[r].ini and M[r].fim <= fim) {
        M[r].flag = 1;
        unflag(r);
        return;
    }
    update(M[r].esq, ini, fim);
    update(M[r].dir, ini, fim);
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
            update(raiz,l,r);
        } else {
            ii tt = query(raiz,l,r);
            if (tt.second == 0) // menor=0
                printf("sim\n");
            else
                printf("nao\n");
        }
    }

    return 0;
}
