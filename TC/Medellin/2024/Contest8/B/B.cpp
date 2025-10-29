#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
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
        jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
      }
    }
  }
  T query(int l, int r) {
    int dep = 31 - __builtin_clz(r - l);
    return min(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

SparseTable<int> st;

const int MAXN = 1e5 + 1;
int n, c;
ll dp[MAXN];
vi a;

ll solve(int i) {
  if (i == n) {
    return 0;
  }
  ll &ans = dp[i];
  if (ans != -1)
    return ans;
  ans = solve(i + 1);
  if (i + c <= n) {
    ans = max(ans, st.query(i, i + c) + solve(i + c));
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> c;

  a.resize(n);

  ll sum = 0;

  FOR (i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }

  st.init(a);

  memset(dp, -1, sizeof dp);

  cout << sum - solve(0) << ENDL;

  return 0;
}