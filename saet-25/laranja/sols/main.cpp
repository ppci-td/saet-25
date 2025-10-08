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
    ll n, l = 0; cin >> n; vll f(13,1);
    rep(i,1,13) f[i] = f[i-1]*i;
    rep(i,0,n){
      ll g, c, ans = 0; cin >> g >> c;
      l += (g-c);
      if(l > 12){
        cout << -1 << endl;
        continue;
      }
      rep(j,0,5){
        rep(k,0,5){
          ll cur = l-k-j;
          if(0 <= cur && cur <= 4){
            ans += f[l]/(f[j]*f[k]*f[cur]);
          }
        }
      }
      cout << ans << endl;
    }
}
int main(){bazinga; solve(); return 0;}