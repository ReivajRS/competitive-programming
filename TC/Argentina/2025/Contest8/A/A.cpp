#include <bits/stdc++.h>
using namespace std;

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr
  #define NEUT 0

  int n;
  vector<int> st;

  STree(int n) : n(n), st(4 * n) {}

  void upd(int v, int tl, int tr, int i, int val) {
    if (tl + 1 == tr) {
      st[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (i < tm) upd(lp, i, val);
    else upd(rp, i, val);
    st[v] = gcd(st[ls], st[rs]);
  }

  void upd(int i, int val) {
    upd(0, 0, n, i, val);
  }
};

void solve(vector<int>& divs) {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  STree st(n);

  auto check = [&](int i, bool add = true) {
    if (0 <= i && i < n - 1 && a[i] > a[i + 1]) {
      st.upd(i, add ? i + 1 : 0);
    }
  };

  for (int i = 0; i < n - 1; ++i) {
    check(i);
  }

  auto print = [&]() {
    int g = st.st[0];
    cout << (!g ? n : divs[g]) << '\n';
  };
  print();

  while (q--) {
    int p, v;
    cin >> p >> v;
    --p;

    check(p - 1, false), check(p, false);
    a[p] = v;
    check(p - 1), check(p);

    print();
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  constexpr int N = int(2e5) + 5;
  vector<int> divs(N);
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      ++divs[j];
    }
  }

  int t;
  cin >> t;

  while (t--) {
    solve(divs);
  }
  
  return 0;
}