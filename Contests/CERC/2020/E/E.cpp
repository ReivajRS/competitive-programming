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
  ll N = 40,M=5000;
  
  cout << M*N << ENDL;
  FOR(i,0,M){
    FOR(j,0,N){
      cout << i*2 << " " << j << " " << (j == 0 ? 1 : 0) << ENDL;
    }
  }
  

  vector<ll> a(N+2);
  a[1] = 1;

  FOR(d,0,N-1){
    vector<ll> curr(N+2);
    FOR(i,1,N+1){
      curr[i] = a[i-1] + a[i] + a[i+1];
    }
    swap(a,curr);
  }
  vector<ll> ori(a.begin(),a.end());

  sort(a.rbegin(),a.rend());

  map<ll,ll> mp;

  FOR(i,0,N){
      FOR(j,1,N+1){
        if(a[i] == ori[j]){
          mp[a[i]] = j-1;
        }
      }
  }
  
  ll currFila = 0;
  vector<pair<ll,ll>> ans;
  ll pos = 0;
  while(n){
    while(n>=a[pos]){
      n-=a[pos];
      ans.push_back({currFila,mp[a[pos]]});
      currFila+=2;
    }
    pos++;
  }
  cout << SZ(ans)<< " " << N-1 <<ENDL;
  for(auto [x,y]:ans){
    cout << x << " " << y << ENDL;
  }

  return 0;
}