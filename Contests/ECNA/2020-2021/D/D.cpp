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

int r, s, n;
int a[51], b[51], c[101];
int psA[101], psB[101];
bool can[2000001];
int dp[101][51][51];

int solve(int ic, int ia, int ib) {
  if (ic == n)
    return 1;
  int &ans = dp[ic][ia][ib];
  if (ans != -1)
    return ans;
  ans = 0;
  FOR (i, 0, r + 1) {
    int iia = ia + i;
    FOR (j, 0, s + 1) {
      int iib = ib + j;
      int cap = c[ic] - (psA[iia] - psA[ia]) - (psB[iib] - psB[ib]);
      if (cap >= 0 && can[cap])
        ans |= solve(ic + 1, iia >= r ? iia - r : iia, iib >= s ? iib - s : iib);
    }
  }
  return ans;
}

signed main() { __
  cin >> r >> s >> n;
  
  FOR (i, 0, r) {
    cin >> a[i];
  }
  FOR (i, 0, s) {
    cin >> b[i];
  }
  FOR (i, 0, n) {
    cin >> c[i];
  }

  FOR (i, 0, r * 2) {
    psA[i + 1] = psA[i] + a[i % r];
  }
  FOR (i, 0, s * 2) {
    psB[i + 1] = psB[i] + b[i % s];
  }

  can[0] = 1;
  FOR (i, 0, 2000001) {
    if (i - psA[r] >= 0)
      can[i] |= can[i - psA[r]];
    if (i - psB[s] >= 0)
      can[i] |= can[i - psB[s]];
  }

  memset(dp, -1, sizeof dp);

  cout << (solve(0, 0, 0) ? "yes" : "no") << ENDL;

  return 0;
}