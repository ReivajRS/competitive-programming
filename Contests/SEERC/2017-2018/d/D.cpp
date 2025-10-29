#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a-1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

struct DSU{
  vi e;
  void init(int n) { e = vi(n,-1);}
  int size(int x){return -e[get(x)];}
  int get(int x){return e[x]<0 ? x : e[x] = get(e[x]);}
  bool join(int a,int b){
    a = get(a),b = get(b);
    if(a == b) return false;
    if(e[a]>e[b]) swap(a,b);
    e[a]+=e[b];
    e[b] = a;
    return true;
  }
};

signed main() { __

  int m,n;
  cin >> m >> n;
  vector<vi> g(n + 1,vi());
  FOR(i,0,m){
    int k;
    cin >> k;
    while(k--){
      int x;
      cin >> x;
      g[x].pb(i+1);
    }
  }

  DSU dsu;
  dsu.init(m+5);

  FOR(i,1,n+1){
    g[i].pb(0);
    g[i].pb(0);
  }

  int ans = 0;
  FOR(i,1,n+1){
    ans += dsu.join(g[i][0],g[i][1]);
  }
  cout << ans << ENDL;

  return 0;
}