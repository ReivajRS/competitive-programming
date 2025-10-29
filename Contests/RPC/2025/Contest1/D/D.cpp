#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct SparseTable {
  vector<vector<int>> jmp;
  SparseTable(const vector<int>& V) {
    jmp.emplace_back(V);
    for (int pw = 1, k = 1; pw * 2 <= int(V.size()); pw *= 2, ++k) {
      jmp.emplace_back(int(V.size()) - pw * 2 + 1);
      for (int j = 0; j < int(jmp[k].size()); ++j) {
        jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
      }
    }
  }
  int query(int l, int r) {
    assert(l < r);
    int dep = 31 - __builtin_clz(r - l);
    return max(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> vals;
  vals.push_back(0);

  vector<pair<int, int>> tables(n), waiters(m);
  for (auto &[l, r] : tables) {
    cin >> l >> r;
    vals.push_back(l), vals.push_back(r), vals.push_back(r + 1);
  }
  for (auto &[l, r] : waiters) {
    cin >> l >> r;
    vals.push_back(l), vals.push_back(r), vals.push_back(r + 1);
  }

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  auto get = [&](int x) -> int {
    return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
  };

  int N = int(vals.size());

  vector<int> pt(N), pw(N);
  for (auto& [l, r] : tables) {
    l = get(l), r = get(r);
    ++pt[l], --pt[r + 1];
  }
  for (auto& [l, r] : waiters) {
    l = get(l), r = get(r);
    ++pw[l], --pw[r + 1];
  }

  vector<int> need(N);
  for (int i = 1; i < N; ++i) {
    pt[i] += pt[i - 1];
    pw[i] += pw[i - 1];
    if (pw[i]) {
      need[i] = (pt[i] + pw[i] - 1) / pw[i];
    }
  }

  bool b = false;
  SparseTable st(need);
  for (auto [l, r] : waiters) {
    if (b) {
      cout << " ";
    }
    cout << st.query(l, r + 1);
    b = true;
  }
  cout << '\n';

  return 0;
}