#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  if (s == "0e") {
    cout << 1 << '\n';
    return 0;
  }

  int target_pos = s.back() - 'a';
  s.pop_back();

  int target_cnt = stoi(s);
  int cnt = 0, pos = 4, steps = 3, ans = 1;

  while (true) {
    ans++;
    int inc = steps;
    cnt += inc / 26;
    inc %= 26;
    if ((pos + inc) % 26 < pos) {
      cnt++;
    }
    pos = (pos + inc) % 26;
    if (cnt == target_cnt && pos == target_pos) {
      break;
    }
    if (cnt > target_cnt) {
      cout << -1 << '\n';
      return 0;
    }
    steps += 2;
  }

  cout << ans << '\n';
}