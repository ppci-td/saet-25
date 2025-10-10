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
  const ll MX = 12*60*60;

  ll n; cin >> n; vll v(n);
  rep(i,0,n){
    ll h, m, s; cin >> h >> m >> s;
    v[i] = h*3600 + m*60 + s;
  }

  sort(all(v));
  ll soma = 0;
  rep(i,0,n) soma += v[i];
  
  ll ans = LLONG_MAX;
  rep(i,0,n){
    if(i > 0 && v[i] == v[i-1]) continue;
    ll cur = v[i];
    ll custo = soma - n*cur + i*MX;
    if(custo < ans) ans = custo;
  }
  
  cout << ans << endl;
}
int main(){bazinga; solve(); return 0;}