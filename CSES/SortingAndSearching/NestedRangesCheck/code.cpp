#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  set<tuple<int, int, int>> st;
  vector<pair<int, int>> ranges(n);
  for (int i = 0; i < n; i++) {
    cin >> ranges[i].first >> ranges[i].second;
    st.insert({ranges[i].first, ranges[i].second, i});
  }

  vector<bool> contain(n), contained(n);
  for (int i = 0; i < n; i++) {
    auto it = st.upper_bound({ranges[i].first, ranges[i].second, i});
    auto [l, r] = ranges[i];
    auto [l2, r2, j] = *it;
    if (l <= l2 && r2 <= r) {
      contain[i] = true;
      contained[j] = true;
    }
  }
}