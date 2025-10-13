#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mae max_element
#define mie min_element
#define lb lower_bound
#define up upper_bound
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vb vector<bool>
#define pll pair<ll,ll>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define allx(v,x) all(v) v.begin(), v.end(), x
#define rep(i,j,n) for (ll i=j; i<(n); i++)
#define srep(i,j,n) for (ll i=j; i<(n); i--)
#define bazinga ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
    ll n; ull x; string s; cin >> n >> x >> s;

    unordered_map<char, int> nucl = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    char saida[4] = {'A', 'C', 'G', 'T'};
    ll complementos[4] = {3, 2, 1, 0};

    string ans; ans.reserve(n);
    ull curxor = x;

    rep(i,0,n){
        ll val = nucl[s[i]]; 
        curxor ^= val;  
        ll ciclo = curxor % 4;   
        ll aux = (complementos[val] + ciclo) % 4;
        ans.pb(saida[aux]);
    }

    cout << ans << endl;
}
int main(){bazinga; solve(); return 0;}