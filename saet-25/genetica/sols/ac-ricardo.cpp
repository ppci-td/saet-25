#include <bits/stdc++.h>

using namespace std;

int n, x;
char s[100010];

int indx(char c) {
    if (c=='A') return 0;
    if (c=='C') return 1;
    if (c=='G') return 2;
    if (c=='T') return 3;
    assert(1==2);
}

char letra(int i) {
    if (i==0) return 'A';
    if (i==1) return 'C';
    if (i==2) return 'G';
    if (i==3) return 'T';
    assert(1==2);
}

int comple(int i) {
    if (i==0) return 3;
    if (i==1) return 2;
    if (i==2) return 1;
    if (i==3) return 0;
    assert(1==2);
}

int main() {

    scanf("%d %d",&n, &x);
    scanf("%s", s);
    for (int i=0;s[i];i++) {
        x ^= indx(s[i]);
        printf("%c", letra((( comple( indx(s[i]) ) )+x)%4));
    }
    printf("\n");

    return 0;
}
