#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 4e4;
vector<pair<int, int>> g[maxn];
int ls[maxn], rs[maxn];

struct STree {
  int n, root1, root2;
  int build1(int& idx, int tl, int tr) {
    if (tl + 1 == tr) {
      return tl;
    }
    int tm = (tl + tr) / 2;
    int curr_idx = idx++;
    int tl_idx = build1(idx, tl, tm);
    int tr_idx = build1(idx, tm, tr);
    g[curr_idx].push_back({tl_idx, 0});
    g[curr_idx].push_back({tr_idx, 0});
    ls[curr_idx] = tl_idx;
    rs[curr_idx] = tr_idx;
    return curr_idx;
  }
  int build2(int& idx, int tl, int tr) {
    if (tl + 1 == tr) {
      return tl;
    }
    int tm = (tl + tr) / 2;
    int curr_idx = idx++;
    int tl_idx = build2(idx, tl, tm);
    int tr_idx = build2(idx, tm, tr);
    g[tl_idx].push_back({curr_idx, 0});
    g[tr_idx].push_back({curr_idx, 0});
    ls[curr_idx] = tl_idx;
    rs[curr_idx] = tr_idx;
    return curr_idx;
  }
  void get_range_idxs(int idx, int tl, int tr, int l, int r, vector<int>& idxs) {
    if (tr <= l || r <= tl) {
      return;
    }
    if (l <= tl && tr <= r) {
      idxs.push_back(idx);
      return;
    }
    int tm = (tl + tr) / 2;
    get_range_idxs(ls[idx], tl, tm, l, r, idxs);
    get_range_idxs(rs[idx], tm, tr, l, r, idxs);
  }
  void insert(int a, int b, int c, int d, int w) {
    vector<int> idxs1, idxs2;
    get_range_idxs(root2, 0, n, a, b, idxs2);
    get_range_idxs(root1, 0, n, c, d, idxs1);
    for (auto i : idxs2) {
      for (auto j : idxs1) {
        g[i].push_back({j, w});
      }
    }
    idxs1.clear();
    idxs2.clear();
    get_range_idxs(root2, 0, n, c, d, idxs2);
    get_range_idxs(root1, 0, n, a, b, idxs1);
    for (auto i : idxs2) {
      for (auto j : idxs1) {
        g[i].push_back({j, w});
      }
    }
  }
  STree(int n) : n(n) {
    int idx = n;
    root1 = idx;
    build1(idx, 0, n);
    root2 = idx;
    build2(idx, 0, n);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);



  return 0;
}