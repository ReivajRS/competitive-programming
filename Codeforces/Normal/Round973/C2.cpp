#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  int ans;
  auto ask = [&](string s) -> void {
    cout << "? " << s << endl;
    cin >> ans;
  };

  ask("0");
  string s = ans ? "0" : "1";
  bool dir = 1;

  // 100
  // 101
  // 010
  // 110

  // 0000

  auto try_char = [&](char c) -> bool {
    string s2 = s;
    if (dir) {
      s2.push_back(c);
    }
    else {
      s2.insert(s2.begin(), c);
    }
    ask(s2);
    if (ans) {
      s = s2;
    }
    return ans;
  };

  while (int(s.size()) < n) {
    if (dir) {
      if (try_char('0')) {
        continue;
      }
      if (try_char('1')) {
        continue;
      }
      dir = !dir;
    }
    else {
      if (try_char('1')) {
        continue;
      }
      if (try_char('0')) {
        continue;
      }
    }
  }

  cout << "! " << s << endl;
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