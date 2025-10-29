#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for (ll i = (ll)a-1; i >= (ll)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0);

struct Line{
  ll m,c,idx;
};

signed main() { __
  
  ll n;
  cin >> n;
  vector<Line> lineas(n);
  set<ll> disponibles;
  FOR(i,0,n){
    cin >> lineas[i].c >> lineas[i].m;
    lineas[i].idx = i;
    disponibles.insert(i);
  }
  priority_queue<tuple<long double,ll,ll>> pq;
  auto ller = [&](ll i,ll j) -> void {
    // m1x + c1 = m2x + c2
    // m1x - m2x = c2 - c1
    // x(m1 - m2) = c2 - c1
    // x = (c2 - c1) / (m1 - m2)
    if(lineas[i].m <= lineas[j].m){
      return;
    }
    long double x = 1.0 * (lineas[j].c - lineas[i].c) / (lineas[i].m - lineas[j].m);
    pq.push({-x,i,j});
  };
  FOR(i,0,n-1){
    ller(i,i+1);
  }

  while(SZ(pq)){
    auto [t,l1,l2] = pq.top();
    pq.pop();
    if(disponibles.count(l1) && disponibles.count(l2)){
      disponibles.erase(l1);
      disponibles.erase(l2);

      ll sig = -1,ant = -1;
      if(disponibles.lower_bound(l2) != disponibles.end()){
        sig = *disponibles.lower_bound(l2);
      }
      if(disponibles.lower_bound(l1) != disponibles.begin()){
        ant = *(--disponibles.lower_bound(l1));
      }
      if(ant != -1 && sig != -1){
        ller(ant,sig);
      }      

      continue;
    }

  }
  cout << SZ(disponibles) << ENDL;
  for(auto x:disponibles){
    cout << x+1 << " ";
  }
  cout << ENDL;

  return 0;
}