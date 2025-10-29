#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

signed main() {
  string s;
  cin >> s;
  vi a(256);
  for (auto &c:s)a[c]++;
  cout << min({a['T'], a['P'], a['A']+a['U']}) << '\n';
}