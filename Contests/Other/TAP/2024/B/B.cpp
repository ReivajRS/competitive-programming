#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
// PURO PINCHE BRO AC
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  bool esprimo = true;
  for(int i=2;i*i<=n;i++){
    if(n%i == 0) {
      esprimo = false;
      break;
    }
  }
  int N = n;
  if(esprimo){
    cout << 1 << ENDL;
    cout << "1 1" << ENDL;
    return 0;
  }
  vector<ll> divs;
  for(int i=2;i*i<=n;i++){
    if(n%i == 0) {
     divs.pb(i);
     if(n/i != i) divs.pb(n/i);
    }
  }
  sort(divs.rbegin(),divs.rend());
  auto can = [&](int x) -> bool {
    for(auto d:divs){
      if(d == x) continue;
      if(d%x == 0) return false;
    }
    return true;
  };
  vi ans;
  for(auto d:divs){
    if(can(d)) ans.pb(d);
  }
  cout << SZ(ans) << ENDL;
  for(auto x:ans){
    cout << "1 " << x << ENDL;
  }

  return 0;
}