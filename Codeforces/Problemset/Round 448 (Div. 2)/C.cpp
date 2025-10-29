#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
  
  vector<vector<int>> cnt(71, vector<int>(2));
  for (int x = 1; x <= 70; x++) {
    cnt[x][0] = 1;
  }
  for (auto x : a) {
    int aux = cnt[x][0];
    cnt[x][0] = (cnt[x][0] + cnt[x][1]) % MOD;
    cnt[x][1] = (cnt[x][1] + aux) % MOD;
  }

  vector<int> mask_num(71);

  for (int x = 1; x <= 70; x++) {
    for (int p = 0; p < 19; p++) {
      int y = x;
      while (y % primes[p] == 0) {
        y /= primes[p];
        mask_num[x] ^= 1 << p;
      }
    }
  }

  vector<int> curr(1 << 19), prev(1 << 19);
  prev[0] = 1;
  for (int x = 1; x <= 70; x++) {
    for (int mask = 0; mask < (1 << 19); mask++) {
      curr[mask] = (curr[mask] + (ll)prev[mask] * cnt[x][0] % MOD) % MOD;
      curr[mask] = (curr[mask] + (ll)prev[mask ^ mask_num[x]] * cnt[x][1] % MOD) % MOD;
    }
    prev = curr;
    fill(curr.begin(), curr.end(), 0);
  }

  cout << (prev[0] - 1 + MOD) % MOD << '\n';

  return 0;
}