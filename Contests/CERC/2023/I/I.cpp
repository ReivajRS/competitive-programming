#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {

  int n;
  cin >> n;
  cout << "QUERY ";
  FOR(i,0,n) cout << "1";
  cout << endl;
  queue<int> q;
  vector<int> hojas(n);
  FOR(i,0,n){
    cin >> hojas[i];
    if(hojas[i] == 1){
      q.push(i);
    }
  }

  vector<vector<int>> precalc(n,vector<int>(15,0));
  FOR(i,0,15){
    string b = "";
    FOR(u,0,n){
      if(u>>i & 1) b+='1';
      else b+='0';
    }
    cout << "QUERY " << b << endl;

    FOR(u,0,n){
      cin >> precalc[u][i];
    }
  }

  vector<pair<int,int>> edges;
  FOR(i,0,n-1){
    int u = q.front();
    q.pop();

    int v = 0;
    FOR(i,0,15){
      if(precalc[u][i]) {
        v += (1<<i);
      }
    }
    edges.push_back({u,v});

    FOR(i,0,15){
      if((u>>i & 1) && precalc[v][i]) precalc[v][i]--; 
    }
    hojas[v]--;
    if(hojas[v] == 1) q.push(v);

  }
  cout << "ANSWER\n";
  for(auto [u,v]:edges){
    cout << u+1 << " " << v+1 << "\n";
  }
  cout << endl;

  return 0;
}