#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

int pot[10];

vi decode(int msk) {
  vi v(9);
  ROF (i, 9, 0) {
    while (msk - pot[i] >= 0) {
      msk -= pot[i];
      v[i]++;
    }
  }
  return v;
}

int encode(vi v) {
  int msk = 0;
  FOR (i, 0, 9) msk += pot[i] * v[i];
  return msk;
}

int winner(vi v) {
  // filas
  if (v[0] && v[0] == v[1] && v[1] == v[2]) return v[0];
  if (v[3] && v[3] == v[4] && v[4] == v[5]) return v[3];
  if (v[6] && v[6] == v[7] && v[7] == v[8]) return v[6];
  
  // columnas
  if (v[0] && v[0] == v[3] && v[3] == v[6]) return v[0];
  if (v[1] && v[1] == v[4] && v[4] == v[7]) return v[1];
  if (v[2] && v[2] == v[5] && v[5] == v[8]) return v[2];

  // diagonales
  if (v[0] && v[0] == v[4] && v[4] == v[8]) return v[0];
  if (v[2] && v[2] == v[4] && v[4] == v[6]) return v[2];

  return -1;
}

constexpr int maxn = 100000, maxi = 9;

int vis[maxn];
void f(int msk, int turn) {
  if (vis[msk]) return;
  vis[msk] = 1;
  vi v = decode(msk);
  int w = winner(v);
  if (w != -1) return; 
  FOR (i, 0, 9) if (v[i] == 0) {
    v[i] = turn + 1;
    f(encode(v), !turn);
    v[i] = 0;
  }
}

ll memo[2][2][maxn + 5];
ll dp(int p, int t, int msk) {
  vi v = decode(msk);
  int w = winner(v);
  if (w != -1) return w-1 == p;
  ll &ans = memo[p][t][msk];
  if (ans != -1) return ans;
  ans = 0;
  FOR (i, 0, 9) if (v[i] == 0) {
    v[i] = t + 1;
    ans += dp(p, !t, encode(v));
    v[i] = 0;
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  memset(memo, -1, sizeof memo);

  pot[0] = 1;
  FOR (i, 1, 10) pot[i] = pot[i-1]*3;

  f(0, 0);

  int t;
  cin >> t;
  while (t--) {
    vi v(9);
    int cnt = 0;
    FOR (i, 0, 9) {
      char c;
      cin >> c;
      if (c == '.') v[i] = 0;
      else if (c == 'X') v[i] = 1, cnt++;
      else v[i] = 2, cnt++;
    }
    int msk = encode(v);
    if (!vis[msk]) {
      cout << "-1 -1" << ENDL;
      continue;
    }
    int turn = cnt % 2;
    cout << dp(0, turn, msk) << ' ' << dp(1, turn, msk) << ENDL;
  }

  return 0;
}