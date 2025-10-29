#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int,int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

bool checkR(pi a,pi b){
  return (a.first == b.first || a.second == b.second);
}

bool checkB(pi a,pi b){
  return (a.second-a.first == b.second-b.first || a.second+a.first == b.second+b.first); 
}

bool checkQ(pi a,pi b){
  return (checkR(a,b) || checkB(a,b));
}

bool checkN(pi a,pi b){
  return(
    (abs(a.first-b.first) == 2 && abs(a.second-b.second) == 1)
    ||
    (abs(a.first-b.first) == 1 && abs(a.second-b.second) == 2)
  );
}

bool checkK(pi a,pi b){
  return(abs(a.first-b.first) <= 1 && abs(a.second-b.second) <= 1);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  char type;
  cin >> n >> type;
  vector<pair<int,int>> pieces;
  FOR(i,0,n){
    FOR(j,0,n){
      char c;
      cin >> c;
      if(c != '.'){
        pieces.push_back({i,j});
      }
    }
  }
  int m = SZ(pieces);
  vector<vector<int>> g(m);
  FOR(i,0,m){
    FOR(j,i+1,m){
      bool ok = (type == 'R' && checkR(pieces[i],pieces[j]));
      ok |= (type == 'Q' && checkQ(pieces[i],pieces[j]));
      ok |= (type == 'B' && checkB(pieces[i],pieces[j]));
      ok |= (type == 'N' && checkN(pieces[i],pieces[j]));
      ok |= (type == 'K' && checkK(pieces[i],pieces[j]));

      if(ok){
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  vector<int> vis(m,0);
  int cnt = 0;
  vector<tuple<int,int,int,int>> ans;
  auto dfs = [&](auto self,int u,int p) -> void {
    cnt++;
    vis[u] = 1;
    for(auto v:g[u]){
      if(vis[v]) continue;
      self(self,v,u);
    }
    if(p != -1)
      ans.push_back({pieces[u].first,pieces[u].second,pieces[p].first,pieces[p].second});
  };

  dfs(dfs,0,-1);
  if(cnt != m){
    cout << "NO" << ENDL;
    return 0;
  }
  cout << "YES" << ENDL;
  for(auto [x1,y1,x2,y2]:ans){
    cout << x1+1 << " " << y1+1 << " "<< x2+1 << " " << y2+1 << ENDL;
  }

  return 0;
}