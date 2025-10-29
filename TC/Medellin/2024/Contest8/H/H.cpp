#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

struct SuffixArray {
  vi SA, LCP;
  string S;
  int n;
  SuffixArray(string &s, int lim = 256) : S(s), n(SZ(s) + 1) {  // O(n log n)
    int k = 0, a, b;
    vi x(ALL(s) + 1), y(n), ws(max(n, lim)), rank(n);
    SA = LCP = y, iota(ALL(SA), 0);

    // Calcular SA
    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
      p = j, iota(ALL(y), n - j);
      FOR(i, 0, n) {
        if (SA[i] >= j) y[p++] = SA[i] - j;
      }
      fill(ALL(ws), 0);
      FOR(i, 0, n) {
        ws[x[i]]++;
      }
      FOR(i, 1, lim) {
        ws[i] += ws[i - 1];
      }
      for (int i = n; i--;) SA[--ws[x[y[i]]]] = y[i];
      swap(x, y), p = 1, x[SA[0]] = 0;
      FOR(i, 1, n) {
        a = SA[i - 1];
        b = SA[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
      }
    }

    FOR(i, 1, n) {
      rank[SA[i]] = i;
    }
    for (int i = 0, j; i < n - 1; LCP[rank[i++]] = k)
      for (k &&k--, j = SA[rank[i] - 1]; s[i + k] == s[j + k]; k++)
        ;
  }

  vi constructRSA(){
    vi RSA(n);
    FOR(i,0,n){
      RSA[SA[i]] = i;
    }
    return RSA;
  }
};

constexpr int INF = 5e8;


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m,d,s;
  cin >> n >> m >> d >> s;
  s--;
  string t;
  cin >> t;
  SuffixArray sa(t);
  vi rsa = sa.constructRSA();

  vector<vector<pi>> g(n,vector<pi>(n,{INF,INF}));
  FOR(i,0,m){
    int u,v,p,l;
    cin >> u >> v >> p >> l;
    p--,u--,v--;
    int aux = rsa[p];
    while(sa.LCP[aux] >= l){
      aux--;
    }
    g[u][v] = {aux,l};
  }

  vector<vi> p(n,vi(n,-1));
  FOR(i,0,n){
    FOR(j,0,n){
      p[i][j] = i;
    }
  }

  FOR(k,0,n){
    FOR(i,0,n){
      FOR(j,0,n){
        if(make_pair(g[i][k].first + g[k][j].first,g[i][k].second) < g[i][j]){
          p[i][j] = p[k][j];
        }
        g[i][j] = min(g[i][j],{g[i][k].first+g[k][j].first,g[i][k].second});
      }
    }
  }
vi path;
  auto printPath =[&](auto self,int i,int j) -> void{
    if(i!=j) self(self,i,p[i][j]);
    path.pb(j+1);
  };

  FOR(i,0,n){
    if(i == s){
      cout << "1 " << s+1 << ENDL;
      continue;
    }
    if(g[s][i].first >= INF){
      cout << 0 << ENDL;
      continue;
    }
    path.clear();
    printPath(printPath,s,i);
    cout << SZ(path);
    for(auto x:path){
      cout << " " << x;
    }
    cout << ENDL;
  }


  return 0;
}