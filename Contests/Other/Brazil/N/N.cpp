#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct FT {
  vector<int> s;
  FT(int n) : s(n) {}
  void update(int pos, int dif) {
    for (; pos < int(s.size()); pos |= pos + 1) s[pos] += dif;
  }
  int query(int pos) {
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
};

constexpr int N = int(1e5) + 5;

vector<int> upd[N];
vector<tuple<int, int, int>> qry[N];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int y, n;
  cin >> y >> n;

  vector<int> x(y);
  for (int i = 0; i < y; ++i) {
    cin >> x[i];
    upd[x[i]].push_back(i);
  }

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int a, p, f;
    cin >> a >> p >> f;
    --a;
    if (p > x[a] && f) {
      qry[p].emplace_back(a + 1, a + f, i);
    }
  }

  FT ft(y);
  for (int i = N - 1; i >= 0; --i) {
    for (int pos : upd[i]) {
      ft.update(pos, 1);
    }
    for (auto [l, r, pos] : qry[i]) {
      ans[pos] = ft.query(r + 1) - ft.query(l);
    }
  }

  for (int x : ans) {
    cout << x << '\n';
  }

  return 0;
}