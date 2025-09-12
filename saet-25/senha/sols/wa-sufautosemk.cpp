// constroi o suffix automata e conta quantas substrings distintias existem,
// ignorando o valor de k
// codigo de https://cp-algorithms.com/string/suffix-automaton.html
#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[200020];

struct state {
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 200020;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

long long get_diff_strings(){
    long long tot = 0;
    for(int i = 1; i < sz; i++) {
        tot += st[i].len - st[st[i].link].len;
    }
    return tot;
}
int main() {

    scanf("%d %d",&n,&k);
    scanf("%s",s);
    // duplica
    for (int i=n;i<2*n;i++)
        s[i] = s[i-n];
    s[2*n]='\0';
    n = 2*n;

    sa_init();

    for (int i=0;i<n;i++)
        sa_extend(s[i]);

    printf("%lld\n",get_diff_strings());

    return 0;
}
