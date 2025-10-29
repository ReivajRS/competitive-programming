#include <bits/stdc++.h>
using namespace std;

constexpr int LOG = 20;
struct XORBasis {
  int basis[LOG] = {0};
  void insert(int x) {
    for (int i = LOG - 1; i >= 0; i--) {
      if (!(x >> i & 1)) {
        continue;
      }
      if (basis[i] == 0) {
        basis[i] = x;
        return;
      }
      x ^= basis[i];
    }
  }
  int get_max() {
    int mx = 0;
    for (int i = LOG - 1; i >= 0; i--) {
      if ((mx ^ basis[i]) > mx) {
        mx ^= basis[i];
      }
    }
    return mx;
  }
};

XORBasis merge(XORBasis& xb1, XORBasis& xb2) {
  XORBasis xb = xb1;
  for (int i = 0; i < LOG; i++) {
    xb.insert(xb2.basis[i]);
  }
  return xb;
}

struct Querie {
  int l, r, idx;
};

void divide(int l, int r, vector<Querie>& queries, vector<int>& c, vector<int>& ans) {
  if (l + 1 == r) {
    for (auto& querie : queries) {
      ans[querie.idx] = c[l];
    }
    return;
  }
  vector<Querie> l_queries, r_queries, m_queries;
  int m = (l + r) / 2;
  for (auto& querie : queries) {
    if (querie.r <= m) {
      l_queries.push_back(querie);
    }
    else if (querie.l >= m) {
      r_queries.push_back(querie);
    }
    else {
      m_queries.push_back(querie);
    }
  }
  vector<XORBasis> r_xb(1);
  for (int ri = m; ri < r; ri++) {
    r_xb.back().insert(c[ri]);
    r_xb.push_back(r_xb.back());
  }
  XORBasis l_xb;
  int qi = int(m_queries.size()) - 1;
  for (int li = m - 1; li >= l; li--) {
    l_xb.insert(c[li]);
    while (qi >= 0 && m_queries[qi].l == li) {
      int ri = m_queries[qi].r - m - 1;
      ans[m_queries[qi].idx] = merge(l_xb, r_xb[ri]).get_max();
      qi--;
    }
  }
  divide(l, m, l_queries, c, ans);
  divide(m, r, r_queries, c, ans);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  int q;
  cin >> q;

  vector<Querie> queries(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    queries[i] = {l - 1, r, i};
  }

  sort(queries.begin(), queries.end(), [&](Querie q1, Querie q2) -> bool {
    return tie(q1.l, q1.r, q1.idx) < tie(q2.l, q2.r, q2.idx);
  });

  vector<int> ans(q);

  divide(0, n, queries, c, ans);

  for (auto& x : ans) {
    cout << x << '\n';
  }
  
  return 0;
}