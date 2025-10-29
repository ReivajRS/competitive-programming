#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  
  string s, t;
  cin >> s >> t;

  map<char, int> cnt;
  for (char c : s) {
    cnt[c]++;
  }
  
  bool has_b = cnt['b'] > 0;
  
  for (char c : t) {
    cnt[c]--;
  }

  if (cnt['a'] != 0 || cnt['b'] != 0 || cnt['c'] != 0) {
    cout << "NO" << '\n';
    return;
  }

  if (!has_b && s != t) {
    cout << "NO" << '\n';
    return;
  }

  map<char, vector<int>> pos_s, pos_t;

  for (int i = 0; i < n; i++) {
    pos_s[s[i]].push_back(i);
    pos_t[t[i]].push_back(i);
  }

  for (int i = 0; i < int(pos_s['a'].size()); i++) {
    if (pos_s['a'][i] > pos_t['a'][i]) {
      cout << "NO" << '\n';
      return;
    }
  }

  for (int i = 0; i < int(pos_s['c'].size()); i++) {
    if (pos_s['c'][i] < pos_t['c'][i]) {
      cout << "NO" << '\n';
      return;
    }
  }

  string s2 = "", t2 = "";
  for (int i = 0; i < n; i++) {
    if (s[i] != 'b') {
      s2 += s[i];
    }
    if (t[i] != 'b') {
      t2 += t[i];
    }
  }

  cout << (s2 == t2 ? "YES" : "NO") << '\n';

  /*
    Las a solo se pueden mover a la derecha
    Las b se pueden mover a la izquierda o derecha
    Las c solo se pueden mover a la izquierda

    entre las a que se tienen que mover y las b, no tiene que haber c
    entre las c que se tienen que mover y las b, no tiene que haber a
  */
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