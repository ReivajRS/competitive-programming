#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string s, t;
  cin >> s >> t;
  bool h = 0, v = 0, r = 0;
  for (char c : t) {
    if (c == 'h') {
      h ^= 1;
    } else if (c == 'v') {
      v ^= 1;
    } else {
      r ^= 1;
    }
  }
  if (h) {
    reverse(s.begin(), s.end());
    for (char& c : s) {
      if (c == 'p') {
        c = 'q';
      } else if (c == 'q') {
        c = 'p';
      } else if (c == 'b') {
        c = 'd';
      } else {
        c = 'b';
      }
    }
  }
  if (v) {
    for (char& c : s) {
      if (c == 'p') {
        c = 'b';
      } else if (c == 'q') {
        c = 'd';
      } else if (c == 'b') {
        c = 'p';
      } else {
        c = 'q';
      }
    }
  }
  if (r) {
    reverse(s.begin(), s.end());
    for (char& c : s) {
      if (c == 'p') {
        c = 'd';
      } else if (c == 'q') {
        c = 'b';
      } else if (c == 'b') {
        c = 'q';
      } else {
        c = 'p';
      }
    }
  }
  cout << s << '\n';
  return 0;
}