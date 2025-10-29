#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

signed main() {
  cin.tie()->sync_with_stdio(0);

  string s;
  cin >> s;

  long long total = 0;
  vector<int> last(26, -1), cnt(26, 0);
  vector<long long> ans(26, 0);
  for (int i = 0; i < SZ(s); i++) {
    int c = s[i] - 'A';
    if (last[c] != -1) {
      int dif = i - last[c];
      ans[c] += (cnt[c] * dif) + dif - 1;
      total += ans[c];
      cnt[c]++;
    }
    last[c] = i;
  }

  cout << total << '\n';

  return 0;
}