#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int MAXN = 1e7 + 10;
bitset<MAXN> is_prime;
int cnt[MAXN];

void sieve(int n) {
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if(!is_prime[p])continue;
    for(ll i=p*p;i<=n;i+=p)is_prime[i]=0;
  }
}

void solve() {
  int n;
  cin >> n;
  cout << cnt[n] << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  sieve(MAXN);

  cnt[5] = 2;

  for (int i = 5; i < MAXN - 2; i++) {
    cnt[i] += cnt[i - 1];
    if (is_prime[i] && is_prime[i + 2])
      cnt[i + 2]++;
  }
  
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}