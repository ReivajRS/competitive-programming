#include <bits/stdc++.h>
using namespace std;

struct FT {
  vector<int> s;
  FT(int n) : s(n) {}
  void update(int pos, int dif) {
    for (; pos < int(s.size()); pos |= pos + 1) s[pos] += dif;
  }
  int query(int pos) {
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> pos;
  vector<pair<int, int>> ranges;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    pos.push_back(x);
    pos.push_back(y);
    ranges.push_back({x, y});
  }

  sort(pos.begin(), pos.end());
  pos.erase(unique(pos.begin(), pos.end()), pos.end());

  auto lb = [&](int x) -> int {
    return int(lower_bound(pos.begin(), pos.end(), x) - pos.begin());
  };

  auto get_contains = [&]() -> vector<int> {
    vector<tuple<int, int, int>> events;
    for (int i = 0; i < n; i++) {
      auto [x, y] = ranges[i];
      events.push_back({lb(y), -lb(x), i});
    }

    sort(events.begin(), events.end());

    FT ft(int(pos.size()) + 1);
    vector<int> contains(n);

    for (auto [id_y, id_x, id] : events) {
      contains[id] = ft.query(id_y + 1) - ft.query(-id_x);
      ft.update(-id_x, 1);
    }

    return contains;
  };

  auto get_contained = [&]() -> vector<int> {
    vector<tuple<int, int, int, int>> events;
    for (int i = 0; i < n; i++) {
      auto [x, y] = ranges[i];
      events.push_back({lb(x), 1, lb(x), i});
      events.push_back({lb(y), 0, -lb(x), i});
    }

    sort(events.begin(), events.end()); 

    FT ft(int(pos.size()) + 1);

    vector<int> contained(n);

    for (auto [idx1, op, idx2, id] : events) {
      if (op == 1) {
        ft.update(idx1, 1);
      }
      else {
        ft.update(-idx2, -1);
        contained[id] = ft.query(-idx2 + 1);
      }
    }

    return contained;
  };

  auto contains = get_contains();
  auto contained = get_contained();

  for (int i = 0; i < n; i++) {
    cout << (contains[i] > 0) << ' ';
  }
  cout << '\n';

  for (int i = 0; i < n; i++) {
    cout << (contained[i] > 0) << ' ';
  }
  cout << '\n';

}