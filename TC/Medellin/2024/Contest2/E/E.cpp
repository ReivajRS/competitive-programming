#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

void solve(){
  ll n;
  cin >> n;
  map<ll,ll> mapa;
  FOR(i,1,n+1){
    ll x;
    cin >> x;
    mapa[-(i+x)]++;
  }

  for(auto [nn,cnt]:mapa){
    ll num = -nn;
    cout << num << " ";
    cnt--;
    if(cnt)
      mapa[-(num-1)] += cnt;
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}