#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m,t;
  cin >> n>>m>>t;
  
  map<string,vector<pair<int,int>>> mp;
  FOR(i,0,n){
    FOR(j,0,m){
      string s = "";
      FOR(k,0,t){
        char c;
        cin >> c;
        s+=c;
      }
      mp[s].push_back({i,j});
    }
  }
  for(auto &[s,v]:mp){
    if((int)v.size() == 1){
      cout << v[0].first+1 << " " << v[0].second+1 << '\n';
      return 0;
    }
  }

  return 0;
}