#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

bool is_prime(ll x) {
  for (int i = 2; i * i <= x; ++i) if (x % i == 0) return 0;
  return 1;
}

const int maxn = 1e6 + 5;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;

  int sq = sqrt(n);
  if ((ll)sq * sq == n && is_prime(sq)) {
    cout << sq << ENDL;
    return 0;
  }

  vi div(maxn, 1);
  div[1] = 1;
  {
    vi prime(maxn, 1);
    FOR (i, 2, maxn) if (prime[i]) {
      div[i]++;
      for (int j = i + i; j < maxn; j += i) {
        prime[j] = 0;
        ll aux = 1, exp = 0;
        while (j % aux == 0) {
          aux *= i;
          exp++;
        }
        exp--;
        div[j] *= (exp + 1);
      }
    }
  }

  FOR (i, 2, maxn) {
    __int128_t k = 1;
    // k * i  > n
    // k > n / i
    bool me_pase = 0;
    for (int z = 0; z < div[i]; ++z) {
      if (k*i > n) {
        me_pase = 1;
        break;
      }
      k *= i;
    }

    if (!me_pase && k == n) {
      cout << i << ENDL;
      return 0;
    }
  }
  cout << -1 << ENDL;

  return 0;
}