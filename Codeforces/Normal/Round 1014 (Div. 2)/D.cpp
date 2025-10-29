#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  map<char, int> c;
  for (auto &x : s) {
    c[x]++;
  }

  if (c['T'] == n || c['I'] == n || c['L'] == n) {
    cout << -1 << '\n';
    return;
  }
  if (n % 3 == 0 && c['T'] == c['I'] && c['I'] == c['L']) {
    cout << 0 << '\n';
    return;
  }

  map<char, map<char, string>> mp;
  mp['T']['I'] = mp['I']['T'] = "L";
  mp['T']['L'] = mp['L']['T'] = "I";
  mp['L']['I'] = mp['I']['L'] = "T";

  vector<int> moves;

  bool flag = 0;

  auto f = [&](char ch) -> bool {
    for (int i = 0; i < SZ(s); i++) {
      if (i > 0 && s[i - 1] != s[i]) {
        string mid = mp[s[i - 1]][s[i]];
        if (mid[0] == ch) {
          c[mid[0]]++;
          s.insert(i, mid);
          moves.push_back(i);
          return true;
        }
      }
    }
    return false;
  };

  while ((c['T'] + c['I'] + c['L']) % 3 != 0 || c['T'] != c['I'] || c['T'] != c['L'] || c['I'] != c['L']) {
    vector<pair<int, char>> cnt = {{c['T'], 'T'}, {c['I'], 'I'}, {c['L'], 'L'}};
    sort(cnt.begin(), cnt.end());
    if (!flag && cnt[1].first > cnt[0].first) {
      bool ok = f(cnt[0].second);
      if (ok) {
        continue;
      }
      ok = f(cnt[2].second);
    }
    else {
      flag = 1;
      bool ok = f(cnt[0].second);
      if (ok) {
        continue;
      }
      f(cnt[1].second);
    }
  }

  cout << SZ(moves) << '\n';
  for (auto x : moves) {
    cout << x << '\n';
  }
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