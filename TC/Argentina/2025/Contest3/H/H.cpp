#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<string> a(n);
  FOR(i,0,n) cin >> a[i];
  vector<vector<int>> g(26);
  vector<int> in(26,0);
  FOR(i,0,n-1){
    int j = 0;
    while(j<SZ(a[i]) && j < SZ(a[i+1]) && a[i][j] == a[i+1][j]) j++;
    
    if(j<SZ(a[i]) && j < SZ(a[i+1])){ 
      //cout << a[i][j]-'a' << " ";
      int u = a[i][j]-'a';
      int v = a[i+1][j]-'a';
      g[u].push_back(v);
      in[v]++;
    }
    
    if(j == SZ(a[i+1]) && SZ(a[i+1])<SZ(a[i])){
      cout << "Impossible" << '\n';
      return 0;
    }
      
  }
  
  priority_queue<int> q;
  FOR(i,0,26){
    if(in[i] == 0) q.push(-i);
  }
  vector<int> ans;
  while(!q.empty()){
    int u = -q.top();
    q.pop();
    ans.push_back(u);
    for(auto v:g[u]){
      in[v]--;
      if(in[v] == 0) q.push(-v);
    }
  }
  if(SZ(ans)!=26){
    cout << "Impossible" << '\n';
    return 0;
  }
  for(auto x:ans) cout << char(x+'a');
  
  cout << '\n';

  return 0;
}