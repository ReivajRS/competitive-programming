#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> b(n * m);
  for (auto &x : b) cin >> x;
  ll ans1 = 0, ans2 = 0;
  if (m > n) swap(n, m);
  sort(ALL(b));
  ans1 = (b.back() - b[0])*(n-1) + (b.back() - b[1])*(m-1) + (b.back() - b[0])*(n-1)*(m-1);
  sort(ALL(b), greater<ll>());
  ans2 = (b.back() - b[0])*(n-1) + (b.back() - b[1])*(m-1) + (b.back() - b[0])*(n-1)*(m-1);
  ans2 *= -1;
  cout << max(ans1, ans2) << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}