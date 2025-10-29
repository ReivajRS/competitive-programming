#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  int n = int(s.size());

  vector<int> cnt(26);
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'A']++;
  }

  for (int c : cnt) {
    if (c > (n + 1) / 2) {
      cout << -1 << '\n';
      return 0;
    }
  }

  string ans = "";

  while (int(ans.size()) < n) {
    char last = ans.empty() ? '$' : ans.back();
    bool ok = false;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] > 0 && (last - 'A') != i) {
        int left = n - int(ans.size()) - 1;
        bool can_finish = true;
        for (int j = 0; j < 26; j++) {
          if (i != j && cnt[j] > (left + 1) / 2) {
            can_finish = false;
            break;
          }
        }
        if (!can_finish) {
          continue;
        }
        ok = true;
        cnt[i]--;
        ans += char(i + 'A');
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      return 0;
    }
  }

  cout << ans << '\n';
}