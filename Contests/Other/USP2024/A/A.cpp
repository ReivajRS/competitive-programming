#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)

#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vector<tuple<ll,ll,ll,ll>> a(n);
  FOR(i,0,n){
    ll t,m,c;
    cin >> t>>m >> c;
    a[i] = {t,m,c,i};
  }
  sort(a.begin(),a.end());
  deque<tuple<ll,ll,ll>> q;
  ll curr = 0;
  vector<ll> ans;
  FOR(i,0,n){
    auto [t,m,c,idx] = a[i];
    if(c == 0){
      q.push_back({t,m,idx});
      continue;
    }
    bool ok = true;
    int cnt=0;
    while(SZ(q) && cnt++<10){
      auto [t2,m2,idx2] = q.front();
      q.pop_front();
      ll termina = max(curr,t2) + m2;
      if(termina <= t){
        curr = termina;
      }else{
        ans.push_back(idx2);
        q.push_front({t,m,idx});
        curr = t;
        ok = false;
        break;
      }
    }
    if(ok) q.push_front({t,m,idx});
  }

  cout << SZ(ans) << ENDL;
  for(auto x:ans) cout << x+1 << " ";
  cout << ENDL;

  return 0;
}