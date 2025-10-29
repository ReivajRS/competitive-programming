#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  for (char c : s) {
    if (c == 'O' || c == 'o') {
      cout << ".-.-";
    }
    if (c == 'K' || c == 'k') {
      cout << ".-";
    }
  }
  cout << '\n';

  return 0;
}