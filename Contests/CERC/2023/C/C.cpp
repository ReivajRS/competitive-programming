#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

template<typename T>
struct Dinic{
  #define INF numeric_limits<T>::max()
  struct Edge{
    int to,rev;
    T c,oc;
    T flow() { return max(oc-c,T(0));}
  };
  vector<int> lvl,ptr,q;
  vector<vector<Edge>> adj;
  Dinic(int n):lvl(n),ptr(),q(n),adj(n){}
  void addEdge(int a,int b,T c,T rcap=0){
    adj[a].push_back({b,SZ(adj[b]),c,c});
    adj[b].push_back({a,SZ(adj[a])-1,rcap,rcap});
  }
  T dfs(int v,int t,T f){
    if(v == t or !f) return f;
    for(int &i = ptr[v];i<SZ(adj[v]);i++){
      Edge& e = adj[v][i];
      if(lvl[e.to] == lvl[v]+1) if(T p = dfs(e.to,t,min(f,e.c))){
        e.c -= p,adj[e.to][e.rev].c += p;
        return p;
      }
    }
    return 0;
  }
  T calc(int s,int t){
    T flow = 0;
    q[0] = s;
    FOR(L,0,31) do {
      lvl = ptr = vector<int>(SZ(q));
      int qi = 0,qe = lvl[s] = 1;
      while(qi < qe && !lvl[t]){
        int v = q[qi++];
        for(Edge e: adj[v]) if (!lvl[e.to] && e.c >> (30-L)) q[qe++] = e.to,lvl[e.to] = lvl[v]+1;
      }
      while(T p = dfs(s,t,INF)) flow += p;
    }
    while(lvl[t]);
    return flow;
  }
};

constexpr ll INF2 = 1e15;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int G,C,T;
  cin >> G >> C >> T;
  vector<ll> c(C),t(T),g(G);
  FOR(i,0,C) cin >> c[i];
  FOR(i,0,G) cin >> g[i];
  FOR(i,0,T) cin >> t[i];
  vector<ll> ganancia(C);
  int SOURCE = C+T+5,SINK = SOURCE+1;
  Dinic<ll> mf(SINK+1);
  ll ans = 0;
  FOR(i,0,C){
    ll ganancia = c[i];
    FOR(j,0,G){
      ll x;
      cin >> x;
      ganancia -= g[j] * x;
    }
    if(ganancia <= 0) continue;
    mf.addEdge(SOURCE,i,ganancia);
    ans += ganancia;
  }
  FOR(i,0,C){
    int n;
    cin >> n;
    while(n--){
      int idx;
      cin >> idx;
      idx--;
      mf.addEdge(i,idx+C,INF2);
    }
  }
  FOR(i,0,T){
    mf.addEdge(C+i,SINK,t[i]);
  }
  cout << ans - mf.calc(SOURCE,SINK) << '\n';

  return 0;
}