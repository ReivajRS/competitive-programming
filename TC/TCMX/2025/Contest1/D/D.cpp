#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define SZ(x) (int(x.size()))

static const ull C = ll(1e11) + 3;

ull hashArray(vector<int>& a) {
  ull h = 0;
  for (int i = 0; i < SZ(a); i++) {
    h = h * C + a[i];
  }
  return h;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, c;
  cin >> n >> m >> c;

  vector<vector<int>> a(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }

  vector<vector<int>> cnt(n, vector<int>(c));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt[i][a[i][j]]++;
    }
  }

  vector<ull> hashes(n);
  for (int i = 0; i < n; i++) {
    hashes[i] = hashArray(cnt[i]);
  }

  int mid = n / 2;

  vector<set<ull>> st(mid + 1);

  for (int mask = 0; mask < (1 << mid); mask++) {
    ull h = 0;
    int on = 0;
    for (int i = 0; i < mid; i++) {
      if ((mask >> i) & 1) {
        h += hashes[i];
        on++;
      }
    }
    st[on].insert(h);
  }

  vector<set<ull>> st2(n - mid + 1);

  for (int mask = 0; mask < (1 << (n - mid)); mask++) {
    ull h = 0;
    int on = 0;
    for (int i = 0; i < n - mid; i++) {
      if ((mask >> i) & 1) {
        h += hashes[i + mid];
        on++;
      }
    }
    st2[on].insert(h);
  }

  for (int keep = n; keep >= 0; keep--) {
    if (keep * m % c != 0) {
      continue;
    }
    int freq = keep * m / c;
    vector<int> cntTotal(c);
    for (int i = 0; i < c; i++) {
      cntTotal[i] = freq;
    }
    ull hTotal = hashArray(cntTotal);
    for (int on = 0; on < SZ(st); on++) {
      if (keep - on < 0 || keep - on >= SZ(st2)) {
        continue;
      }
      for (auto h : st[on]) {
        if (st2[keep - on].count(hTotal - h)) {
          cout << keep << '\n';
          return 0;
        }
      }
    }
  }

  cout << 0 << '\n';

  return 0;
}