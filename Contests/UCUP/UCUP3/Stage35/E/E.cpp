#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll random(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r)(rng);
}

constexpr ll INF = 1e12;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll mn = INF, mx = 0;
  for (int i = 0; i < 200000; ++i) {
    ll x = random(1, INF);
    mn = min(mn, x);
    mx = max(mx, x);
  }
  cout << mn << ' ' << mx << '\n';

  return 0;
}

/*
  E[2][1] = 1 +(1/2 + 1/4*E[1][2] = 2
        x = 1 + (1/2 + (1/4 + 1/8 x))
            (2^{k+1}-1)/2^k

*/