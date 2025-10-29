#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  string s;
  cin >> s;

  int n = (int)s.size();

  unordered_map<char, char> compCierre;
  compCierre['a'] = 'e';
  compCierre['i'] = 'o';

  unordered_map<char, char> compApertura;
  compApertura['e'] = 'a';
  compApertura['o'] = 'i';

  stack<char> st;
  vector<pair<char, int>> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = {st.empty() ? 0 : compCierre[st.top()], (int)st.size()};
    if (s[i] == 'a' || s[i] == 'i') {
      st.push(s[i]);
    } else {
      if (st.empty() || st.top() != compApertura[s[i]]) {
        cout << "INVALID\n";
        return;
      }
      st.pop();
    }
  }

  if (!st.empty()) {
    cout << "INVALID\n";
    return;
  }

  vector<char> ord = {'a', 'e', 'i', 'o'};
  pair<int, char> cambio = {-1, 0}; 
  for (int i = n - 1; i >= 0; --i) {
    for (char c : ord) {
      if (c <= s[i]) {
        continue;
      }
      if (c == 'i') {
        if (n - i - 1 < v[i].second + 1) {
          continue;
        }
      } else {
        if (c != v[i].first) {
          continue;
        }
      }
      cambio = {i, c};
      break;
    }
    if (cambio.first != -1) {
      break;
    }
  }
  
  auto [x, nw] = cambio;
  
  if (x == -1) {
    cout << "ULTIMATE\n";
    return;
  }
  
  s = s.substr(0, x) + nw;
  
  for (char c : s) {
    if (c == 'a' || c == 'i') {
      st.push(c);
    } else {
      st.pop();
    }
  }

  while ((int)s.size() + (int)st.size() < n) {
    s += "ae";
  }

  while (!st.empty()) {
    s += compCierre[st.top()];
    st.pop();
  }

  cout << s << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
