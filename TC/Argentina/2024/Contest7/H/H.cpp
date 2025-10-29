#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

template<class T>
struct SparseTable {
  vector<vector<T>> jmp;
  void init(const vector<T>& V) {
    if (SZ(jmp)) jmp.clear();
    jmp.emplace_back(V);
    for (int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
      jmp.emplace_back(SZ(V) - pw * 2 + 1);
      FOR (j, 0, SZ(jmp[k]))
        jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int l, int r) {
    int dep = 31 - __builtin_clz(r - l);
    return min(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<string> mat(n);
  FOR (i, 0, n) {
    cin >> mat[i];
  }

  vector<vi> prefc(n, vi(m, 0));
  FOR (j, 0, m) {
    int last = -1;
    ROF (i, n, 0) {
      if (mat[i][j] != last) {
        prefc[i][j] = 1;
      } else {
        prefc[i][j] += (i + 1 < n ? prefc[i + 1][j] + 1 : 1);
      }
      last = mat[i][j];
    }
  }

  vector<vi> prefh(m, vi(n, 0));
  FOR (i, 0, n) {
    int last = -1;
    ROF (j, m, 0) {
      if (mat[i][j] != last) {
        prefh[j][i] = 1;
      } else {
        prefh[j][i] += (j + 1 < m ? prefh[j + 1][i] + 1 : 1);
      }
      last = mat[i][j];
    }
  }

  vector<SparseTable<int>> st(m);
  FOR (j, 0, m) st[j].init(prefh[j]);

  ll ans = 0;
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      int h = prefc[i][j];
      if (i + 3 * h - 1 < n && prefc[i + h][j] == h && prefc[i + 2 * h][j] >= h) {
        int w = st[j].query(i, i + 3 * h);
        // cout << i << ' ' << j << ' ' << h << ' ' << w << ENDL;
        ans += w;
      }
    }
  }
  cout << ans << ENDL;

  // FOR (i, 0, n) {
  //   FOR (j, 0, m) {
  //     cout << prefc[i][j] << ' ';
  //   }
  //   cout << ENDL;
  // }
  // cout << ENDL;
  // FOR (i, 0, n) {
  //   FOR (j, 0, m) {
  //     cout << prefh[j][i] << ' ';
  //   }
  //   cout << ENDL;
  // }

  return 0;
}