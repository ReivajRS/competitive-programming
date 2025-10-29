#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

void solve() {
  string s;
  cin >> s;

  int diff = 0;
  vector<int> cnt(26);
  for (char c : s) {
    ++cnt[c - 'a'];
    diff += cnt[c - 'a'] == 1;
  }

  if (s.size() == 1) {
    cout << "YES\n";
    cout << s << '\n';
    return;
  }
  if (diff == 1) {
    cout << "NO\n";
    return;
  }
  if (diff == 2) {
    pair<int, char> mn = {1e9, 0}, mx = {0, 0};
    for (int i = 0; i < 26; ++i) {
      if (cnt[i]) {
        pair<int, char> p = {cnt[i], char('a' + i)};
        mn = min(mn, p);
        mx = max(mx, p);
      }
    }
    if (mn.first != 1) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    cout << mn.second;
    for (int i = 0; i < cnt[mx.second - 'a']; ++i) {
      cout << mx.second;
    }
    cout << '\n';
    return;
  }
  int f = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i]) {
      f = i;
      break;
    }
  }
  cout << "YES\n";
  cout << char('a' + f);
  --cnt[f];
  for (int i = f + 1; i < 26; ++i) {
    while (cnt[i]) {
      cout << char('a' + i);
      --cnt[i];
    }
  }
  while (cnt[f]) {
    cout << char('a' + f);
    --cnt[f];
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}