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

  vector<pi> pts(nt), reads(ns);
  FOR (i, 0, nt) {
    cin >> pts[i].first >> pts[i].second;
  }

  FOR (i, 0, ns) {
    cin >> reads[i].first >> reads[i].second;
  }

  map<int, int> dif;
  FOR (i, -100000, 100001) {
    dif[i] = rmax - abs(i);
  }

  // for (int i = -3; i <= 3; i++)
  //   cout << dif[i] << ENDL;

  int pt_idx = 0;
  set<pi> active_pts;
  set<pi> outs;

  /*
    dir
    0: right
    1: left
    2: up
    3: down
  */

  auto update = [&](int x, int y, int dir) -> void {
    if (dir == 0 || dir == 1) {
      // cerr << "hola" << ENDL;
      auto it = outs.lower_bound({x, 0});
      while (it != outs.end() && it->first == x) {
        // cout << it->first << ' ' << pts[it->second].first << ' ' << pts[it->second].second << ENDL;
        // cerr << "borro" << ENDL;
        active_pts.erase(pts[it->second]);
        outs.erase(it);
        it = outs.lower_bound({x, 0});
      }

      while (pt_idx < nt && x == pts[pt_idx].first) {
        int lx = x - dif[y], rx = x + dif[y];
        if (x < lx || x > rx) {
          pt_idx++;
          return;
        }
        int out_x;
        if (dir == 0)
          out_x = x + (x - lx) + 1;
        else
          out_x = x - (rx - x) - 1;
        active_pts.insert(pts[pt_idx]);
        // cout << "meto " << pts[pt_idx].first << ' ' << pts[pt_idx].second << " en " << x << ENDL;
        outs.insert({out_x, pt_idx});
        pt_idx++;  
      }
    }
    if (dir == 2 || dir == 3) {
      auto it = outs.lower_bound({y, 0});
      while (it != outs.end() && it->first == y) {
        active_pts.erase(pts[it->second]);
        outs.erase(it);
        it = outs.lower_bound({y, 0});
      }

      while (pt_idx < nt && y == pts[pt_idx].second) {
        int ly = y - dif[x], uy = y + dif[x];
        if (y < ly || y > uy) {
          pt_idx++;
          continue;
        }
        int out_y;
        if (dir == 2)
          out_y = y + (y - ly) + 1;
        else
          out_y = y - (uy - y) - 1;
        active_pts.insert(pts[pt_idx]);
        // cout << "meto " << pts[pt_idx].first << ' ' << pts[pt_idx].second << " en " << y << ENDL;
        outs.insert({out_y, pt_idx});
        pt_idx++;
      }
    }
  };

  auto check = [&](int x, int y, int dir) -> bool {
    FOR (i, 0, ns) {
      int difx, dify;
      if (dir == 0)
        difx = reads[i].second, dify = -reads[i].first;
      else if (dir == 1)
        difx = -reads[i].second, dify = reads[i].first;
      else if (dir == 2)
        difx = reads[i].first, dify = reads[i].second;
      else
        difx = -reads[i].first, dify = -reads[i].second;
      // cout << x + difx << ' ' << y + dify << ENDL;
      if (!active_pts.count({x + difx, y + dify}))
        return false;
    }
    return true;
  };

  set<pi> matches;

  // moving right
  pt_idx = 0;
  sort(ALL(pts), [&](pi a, pi b) { return a.first < b.first; });
  for (int x = -100000 - 1000; x <= 100000 + 1000; x++) {
    update(x, 0, 0);
    FOR (dir, 0, 4) {
      if (check(x - rmax, 0, dir)) {
        if (matches.count({x - rmax, 0})) {
          cout << "Ambiguous" << ENDL;
          return 0;
        }
        matches.insert({x - rmax, 0});
      }
    }
  }

  // moving left
  active_pts.clear();
  outs.clear();
  pt_idx = 0;
  sort(ALL(pts), [&](pi a, pi b) { return a.first > b.first; });
  for (int x = 100000 + 1000; x >= -100000 - 1000; x--) {
    update(x, 0, 1);
    FOR (dir, 0, 4) {
      if (check(x + rmax, 0, 1)) {
        if (matches.count({x + rmax, 0})) {
          cout << "Ambiguous" << ENDL;
          return 0;
        }
        matches.insert({x + rmax, 0});
      }
    }
  }

  // moving up
  active_pts.clear();
  outs.clear();
  pt_idx = 0;
  sort(ALL(pts), [&](pi a, pi b) { return a.second < b.second; });
  for (int y = -100000 - 1000; y <= 100000 + 1000; y++) {
    update(0, y, 2);
    FOR (dir, 0, 4) {
      if (check(0, y - rmax, dir)) {
        if (matches.count({0, y - rmax})) {
          cout << "Ambiguous" << ENDL;
          return 0;
        }
        matches.insert({0, y - rmax});
      }
    }
  }

  // moving down
  active_pts.clear();
  outs.clear();
  pt_idx = 0;
  sort(ALL(pts), [&](pi a, pi b) { return a.second > b.second; });
  for (int y = 100000 + 1000; y >= -100000 - 1000; y--) {
    update(0, y, 3);
    FOR (dir, 0, 4) {
      if (check(0, y + rmax, 3)) {
        if (matches.count({0, y + rmax})) {
          cout << "Ambiguous" << ENDL;
          return 0;
        }
        matches.insert({0, y + rmax});
      }
    }
  }

  if (SZ(matches) == 1)
    cout << matches.begin()->first << ' ' << matches.begin()->second << ENDL;
  else
    cout << "Impossible" << ENDL;

  return 0;
}