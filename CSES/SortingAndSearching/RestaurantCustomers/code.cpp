#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<pair<int, int>> events;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    events.emplace_back(a, 1);
    events.emplace_back(b + 1, 0);
  }

  sort(events.begin(), events.end());

  int sz = int(events.size());
  int i = 0, cnt = 0, ans = 0;
  while (i < sz) {
    int t = events[i].first;
    while (i < sz && events[i].first == t && events[i].second == 0) {
      cnt--;
      i++;
    }
    while (i < sz && events[i].first == t && events[i].second == 1) {
      cnt++;
      i++;
    }
    ans = max(ans, cnt);
  }

  cout << ans << '\n';
}