#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
  ll n, mn = LLONG_MAX, mx = 0; cin >> n;
  bool primeiro = true;
  vll d(n), m(n), a(n);
  rep(i,0,n){
    cin >> d[i] >> m[i] >> a[i];
    ll cnt = 0;
    // if(primeiro){
    //   primeiro = false;
    //   continue;
    // }
    cnt = (a[i]-a[i-1])*365 + (m[i]-m[i-1])*30 + (d[i]-d[i-1]);
    
    mx = max(mx, cnt);
    mn = min(mn, cnt); 
  }

  cout << mn << " " << mx << endl;
}
int main(){bazinga; solve(); return 0;}