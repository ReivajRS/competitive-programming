#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  string s;
  ll sum = 0;
  cin >> s;
  if (s[0] == '-') {
    cout << 0 << ENDL;
    return 0;
  }
  for (char &c : s) {
    sum += c - '0';
  }
  cout << (sum > 99999 ? 0 : sum) << ENDL;
  return 0;
}