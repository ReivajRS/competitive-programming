#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  vector<int> cnt(26);
  for (char c : s) {
    cnt[c - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 1) {
      cout << char(i + 'a') << '\n';
      return 0;
    }
  }

  cout << 'a' << '\n';
}