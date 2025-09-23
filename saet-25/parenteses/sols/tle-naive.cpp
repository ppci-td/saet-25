#include <bits/stdc++.h>

using namespace std;

int n, q, tipo, l, r;
char s[200020];

int main() {

    scanf("%d %d",&n, &q);
    scanf("%s",s);
    while (q--) {
        scanf("%d %d %d", &tipo, &l, &r); l--; r--;
        if (tipo==1) {
            for (int i=l;i<=r;i++)
                if (s[i]=='(') s[i]=')';
                else s[i]='(';
        } else {
            if ((r-l+1)%2==1) { // impar
                printf("nao\n");
                continue;
            }
            int saldo=0;
            for (int i=l;i<=r;i++)
                if (s[i]=='(') saldo++;
                else {
                    saldo--;
                    if (saldo<0) break;
                }
            if (saldo==0)
                printf("sim\n");
            else
                printf("nao\n");
        }
    }

    return 0;
}
