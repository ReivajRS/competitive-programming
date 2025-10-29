#include <bits/stdc++.h>
using namespace std;

bool all_equal(vector<int>& a) {
  return count(a.begin(), a.end(), a[0]) == (int)a.size();
}

bool increasing(vector<int>& a) {
  return is_sorted(a.begin(), a.end());
}

bool decreasing(vector<int>& a) {
  return is_sorted(a.rbegin(), a.rend());
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a) cin >> x;

  if (all_equal(a)) {
    cout << "Both" << '\n';
    return 0;
  }
  if (increasing(a)) {
    cout << "Ana" << '\n';
    return 0;
  }
  if (decreasing(a)) {
    cout << "Ernesto" << '\n';
    return 0;
  }

  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      a[i] = a[i + 1];
      if (increasing(a)) {
        cout << "Ana" << '\n';
        return 0;
      }
      break;
    }
  }

  cout << "Both" << '\n';

  return 0;
}