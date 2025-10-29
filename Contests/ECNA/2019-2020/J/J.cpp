#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n,m;
  cin >> n>>m;

  vector<pi> v(n);
  for (auto &[d, l] : v) {
    cin >> l >> d;
  }
  sort(ALL(v));

  auto can = [&](ll x){
    priority_queue<int> pq;
    ll hojas = 0;
    FOR(i,0,n){
      if(hojas + v[i].second <= v[i].first*x){
        hojas+=v[i].second;
        pq.push(v[i].second);
      }else if(SZ(pq) && pq.top() > v[i].second){
        hojas-=pq.top();
        hojas+=v[i].second;
        pq.pop();
        pq.push(v[i].second);
      }
    }
    int M = n-SZ(pq);
    return M<=m;
  };

  ll l = 1, r = 1e15;
  while(l<r){
    ll mid = (l+r)/2;
    if(can(mid)){
      r=mid;
    }else{
      l=mid+1;
    }
  }

  cout << r << ENDL;

  return 0;
}