#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)


struct DSU{
  vector<int> e;
  void init(int n){e = vector<int>(n,-1);}
  int size(int x){return -e[get(x)];}
  int get(int x){return e[x]<0 ? x:e[x] = get(e[x]);}
  bool join(int a,int b){
    a = get(a),b = get(b);
    if(a==b) return false;
    if(e[a]>e[b]) swap(a,b);
    e[a]+=e[b];
    e[b] = a;
    return true;
  }
};

struct Edge{
  ll u,v,a,b,c;
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m;
  cin >> n>>m;
  vector<Edge> edges(m);
  FOR(i,0,m){
    ll u,v,a,b,c;
    cin >> u >> v >> a >> b >> c;
    u--,v--;
    edges[i] = {u,v,a,b,c};
  }

  auto mst = [&](int n,ld t) -> ld {
    vector<tuple<ld,int,int>> e(m);
    FOR(i,0,m){
      e[i] = {edges[i].a * t * t + edges[i].b * t+ edges[i].c ,edges[i].u,edges[i].v};
    } 
    sort(e.begin(),e.end());
    DSU dsu;
    dsu.init(n);
    ld mst = 0;
    for(auto &[w,u,v]:e){
      if(dsu.join(u,v)){
        mst+=w;
        if(--n == 1) break;
      }
    }
    return mst;
  };

  ld L = -1000000,R = 1000000;
  FOR(i,0,10000){
    ld m1 = L+(R-L)/3;
    ld m2 = R-(R-L)/3;
    ld f1 = mst(n,m1);
    ld f2 = mst(n,m2);
    if(f1>f2) L = m1;
    else R = m2;
  }
  cout << setprecision(12) << fixed;
  cout << mst(n,L) << '\n';

  return 0;
}