#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'
#define SZ(x) ((int)x.size())

using ll = long long;

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) {
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) {
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll inv = 1e9;
  ll cnt = 0;
  FT bit(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    bit.update(a[i], 1);
    cnt += bit.query(a[i]);
  }

  inv = cnt;

  bool useXor = false;
  for (int i = 18; i >= 0; i--) {
    int x = (1 << i);
    cnt = 0;
    FT bit(n + 1);
    bool valiomadres = false;
    for (int j = n - 1; j >= 0; j--) {
      int y = a[j] ^ x;
      if(y > n){
        valiomadres = true;
        break;
      }
      bit.update(y, 1);
      cnt += bit.query(y);
    }
    if (!valiomadres && cnt < inv) {
      useXor = true;
      inv = cnt;
      for (int j = n - 1; j >= 0; j--) {
        a[j] ^= x;
      }
    }
  }

  cout << inv + useXor << '\n';

  return 0;
}