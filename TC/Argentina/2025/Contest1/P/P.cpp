#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
//<>
struct DSU{
  vector<int> e;
  void init(int n){e = vector<int>(n,-1);}
  int get(int x){return e[x]<0?x:e[x]=get(e[x]);}
  bool join(int a,int b){
    a = get(a),b = get(b);
    if(a == b) return false;
    if(e[a]>e[b])swap(a,b);
    e[a]+=e[b];
    e[b] = a;
    return true;
  }
};

void solve(){
  int n;
  cin >> n;
  DSU dsu;
  dsu.init(n*2);
  vector<vi> pos(n);
  vector<vi> grupos(2*n);
  FOR(i,0,n){
    int x;
    cin >> x;
    x--;
    pos[x].push_back(i);
  }
  FOR(i,0,n){
    int x;
    cin >> x;
    x--;
    pos[x].push_back(i+n);
    }
  FOR(i,0,n){
    if(SZ(pos[i]) != 2) {
      cout << -1 << '\n';
      return;
    }
    int a = pos[i][0], b = pos[i][1];
    if((a < n && b < n)){
      dsu.join(a,b+n);
      dsu.join(a+n,b);
    }else if((a >= n && b >= n)){
      dsu.join(a,b-n);
      dsu.join(a-n,b);
    }else{
      if(a < n){
        dsu.join(a,b-n);
        dsu.join(a+n,b);
      }else{
        dsu.join(a-n,b);
        dsu.join(a,b+n);
      }
    }
  }
  vi ans;
  FOR(i,0,n){
    grupos[dsu.get(i)].push_back(i);
  }
  FOR(i,0,n){
    if(SZ(grupos[i])< SZ(grupos[i+n])){
      for(auto x:grupos[i]){
        ans.push_back(x);
        
      }
    }else{
      for(auto x:grupos[i+n]){
        ans.push_back(x);
      }
    }
  }
  cout << SZ(ans) << '\n';
  for(auto x:ans) cout << x+1 << " ";
  cout << '\n';
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}