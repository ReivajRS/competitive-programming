#include<bits/stdc++.h>
using namespace std;

struct BIT {
  int n;
  vector<int> bit;
  BIT(int _n) : n(_n + 1), bit(n) {}
  void add(int i, int x) {
    while (i <= n) {
      bit[i] += x;
      i += i&-i;
    }
  }
  int query(int i) {
    int s = 0;
    while (i >= 1) {
      s += bit[i];
      i -= i&-i;
    }
    return s;
  }
};

BIT bit(100001);

vector<int> z_function(const string& s) {
  int n = (int)s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    bit.add(1, 1);
    bit.add(z[i] + 1, -1);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
      bit.add(z[i], 1);
      bit.add(z[i] + 1, -1);
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  vector<int> z = z_function(s);
  int n = (int)s.size();
  vector<pair<int, int>> ans;
  for (int i = n - 1; i >= 1; i--) {
    if (i + z[i] == n) {
      ans.push_back({z[i], bit.query(z[i]) + 1});
    }
  }
  ans.push_back({n, 1});
  cout << (int)ans.size() << '\n';
  for (auto &[x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
