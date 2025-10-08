#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n, q;
char nome[2000][11];
int codigo[2000];
int erros[2000];
bool imune[2000];
bool punido[2000];
char s[11];
int linha;

int main() {

    scanf("%d %d", &n, &q);
    for (int i=0;i<n;i++) {
        scanf("%s %d", nome[i], codigo+i);
        erros[i]=0;
        imune[i]=false;
        punido[i]=false;
    }
    while (q--) {
        scanf("%s %d", s, &linha);
        for (int i=0;i<n;i++)
            if (!strcmp(s, nome[i])) {
                if (!imune[i] and linha <= codigo[i])
                    punido[i]=true;
                else {
                    erros[i]++;
                    if (erros[i] >= 3)
                        imune[i] = true;
                }
                break;
            }
    }
    vector<char *> resp;
    for (int i=0;i<n;i++)
        if (punido[i])
            resp.pb(nome[i]);
    if (resp.empty())
        printf("-1\n");
    else {
        printf("%d\n", (int)resp.size());
        for (int i=0;i<(int)resp.size();i++)
            printf("%s\n", resp[i]);
    }

    return 0;
}
