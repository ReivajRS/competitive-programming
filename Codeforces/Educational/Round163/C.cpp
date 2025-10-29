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

pi moves[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
  int n;
  cin >> n;
  vector<string> mat(2);
  FOR (i, 0, 2)
    cin >> mat[i];
  
  queue<pi> q;
  // mov: bit 0 can choose the move, bit 1 can't choose the move
  vector<vector<bool>> tmov(2, vector<bool>(n, 0));
  vector<vector<int>> mov(2, vector<int>(n, 0));
  q.push({0, 0});
  // mov[0][0] |= (1 << 0);
  
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    // printf("(%d, %d)\n", i, j);

    if (i == 1 && j == n - 1) {
      cout << "YES" << ENDL;
      return;
    }

    if (tmov[i][j] && !(mov[i][j] & 2)) {
      int y, x;
      if (mat[i][j] == '>')
        y = i + moves[0].first, x = j + moves[0].second;
      if (mat[i][j] == '<')
        y = i + moves[2].first, x = j + moves[2].second;
      tmov[y][x] = 0;
      mov[i][j] |= 2;
      q.push({y, x});
    }


    if (!tmov[i][j] && !(mov[i][j] & 1))
    FOR (k, 0, 4) {
      int y = i + moves[k].first, x = j + moves[k].second;
      if (y < 0 || y >= 2 || x < 0 || x >= n)
        continue;
      tmov[y][x] = 1;
      mov[i][j] |= 1;
      q.push({y, x});
    }
  }

  cout << "NO" << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}