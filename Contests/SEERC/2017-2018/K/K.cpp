#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a-1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

struct FT{
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos,ll dif){
    for (;pos<SZ(s);pos|=pos+1)s[pos]+=dif;
  }
  ll query(int pos){
    // 3 2 2 2 1 1
    // 1 4 3 2 6 5


    ll res = 0;
    for(;pos>0;pos&=pos - 1) res += s[pos-1];
    return res;
  }
  int lower_bound(ll sum) {
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= SZ(s) && s[pos + pw - 1] < sum) {
        pos += pw, sum -= s[pos - 1];
      }
    }
    return pos;
  }
};

signed main() { __
  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a) {
    cin >> x;
    x--;
  }

  vi g(n);
  FT gft(n);
  for (int i = n - 1; i >= 0; i--) {
    g[i] = gft.query(n) - gft.query(a[i]);
    gft.update(a[i], 1);
  }

  FT bueno(n);
  FOR (i, 0, n) {
    bueno.update(i, 1);
  }
    // 2 2 3 2 1 1
    // 1 2 3 4 5 6
    // 4 3 1 2 6 5
  FOR (i, 0, n) {
    int x = bueno.lower_bound(g[i] + 1);
    assert(x != -1);
    cout << x + 1 << " ";
    bueno.update(x, -1);
  }
  cout << ENDL;

  return 0;
}