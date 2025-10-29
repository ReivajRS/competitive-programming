#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m;
string s;
bool av[255];

signed main() { __
  cin >> n >> m;
  cin >> s;

  FOR (i, 0, n) {
    char c;
    cin >> c;
    av[c] = 1;
  }

  int cnt = 0;
  ll ans = 0;
  FOR (i, 0, n) {
    if (av[s[i]]) {
      cnt++;
      continue;
    }
    ans += 1ll * cnt * (cnt + 1) / 2;
    cnt = 0;
  }

  ans += 1ll * cnt * (cnt + 1) / 2;

  cout << ans << ENDL;

  return 0;
}