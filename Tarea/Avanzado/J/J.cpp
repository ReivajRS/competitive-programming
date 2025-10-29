#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline int add(int a, int b, const int& mod) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b, const int& mod) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b, const int& mod) { return (int)((ll)a * b % mod); }

const int X[] = {257, 359};
const int MOD[] = {(int)1e9 + 7, (int)1e9 + 9};
vector<int> xpow[2];

struct Hashing {
  vector<int> h[2];

  Hashing(const string& s) {
    int n = (int)s.size();
    for (int j = 0; j < 2; j++) {
      h[j].resize(n + 1);
      for (int i = 1; i <= n; i++) {
        h[j][i] = add(mul(h[j][i - 1], X[j], MOD[j]), s[i - 1], MOD[j]);
      }
    }
  }

  ll value(int l, int r) {
    int a = sub(h[0][r], mul(h[0][l], xpow[0][r - l], MOD[0]), MOD[0]);
    int b = sub(h[1][r], mul(h[1][l], xpow[1][r - l], MOD[1]), MOD[1]);
    return (ll(a) << 32) + b;
  }
};

void calc_xpow(int mxlen) {
  for (int j = 0; j < 2; j++) {
    xpow[j].resize(mxlen + 1, 1);
    for (int i = 1; i <= mxlen; i++) {
      xpow[j][i] = mul(xpow[j][i - 1], X[j], MOD[j]);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s, sr;
  cin >> s;
  sr = s;
  reverse(sr.begin(), sr.end());

  int n = (int)s.size();
  calc_xpow(n + 1);
  Hashing h(s), hr(sr);

  /*
    abacaba

    nivel 1
    a b a c a b a aba aca aba bacab abacaba
    nivel 2
    aba aca aba abacaba
    nivel 3
    abacaba
  */

  vector<int> cnt(n + 1);
  vector<vector<int>> level(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    level[i][i] = 1;
    cnt[1]++;
  }

  for (int len = 2; len <= n; len++) {
    for (int l = 0, r = len - 1; r < n; l++, r++) {
      int m = len / 2;
      int lb = l, rb = l + m;
      ll lh = h.value(lb, rb);
      lb = rb + (len & 1), rb = r + 1;
      lb = n - lb, rb = n - rb;
      swap(lb, rb);
      ll rh = hr.value(lb, rb);
      if (lh == rh) {
        level[l][r] = 1;
        cnt[1]++;
      }
    }
  }

  for (int len = 2; len <= n; len++) {
    for (int l = 0, r = len - 1; r < n; l++, r++) {
      int m = len / 2;
      int lb = l, rb = l + m;
      ll lh = h.value(lb, rb);
      int left_level = level[lb][rb - 1];
      lb = rb + (len & 1), rb = r + 1;
      ll rh = h.value(lb, rb);
      int right_level = level[lb][rb - 1];
      if (lh == rh && left_level > 0 && left_level == right_level) {
        for (int k = level[l][r] + 1; k <= left_level + 1; k++) {
          cnt[k]++;
        }
        level[l][r] = left_level + 1;
      }
    }
  }

  for (int k = 1; k <= n; k++) {
    cout << cnt[k] << ' ';
  }
  cout << '\n';

  return 0;
}