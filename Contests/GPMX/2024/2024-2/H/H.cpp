#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  int n, r, c;
  cin >> n >> r >> c;
  
  r--, c--;
  int R = r, C = c;

  set<int> hired;
  vector<bool> a(n, true);
  int s1 = 0, s2 = n - 1, N = n;

  while (n > 2) {
    r = R % n;
    c = C % n;

    int cnt = r;
    while (cnt) {
      s1++;
      if (s1 == N) {
        s1 = 0;
      }
      cnt -= a[s1];
    }

    cnt = c;
    while (cnt) {
      s2--;
      if (s2 < 0) {
        s2 = N - 1;
      }
      cnt -= a[s2];
    }

    if (s1 == s2) {
      hired.insert(s1 + 1);
      a[s1] = false;
      n--;
    } else {
      a[s1] = a[s2] = false;
      n -= 2;
    }

    cnt = 1;
    while (cnt) {
      s1++;
      if (s1 == N) {
        s1 = 0;
      }
      cnt -= a[s1];
    }

    cnt = 1;
    while (cnt) {
      s2--;
      if (s2 < 0) {
        s2 = N - 1;
      }
      cnt -= a[s2];
    }
  }

  FOR (i, 0, N) {
    if (a[i]) {
      hired.insert(i + 1);
    }
  }

  for (auto &x : hired) {
    cout << x << ' ';
  }
  cout << ENDL;

  return 0;
}