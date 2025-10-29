#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
  vector<int> e, p;
  DSU(int n) : e(n, -1), p(n) {
    iota(p.begin(), p.end(), 0);
  }
  int get(int x) {
    if (e[x] < 0) {
      return x;
    }
    return e[x] = get(e[x]);
  }
  int next(int x) {
    return p[get(x)];
  }
  void join(int a, int b) {
    a = get(a);
    b = get(b);
    if (e[a] > e[b]) {
      swap(a, b);
    }
    e[b] = a;
    p[a] = max(p[a], p[b]);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> rg(n);
  {
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && a[st.top()] <= a[i]) {
        st.pop();
      }
      if (st.empty()) {
        rg[i] = -1;
      } else {
        rg[i] = st.top();
      }
      st.push(i);
    }
  }
  DSU dsu(n);
  vector<int> liters(n);
  while (q--) {
    char op;
    cin >> op;
    if (op == '?') {
      int l;
      cin >> l;
      --l;
      cout << liters[l] << '\n';
      continue;
    }
    int l, x;
    cin >> l >> x;
    --l;
    int i = dsu.next(l); 
    if (liters[i] == a[i]) { // todo lleno hacia abajo
      continue;
    }
    while (i != -1 && x) {
      int aux = min(x, a[i] - liters[i]);
      x -= aux;
      liters[i] += aux;
      if (liters[i] == a[i]) {
        if (rg[i] == -1) {
          break;
        }
        dsu.join(i, rg[i]);
        i = dsu.next(i);
      }
    }
  }

  return 0;
}