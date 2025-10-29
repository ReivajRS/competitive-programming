
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
      FOR (j, 0, SZ(jmp[k])) {
        jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
      }
    }
  }
  T query(int l, int r) { // [a, b)
    int dep = 31 - __builtin_clz(r - l);
    return max(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  vector<vi> a(n, vi(n));
  FOR (i, 0, n) FOR (j, 0, n) cin >> a[i][j];

  auto bad = [&]() -> void {
    cout << "NOT MAGIC" << ENDL;
    exit(0);
  };

  FOR (i, 0, n) {
    if (a[i][i]) bad();
    FOR (j, 0, n) {
      if (a[i][j] != a[j][i]) bad();
    }
  }

  vector<vi> mx_r(n, vi(n, 0)), mx_c(n, vi(n, 0));
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      mx_r[i][j] = a[i][j];
      if (j) mx_r[i][j] = max(mx_r[i][j], mx_r[i][j - 1]);
      mx_c[j][i] = a[i][j];
      if (i) mx_c[i][j] = max(mx_c[i][j], mx_c[i - 1][j]); 
    }
  }

  FOR (i, 0, n) {
    FOR (j, 0, n) if (i != j) {
      int x = max(mx_r[i][i], mx_c[i][i]);
      if (x > a[i][j]) bad();
    }
  }

  cout << "MAGIC" << ENDL;

  return 0;
}