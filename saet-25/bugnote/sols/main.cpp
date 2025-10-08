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
    ll n, q, ans = 0; cin >> n >> q; vs v(n); vll a(n); vll cnt(n,0);
    set<ll> b; // indices dos punidos
    rep(i,0,n) cin >> v[i] >> a[i];
    rep(i,0,q){
      string s; ll m; cin >> s >> m;
      rep(j,0,n) {
        if(s == v[j] && m <= a[j] && cnt[j] < 3){
          b.insert(j);
      }
        if(s == v[j] && m > a[j]) cnt[j]++;
        //cout << cnt[j] << endl;
    }  
  }
  ans = b.size();
  if(ans == 0) cout << -1 << endl;
  else{
    cout << ans << endl;
    for (auto i : b)
        cout << v[i] << endl;
  }
}
int main(){bazinga; solve(); return 0;}
