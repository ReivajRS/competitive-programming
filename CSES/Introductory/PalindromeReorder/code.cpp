#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  vector<int> cnt(26);
  
  for (char& c : s) {
    cnt[c - 'A']++;
  }

  char odd = '$';
  for (int i = 0; i < 26; i++) {
    if (cnt[i] & 1) {
      if (odd == '$') {
        odd = char('A' + i);
      }
      else {
        cout << "NO SOLUTION" << '\n';
        return 0;
      }
    }
  }

  vector<char> ans(int(s.size()));
  int l = 0, r = int(s.size()) - 1;
  for (int i = 0; i < 26; i++) {
    if (i == odd - 'A') {
      continue;
    }
    while (cnt[i] >= 2) {
      ans[l++] = ans[r--] = char('A' + i);
      cnt[i] -= 2;
    }
  }

  while (l <= r) {
    ans[l++] = ans[r--] = odd;
  }

  for (auto& c : ans) {
    cout << c;
  }
  cout << '\n';
  
  return 0;
}