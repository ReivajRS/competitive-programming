#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define N 155

constexpr int INF = 1e6;

int n, all;
int letra[N], val[N], cnt[5];
int dp[N][128];

// IIEEA

int solve(int i, int mask) {
  if (i == n) {
    return mask == all ? 0 : INF; 
  }
  int &ans = dp[i][mask];
  if (~ans) {
    return ans;
  }
  ans = val[i] + solve(i + 1, mask);
  FOR (l, 0, 5) {
    if (((mask >> l) & 1) || i + cnt[l] > n) {
      continue;
    }
    int agg = 0;
    FOR (j, i, i + cnt[l]) {
      if (letra[j] != l) {
        agg += val[j];
      }
    }
    ans = min(ans, agg + solve(i + cnt[l], mask | (1 << l)));
  }
  return ans;
}

signed main() { __
  int m[256];
  m['A'] = 0;
  m['E'] = 1;
  m['I'] = 2;
  m['O'] = 3;
  m['U'] = 4;
  m['X'] = -1;

  string s;
  cin >> s;
  n = SZ(s);
  all = (1 << 5) - 1;

  FOR (i, 0, n) {;
    letra[i] = m[s[i]];
  }

  FOR (i, 0, n) {
    cin >> val[i];
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    letra[x - 1] = -1;
    val[x - 1] = 0;
  }

  FOR (i, 0, n) {
    if (letra[i] != -1) {
      cnt[letra[i]]++;
    }
  }

  cin >> s;
  for (auto &c : s) {
    cnt[m[c]]++;
  }

  memset(dp, -1, sizeof dp);

  int mask = 0;
  FOR (i, 0, 5) {
    if (cnt[i] == 0) {
      mask |= 1 << i;
    }
  }

  cout << solve(0, mask) << ENDL;

  return 0;
}