#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int n;
  cin >> n;
  
  vi a(n);
  for (auto &x : a)
    cin >> x;

  ll sum = 0;

  auto brute_force = [&]() -> bool {
    vi b(n), cnt(n + 1, 0);
    int mx = 0;
    FOR (i, 0, n) {
      sum += a[i];
      cnt[a[i]]++;
      if (cnt[a[i]] >= 2) {
        mx = max(mx, a[i]);
      }
      b[i] = mx;
    }
    a = b;
    return mx != 0;
  };

  brute_force();

  if (!brute_force()) {
    cout << sum << ENDL;
    return;
  }

  int lptr = -1, rptr = n - 1;
  ll sum2 = 0;
  FOR (i, 0, n) {
    if (a[i] != 0 && lptr == -1) {
      lptr = i;
    }
    sum2 += a[i];
  }

  while (lptr <= rptr) {
    sum += sum2;
    sum2 -= a[rptr--];
  }

  cout << sum << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}