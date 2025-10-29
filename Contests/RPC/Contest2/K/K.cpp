#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  string s;
  cin >> s;
  vi cnt(3, 0);

  ll ans = 0;
  for (auto c : s) {
    cnt[c - '0']++;
    if (c == '1')
      ans += cnt[2];
    if (c == '0')
      ans += cnt[1] + cnt[2];
  }

  cout << ans << ENDL;

  return 0;
}