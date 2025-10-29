#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  const int maxn = 100005;
  vector<int> win(maxn);

  for (int i = 1; i < maxn; i++) {
    ll op1 = 1, op2 = 0;
    ll x = i;
    while (x) {
      ll d = x % 10;
      x /= 10;
      op1 *= d;
      op2 += d * d;
    }
    if (op1 > op2) {
      win[i] = 1;
    }
    else if (op2 > op1) {
      win[i] = 2;
    }
  }

  vector<int> pref1(maxn), pref2(maxn);
  for (int i = 1; i < maxn; i++) {
    pref1[i] = pref1[i - 1] + (win[i] == 1);
    pref2[i] = pref2[i - 1] + (win[i] == 2);
  }

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int c1 = pref1[b] - pref1[a - 1];
    int c2 = pref2[b] - pref2[a - 1];
    cout << c1 << ' ' << c2 << '\n';
  }

  return 0;
}