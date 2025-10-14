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
const ll INF = 1e18;

void solve(){
  ll n, m, q; cin >> n >> m >> q;
  vector<vector<pll>> adj(n+1);
    rep(i,0,m){
      ll x, y, d; ld h; cin >> x >> y >> d >> h;
      if(h >= 2.275 || h == 0){
        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
      }
    }
    
    vll destinos(q); rep(i,0,q) cin >> destinos[i];
    ll cur = 1;
   
    rep(i,0,q){
        ll aux = destinos[i];
        if(cur == aux){
            cout << 0 << endl;
            cur = aux;
            continue;
        }
        vector<ll> dist(n+1, INF);
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        dist[cur] = 0; 
        pq.push({0, cur});
        bool ok = false;
        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d != dist[u]) continue;
            if(u == aux){ 
                ok = true;
                break;
            }
            for (auto &e : adj[u]) {
                ll v = e.fi, w = e.se;
                if (dist[v] > d+w){
                    dist[v] = d+w;
                    pq.push({dist[v], v});
                }
            }
        }
        if(dist[aux] == INF) cout << -1 << endl;
        else {
            cout << dist[aux] << endl;
            cur = aux;
        }
    }
}
int main(){bazinga; solve(); return 0;}