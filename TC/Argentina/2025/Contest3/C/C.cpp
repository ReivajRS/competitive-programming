#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

const int MAX = 8e5+5;
int top = 0;
map<char,int> nxt[MAX];
list<int> a[MAX],b[MAX];
void insert(string &s,int id,int flag){
  int curr = 0;
  for(auto c:s){
    if(!nxt[curr].count(c)){
      nxt[curr][c] = ++top;
    }
    curr = nxt[curr][c];
  }
  if(flag) b[curr].push_back(id);
  else a[curr].push_back(id);
}
ll res = 0;
vector<pair<int,int>> ans;
void dfs(int u,int d = 0) {
  FOR(i,'a','z'+1){
    if(nxt[u].count(i)) {
      dfs(nxt[u][i],d+1);
      a[u].splice(a[u].end(),a[nxt[u][i]]);
      b[u].splice(b[u].end(),b[nxt[u][i]]);
    }
  }
  int cnt = min(SZ(a[u]),SZ(b[u]));
  while(cnt--){
    ans.push_back({a[u].back(),b[u].back()});
    a[u].pop_back();
    b[u].pop_back();
    res +=d;
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  string s;
  FOR(i,0,n){
    cin >> s;
    insert(s,i,0);
  }
  FOR(i,0,n){
    cin >> s;
    insert(s,i,1);
  }

  ans.reserve(n);
  dfs(0);

  cout << res << '\n';
  for(auto [x,y]:ans){
    cout << x+1 << " " << y+1 << '\n';
  }


  return 0;
}