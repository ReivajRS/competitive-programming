#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int n, c[256], value[256];
vector<char> oc;
ll dp[105][20];

ll solve(int i, int res) {
  if (res == 0)
    return 2;
  if (res < 0 || i == n) return 0;
  ll &ans = dp[i][res];
  if (ans != -1) return ans;
  return ans = solve(i + 1, res - value[oc[i]]) + solve(i + 1, res);
}

signed main() { __
  memset(dp, -1, sizeof dp);

  cin >> n;

  oc = vector<char>(n);
  for (auto &ch : oc) {
    cin >> ch;
    c[ch]++;
  }

  FOR (i, 2, 10) 
    value['0' + i] = i;
  value['A'] = 1;
  value['T'] = value['J'] = value['Q'] = value['K'] = 10;

  
  ll ans = solve(0, 15);

  FOR (i, 0, n)
    FOR (j, i + 1, n)
      if (oc[i] == oc[j])
        ans += 2;

  vector<char> cards;
  cards.pb('A');
  FOR (i, 2, 10) 
    cards.pb(char('0' + i));
  cards.pb('T'), cards.pb('J'), cards.pb('Q'), cards.pb('K'), cards.pb('#');
  ll cnt = 0, escaleras = 0;
  for (auto &ch : cards) {
    if (c[ch] == 0) {
      if (cnt >= 3)
        ans += cnt * escaleras;
      escaleras = 0;
      cnt = 0;
      continue;
    }
    if (cnt == 0) {
      escaleras = c[ch];
      cnt = 1;
      continue;
    }
    cnt++;
    escaleras *= 1ll * c[ch];
  }

  cout << ans << ENDL;

  return 0;
}