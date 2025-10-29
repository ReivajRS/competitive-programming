#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<pair<int, int>> pts(5);

  for (auto &[x, y] : pts) {
    cin >> x >> y;
  }

  auto remove_duplicates = [&pts]() -> void {
    set<pair<int, int>> st;
    for (auto &x : pts) {
      st.insert(x);
    }
    pts.clear();
    for (auto &x : st) {
      pts.push_back(x);
    }
  };

  int ans = 0;

  while (1) {
    bool flag = 0;
    while (1) {
      sort(pts.begin(), pts.end(), [&](const pair<int, int> &i, const pair<int, int> &j) -> bool {
        return i.first > j.first;
      });
      int sz = SZ(pts);
      if (sz > 1 && pts[sz - 1].first != pts[sz - 2].first) {
        int dx = pts[sz - 2].first - pts[sz - 1].first;
        cout << 1 << ' ' << dx << '\n';
        ans += dx;
        int y = pts[sz - 1].second;
        pts.pop_back();
        pts.push_back({pts.back().first, y});
        remove_duplicates();
        flag = 1;
        continue;
      }
      break;
    }

    while (1) {
      sort(pts.begin(), pts.end(), [&](const pair<int, int> &i, const pair<int, int> &j) -> bool {
        return i.first < j.first;
      });
      int sz = SZ(pts);
      if (sz > 1 && pts[sz - 1].first != pts[sz - 2].first) {
        int dx = pts[sz - 1].first - pts[sz - 2].first;
        cout << 2 << ' ' << dx << '\n';
        ans += dx;
        int y = pts[sz - 1].second;
        pts.pop_back();
        pts.push_back({pts.back().first, y});
        remove_duplicates();
        flag = 1;
        continue;
      }
      break;
    }

    while (1) {
      sort(pts.begin(), pts.end(), [&](const pair<int, int> &i, const pair<int, int> &j) -> bool {
        return i.second > j.second;
      });
      int sz = SZ(pts);
      if (sz > 1 && pts[sz - 1].second != pts[sz - 2].second) {
        int dy = pts[sz - 2].second - pts[sz - 1].second;
        cout << 3 << ' ' << dy << '\n';
        ans += dy;
        int x = pts[sz - 1].first;
        pts.pop_back();
        pts.push_back({x, pts.back().second});
        remove_duplicates();
        flag = 1;
        continue;
      }
      break;
    }

    while (1) {
      sort(pts.begin(), pts.end(), [&](const pair<int, int> &i, const pair<int, int> &j) -> bool {
        return i.second < j.second;
      });
      int sz = SZ(pts);
      if (sz > 1 && pts[sz - 1].second != pts[sz - 2].second) {
        int dy = pts[sz - 1].second - pts[sz - 2].second;
        cout << 4 << ' ' << dy << '\n';
        ans += dy;
        int x = pts[sz - 1].first;
        pts.pop_back();
        pts.push_back({x, pts.back().second});
        remove_duplicates();
        flag = 1;
        continue;
      }
      break;
    }
    if (!flag) {
      break;
    }
  }

  sort(pts.begin(), pts.end(), [&](const pair<int, int> &i, const pair<int, int> &j) -> bool {
    return i.first < j.first;
  });
  int dx = pts.back().first - pts[0].first;
  // bool difx = pts[0].first != pts.back().first;
  sort(pts.begin(), pts.end(), [&](const pair<int, int> &i, const pair<int, int> &j) -> bool {
    return i.second < j.second;
  });
  int dy = pts.back().second - pts[0].second;
  // bool dify = pts[0].second != pts.back().second;

  // ans += dx + dx * dify;
  // ans += dy + dy * difx;
  ans += dx * 2;
  ans += dy * 2;

  if (SZ(pts) == 5) {
    for (int i = 0; i < 5; i++) {
      bool has_left, has_right, has_up, has_down;
      has_left = has_right = has_up = has_down = 0;
      for (int j = 0; j < SZ(pts); j++) {
        if (pts[j].first < pts[i].first) {
          has_left = 1;
        }
        if (pts[j].first > pts[i].first) {
          has_right = 1;
        }
        if (pts[j].second < pts[i].second) {
          has_up = 1;
        }
        if (pts[j].second > pts[i].second) {
          has_down = 1;
        }
      }
      if (has_left && has_right && has_up && has_down) {
        ans += min(dx, dy);
        break;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}