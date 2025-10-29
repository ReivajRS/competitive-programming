#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n = 1 << 20;

  cout << n << '\n';
  for (int i = 0; i < n; ++i) {
    cout << char('A' + (i % 26));
  }
  cout << '\n';
  cout << "1\n";
  cout << "A 1\n";

  return 0;
}