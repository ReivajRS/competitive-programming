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

string s;
int a[100 + 2];
int dp[100 + 2][5 + 2][5 + 2][5 + 2][5 + 2];
int nxt[100 + 2][5 + 2][5 + 2][5 + 2][5 + 2];

int same(int a, int b) {
  return a != 4 && b != 4 && a == b;
}

int f(int i, int a0, int a1, int a2, int a3) {
  // cout << i << ' ' << a0 << ' ' << a1 << ' ' << a2 << ' ' << a3 << ENDL;
  if (same(a0, a1) || same(a0, a2) || same(a0, a3) || same(a1, a2) || same(a1, a3) || same(a2, a3)) {
    return 0;
  }
  if (i == SZ(s)) {
    return 1;
  }
  int &ans = dp[i][a0][a1][a2][a3];
  int &nx = nxt[i][a0][a1][a2][a3];
  if (ans) {
    return 0;
  }
  ans = 1;
  if (a[i] != -1) {
    bool b = f(i + 1, a1, a2, a3, a[i]);
    if (b) { 
      nx = a[i];
    }
    return b;
  }
  FOR (k, 0, 4) {
    if (f(i + 1, a1, a2, a3, k)) {
      nx = k;
      return 1;
    }
  }
  return 0;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // r b y g
  cin >> s;
  FOR (i, 0, SZ(s)) {
    if (s[i] == 'R') {
      a[i] = 0;
    } else if (s[i] == 'B') {
      a[i] = 1;
    } else if (s[i] == 'Y') {
      a[i] = 2;
    } else if (s[i] == 'G'){
      a[i] = 3;
    } else {
      a[i] = -1;
    }
  }
  f(0, 4, 4, 4, 4);
  vi cnt(4, 0);
  int i = -1, a0 = 4, a1 = 4, a2 = 4, a3 = 4;
  while (++i < SZ(s)) {
    int k = nxt[i][a0][a1][a2][a3];
    swap(a0, a1);
    swap(a1, a2);
    swap(a2, a3);
    a3 = k;
    if (a[i] == -1) {
      cnt[a3]++;
    }
  }
  FOR (k, 0, 4) {
    cout << cnt[k] << ' ';
  }
  cout << ENDL;

  

  return 0;
}