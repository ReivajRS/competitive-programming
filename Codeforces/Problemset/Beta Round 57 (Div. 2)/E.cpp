#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

struct BIT {
  int n;
  vector<int> bit;
  BIT(int sz) : n(sz), bit(n + 1) {}
  void update(int i, int val) {
    i++;
    while (i <= n) {
      bit[i] += val;
      i += i & -i;
    }
  }
  int query(int i) {
    i++;
    int sum = 0;
    while (i >= 1) {
      sum += bit[i];
      i -= i & -i;
    }
    return sum;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> b = a;
  
  sort(b.begin(), b.end());
  map<int, int> mp;
  for (auto &x : b) mp[x] = SZ(mp);

  vector<int> lg(n), rl(n);
  BIT bit1(n), bit2(n);

  for (int i = 0; i < n; i++) {
    lg[i] = bit1.query(n - 1) - bit1.query(mp[a[i]]);
    bit1.update(mp[a[i]], 1);
  }
  for (int i = n - 1; i >= 0; i--) {
    rl[i] = bit2.query(mp[a[i]]);
    bit2.update(mp[a[i]], 1);
  }
  
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (ll)lg[i] * rl[i];
  }

  cout << ans << '\n';

  return 0;
}