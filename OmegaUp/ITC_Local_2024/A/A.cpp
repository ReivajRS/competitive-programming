#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll k, n;
  cin >> k >> n;

  cout << (n + k - 1) / k << '\n';

  return 0;
}