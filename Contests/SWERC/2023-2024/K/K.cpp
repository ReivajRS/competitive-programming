#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF (i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
  int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1)
      if (pos + pw <= SZ(s) && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    return pos;
  }
};

signed main() { __
  int n;
  cin >> n;
  vi a(n/2), b(n/2);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;

  FT bit(n + 1);
  FOR (i, 0, n)
    bit.update(i, 1);
  
  vi p1, p2;
  n >>= 1;
  FOR (i, 0, n) {
    int pos1 = bit.lower_bound(a[i]);
    p1.pb(pos1 + 1);
    bit.update(pos1, -1);
    int pos2 = bit.lower_bound(b[i]);
    p2.pb(pos2 + 1);
    bit.update(pos2, -1);
  }

  for (auto &x : p1)
    cout << x << ' ';
  cout << ENDL;

  for (auto &x : p2)
    cout << x << ' ';
  cout << ENDL;
  
  return 0;
}