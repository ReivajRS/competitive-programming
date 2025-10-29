#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  ll px, py;
  cin >> n >> m >> px >> py;

  vector<pair<ll, ll>> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }

  map<ll, int> idx, idy;
  sort(a.begin(), a.end());
  for (auto &[x, y] : a) {
    if (!idx.count(x)) {
      idx[x] = SZ(idx);
    }
  }
  sort(a.begin(), a.end(), [&](const pair<ll, ll>& i, const pair<ll, ll>& j) -> bool {
    return i.second < j.second;
  });
  for (auto &[x, y] : a) {
    if (!idy.count(y)) {
      idy[y] = SZ(idy);
    }
  }

  vector<set<pair<ll, ll>>> hx(SZ(idx)), hy(SZ(idy));
  for (auto &[x, y] : a) {
    hx[idx[x]].insert({y, x});
    hy[idy[y]].insert({x, y});
  }

  auto make_move = [](ll delta, ll& p1, ll& p2, map<ll, int>& id1, map<ll, int>& id2, vector<set<pair<ll, ll>>>& h1, vector<set<pair<ll, ll>>>& h2) -> int {
    if (!id1.count(p1) || h1[id1[p1]].empty()) {
      p2 += delta;
      return 0;
    }
    int ans = 0;
    ll sp = p2, ep = p2 + delta;
    if (delta < 0) {
      swap(sp, ep);
    }
    int id = id1[p1];
    auto it = h1[id].lower_bound({sp, p1});
    while (it != h1[id].end() && it->first <= ep) {
      ans++;
      auto [it2, it1] = *it;
      auto nit = next(it);
      h2[id2[it2]].erase({it1, it2});
      h1[id].erase(it);
      it = nit;
    }
    p2 += delta;
    return ans;
  };

  int ans = 0;

  while (m--) {
    char dir;
    ll delta;
    cin >> dir >> delta;
    
    if (dir == 'U') {
      ans += make_move(delta, px, py, idx, idy, hx, hy);
    }
    else if (dir == 'D') {
      ans += make_move(-delta, px, py, idx, idy, hx, hy);
    }
    else if (dir == 'L') {
      ans += make_move(-delta, py, px, idy, idx, hy, hx);
    }
    else {
      ans += make_move(delta, py, px, idy, idx, hy, hx);
    }
  }

  cout << px << ' ' << py << ' ' << ans << '\n';

  return 0;
}