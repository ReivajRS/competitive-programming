#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  string s;
  cin >> s;

  int n = SZ(s);
  int fb = 0;
  for (; fb < n; fb++) {
    if (s[fb] == '0') break;
  }

  if (fb == n) {
    cout << 1 << ' ' << n << ' ' << 1 << ' ' << 1 << '\n';
    return;
  }

  list<char> bits;
  for (int i = 0; i < n - fb; i++) {
    bits.push_back(s[i]);
  }

  string mx;
  pair<int, int> pos;

  {
    string bit = "";
    int j = fb;
    for (auto &x : bits) {
      if (s[j] == x) bit += '0';
      else bit += '1';
      j++;
    }
    mx = bit;
    pos = {1, SZ(bits)};
  }

  int idx = 2;
  for (int i = n - fb; i < n; i++) {
    bits.pop_front();
    bits.push_back(s[i]);
    string bit = "";
    int j = fb;
    for (auto &x : bits) {
      if (s[j] == x) bit += '0';
      else bit += '1';
      j++;
    }
    if (bit > mx) {
      mx = bit;
      pos = {idx, idx + SZ(bits) - 1};
    }
    idx++;
  }

  auto [x, y] = pos;
  cout << 1 << ' ' << n << ' ' << x << ' ' << y << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}