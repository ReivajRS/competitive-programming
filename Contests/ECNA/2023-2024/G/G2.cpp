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
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  int nt, ns, rmax;
  cin >> nt >> ns >> rmax;

  set<pi> trees;
  vector<pi> reads(ns);

  FOR (i, 0, nt) {
    int x, y;
    cin >> x >> y;
    trees.insert({x, y});
  }

  FOR (i, 0, ns) {
    cin >> reads[i].first >> reads[i].second;
  }

  auto dist = [](int x1, int y1, int x2, int y2) -> int {
    return abs(x1 - x2) + abs(y1 - y2);
  };

  auto check = [&](int x, int y, set<pi> &pts) -> bool {
    for (auto &t : trees) {
      if (pts.count(t))
        continue;
      if (dist(x, y, t.first, t.second) <= rmax)
        return false;
    }
    return true;
  };

  pi ans = {1e9, 1e9};

  FOR (dir, 0, 4) {
    for (auto &t : trees) {
      int x = t.first, y = t.second;
      
      int dx = reads[0].first, dy = reads[0].second;
      if (dir == 0 || dir == 1)
        swap(dx, dy);
      
      int sgnx, sgny;
      if (dir == 0)
        sgnx = 1, sgny = -1;
      else if (dir == 1)
        sgnx = -1, sgny = 1;
      else if (dir == 2)
        sgnx = 1, sgny = 1;
      else
        sgnx = -1, sgny = -1;
      
      x += dx * -sgnx;
      y += dy * -sgny;

      if (trees.count({x, y}))
        continue;
      
      set<pi> pts;
      pts.insert(t);
      
      bool flag = 1;
      FOR (i, 1, ns) {
        dx = reads[i].first, dy = reads[i].second;
        if (dir == 0 || dir == 1)
          swap(dx, dy);
        int xx = x + dx * sgnx;
        int yy = y + dy * sgny;
        if (!trees.count({xx, yy})) {
          flag = 0;
          break;
        }
        pts.insert({xx, yy});
      };
      
      if (flag && check(x, y, pts)) {
        if (ans.first != 1e9) {
          cout << "Ambiguous" << ENDL;
          return 0;
        }
        ans = {x, y};
      }
    }
  }

  if (ans.first != 1e9)
    cout << ans.first << ' ' << ans.second << ENDL;
  else
    cout << "Impossible" << ENDL;

  return 0;
}