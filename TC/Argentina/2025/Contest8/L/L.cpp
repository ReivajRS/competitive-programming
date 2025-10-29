#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)

void solve(){
  int n,m;
  cin >> n >> m;
  vector<int> cap(n);
  vector<int> bat(n);
  FOR(i,0,n) cin >> cap[i];
  vector<int> x(m),t(m);
  vector<vector<int>> stations(n);
  FOR(i,0,m){
    cin >> x[i] >> t[i];
    t[i]--;
    stations[t[i]].push_back(x[i]);
  }
  ll ans = 0;
  
  priority_queue<pair<int,int>> pq;
  FOR(i,0,n){
    bat[i] = cap[i];
    ans+=bat[i];
    stations[i].push_back(1e9+10);
    pq.push({-stations[i][0],i});
    
  }
    

  ll curr = 0;
  FOR(i,0,m){
    while(curr < x[i] && SZ(pq)){
      auto [nxtStation,idx] = pq.top();
      pq.pop();


      // ya paso no sirve :(
      if(-nxtStation < x[i]){
        pq.push({-(*lower_bound(stations[idx].begin(),stations[idx].end(),x[i])),idx});
        continue;
      }
      // llego y me sobra a la roña
      if(bat[idx] + curr > x[i]){
        bat[idx] -= (x[i]-curr);
        curr = x[i];
        pq.push({nxtStation,idx});
      }else{
        curr+=bat[idx];
        bat[idx] = 0;
      }
    }
    // no llego :(
    if(curr < x[i]) break;

    ans+=cap[t[i]]-bat[t[i]];
    // ya sirve la sig estacion
    if(bat[t[i]] == 0)  pq.push({-(*upper_bound(stations[t[i]].begin(),stations[t[i]].end(),x[i])),t[i]});
    bat[t[i]] = cap[t[i]];
  }
  
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int t;
  cin >> t;
  while(t--) solve();
  
  return 0;
}