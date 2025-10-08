#include <bits/stdc++.h>
#define pb push_back
#define ll long long int
#define SIZE 20000020ll

using namespace std;
int n, m;
bool primo[SIZE];

int main() {

    memset(primo,true,sizeof(primo));
    primo[0]=false;
    primo[1]=false;
    for (int i=2;i<SIZE;i++) if (primo[i]) {
        for (ll j = (ll)i*(ll)i; j < SIZE; j += i)
            primo[j]=false;
    }

    vector<int> resp;
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d",&m);
        int soma=0;
        for (int i=1;i<=m;i++) {
            int t;
            scanf("%d",&t);
            if (primo[i])
                soma += t;
        }
        if (primo[soma])
            resp.pb(soma);
    }
    if (resp.empty())
        printf("ITS OVER SOBROU NADA PRO BETINHA\n");
    else {
        printf("%d\n", (int)resp.size());
        for (int i=0;i<(int)resp.size();i++) {
            if (i) printf(" ");
            printf("%d",resp[i]);
        }
        printf("\n");
    }

    return 0;
}
