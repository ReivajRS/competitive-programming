#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  
  int n;
  cin >> n;
  map<string,string> quiere;
  map<string,pair<string,int>> tiene;
  vector<string> nombres(n);
  FOR(i,0,n){
    string name,s1,s2;
    cin >> name >> s1 >> s2;
    nombres[i] = name;
    quiere[name] = s2;
    tiene[s1] = {name,i};
  }

  int ans = 0;
  FOR(i,0,n){
    int cnt = 0;
    string curr = nombres[i];
    vi vis(n,0);
    vis[i] = true;
    int currI = i;
    bool work = false;
    while(true){
      //cout << curr << ENDL;
      string busca = quiere[curr];
      //cout << busca << ENDL;
      if(!tiene.count(busca)) break;
      cnt++;
      curr = tiene[busca].first;
      currI = tiene[busca].second;
      if(vis[currI]){
        work = true;
        break;
    }
    vis[currI] = true;
    }
    if(work)
      ans = max(cnt,ans);
  }
  if(ans == 0){
    cout << "No trades possible" << ENDL;
    return 0;
  }
  cout << ans << ENDL;

  return 0;
}