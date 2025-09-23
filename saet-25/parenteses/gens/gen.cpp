#include "testlib.h"
#include <assert.h>

using namespace std;

typedef pair<int, int> ii;
char s[200020];
vector<ii> validas;

// gera uma valida em s[ini.fim]
void gera(int ini, int fim) {
    if (ini > fim) return;
    int r = rnd.next(1,2);
    if (r==1 or fim==ini+1) {
        s[ini] = '(';
        s[fim] = ')';
        gera(ini+1,fim-1);
    } else {
        int tam = (fim-ini+1);
        int lim;
        do {
            lim = rnd.next(2,tam-2);
        } while (lim%2 == 1); // num par de 2 ate tam-2
        gera(ini, ini+lim-1);
        gera(ini+lim,fim);
    }
    validas.push_back(ii(ini+1,fim+1)); // eh valida
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>(1), q = opt<int>(2);
    printf("%d %d\n",n,q);
    assert( (n%2) == 0 );
    validas.clear();
    gera(0,n-1);
    s[n]='\0';
    printf("%s\n",s);
    while (q--) {
        int t, l, r;
        do {
            t = rnd.next(1,2);
            int i = rnd.next(1, (int)validas.size());
            i--;
            l = validas[i].first;
            r = validas[i].second;
        } while (t==2 and (r-l+1)%2==1); // 2 soh par
        printf("%d %d %d\n",t,l,r);
    }
}
