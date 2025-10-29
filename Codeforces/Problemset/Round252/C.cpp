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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int tub[301][301];
int n, m, k;
int v = 1, cnt = 0;
vector<vector<pi>> tubes;

void dfs(int x, int y) {
  if (cnt == 2 && v != k) {
    v++;
    cnt = 0;
    tubes.pb(vector<pi>());
  }
  tub[x][y] = v;
  cnt++;
  tubes.back().pb({x, y});
  FOR (i, 0, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || tub[nx][ny] != -1) {
      continue;
    }
    dfs(nx, ny);
  }
}

signed main() { __
  cin >> n >> m >> k;

  memset(tub, -1, sizeof tub);

  tubes.pb(vector<pi>());

  dfs(0, 0);

  for (auto &x : tubes) {
    cout << SZ(x);
    for (auto &y : x) {
      cout << ' ' << y.first + 1 << ' ' << y.second + 1;
    }
    cout << ENDL;
  }

  return 0;
}