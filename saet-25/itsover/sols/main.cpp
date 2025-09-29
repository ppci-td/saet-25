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

const ll LIM = 1e6;
vb primo(LIM+1, true);
 
void crivo(){
    primo[0] = primo[1] = false;
    for(ll i = 2; i*i <= LIM; i++){
        if(primo[i]) {
            for(ll j = i*i; j <= LIM; j+= i){
                primo[j] = false;
            }     
        }
    }
}

void solve(){
    crivo();
    ll n, ans = 0; cin >> n; vll a;
    rep(i,0,n){
      ll m, cur = 0; cin >> m; vll v(m);
      rep(i,0,m){
        cin >> v[i];
        if(primo[i+1]) cur += v[i];
      }
        if(primo[cur]) {
          ans++;
          a.pb(cur);
        }
    }
    if(ans == 0) cout << "ITS OVER SOBROU NADA PRO BETINHA" << endl;
    else{
      cout << ans << endl;
      rep(i,0,a.size()){
        if(i == a.size()-1) cout << a[i];
        else cout << a[i] << " ";
      }
      cout << endl;
    }
}
int main(){bazinga; solve(); return 0;}