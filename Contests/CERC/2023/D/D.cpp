#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct Data {
  int d, fast, slow;

  bool operator<(Data& other) const {
    return slow < other.slow;
  }
  bool operator==(Data& other) const {
    return slow == other.slow;
  }
};

constexpr int maxw = 3e5 + 5;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<Data> a(n);
  for (Data& data : a) {
    cin >> data.d >> data.fast >> data.slow;
  }

  sort(a.begin(), a.end());

  vector<bitset<maxw>> dp(n + 1);
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = dp[i] | (dp[i] << a[i].d);
  }

  vector<ll> ps(n + 1);
  for (int i = 0; i < n; ++i) {
    ps[i + 1] = ps[i] + a[i].d;
  }

  vector<int> mxFast(n + 1);
  mxFast.back() = 0;
  for (int i = n - 1; i >= 0; --i) {
    mxFast[i] = max(mxFast[i + 1], a[i].fast);
  }
  
  while (q--) {
    int len;
    cin >> len;
    
    auto f = [&](int t) -> bool {
      Data d = {0, 0, t};
      int i = upper_bound(a.begin(), a.end(), d) - a.begin();
      if (t < mxFast[i]) {
        return false;
      }
      int k = ps[n] - ps[i];
      int bit = dp[i].
    };

    int l = 1, r = 1e9;
    while (l < r) {
      int m = (l + r) / 2;
      if (f(m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << l << '\n';
  }

  return 0;
}