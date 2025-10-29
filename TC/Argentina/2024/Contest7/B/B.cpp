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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll a,b,c;
  cin >> a >> b >> c;
  ll mx = max({a,b,c});
  ll ans = max(0ll,mx-a-1);
  ans+=max(0ll,mx-b-1);
  ans+=max(0ll,mx-c-1);
  cout << ans << ENDL;

  return 0;
}