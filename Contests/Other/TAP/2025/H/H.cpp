#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = uint64_t;

ull modmul(ull a, ull b, ull M) {
  ll ret = a * b - M * ull(1.L / M * a * b);
  return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull modpow(ull b, ull e, ull mod) {
  ull ans = 1;
  for (; e; b = modmul(b, b, mod), e /= 2)
    if (e & 1) ans = modmul(ans, b, mod);
  return ans;
}

bool isPrime(ull n) {
  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
  ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
    s = __builtin_ctzll(n - 1), d = n >> s;
  for (ull a : A) {
    ull p = modpow(a % n, d, n), i = s;
    while (p != 1 && p != n - 1 && a % n && i--)
      p = modmul(p, p, n);
    if (p != n - 1 && i != s) return 0;
  }
  return 1;
}

ull pollard(ull n) {
  ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
  auto f = [&](ull x) { return modmul(x, x, n) + i; };
  while (t++ % 40 || __gcd(prd, n) == 1) {
    if (x == y) x = ++i, y = f(x);
    if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
    x = f(x), y = f(f(y));
  }
  return __gcd(prd, n);
}

vector<ull> factor(ull n) {
  if (n == 1) return {};
  if (isPrime(n)) return {n};
  ull x = pollard(n);
  auto l = factor(x), r = factor(n / x);
  l.insert(l.end(), r.begin(), r.end());
  return l;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<ull> divisors(n);

  ull N = 1;
  for (int i = 0; i < n; i++) {
    cin >> divisors[i];
    N = lcm(N, divisors[i]);
  }

  sort(divisors.begin(), divisors.end());

  if (n == 1 && divisors[0] == 1) {
    cout << '*' << '\n';
    return 0;
  }

  if (!binary_search(divisors.begin(), divisors.end(), 1)) {
    cout << N << ' ' << 1 << '\n';
    return 0;
  }

  if (!binary_search(divisors.begin(), divisors.end(), N)) {
    cout << N << ' ' << N << '\n';
    return 0;
  }

  vector<ull> factors = factor(N);
  sort(factors.begin(), factors.end());

  map<ull, int> cnt;
  for (auto x : factors) {
    cnt[x]++;
  }

  vector<pair<ull, int>> factor_cnt;
  for (auto [x, y] : cnt) {
    factor_cnt.push_back({x, y});
  }

  if (int(factor_cnt.size()) == 1) {
    N = 1;
    vector<ull> pot(n);
    vector<bool> in(n);
    for (int i = 0; i < factor_cnt[0].second; i++) {
      N *= factor_cnt[0].first;
      pot[i] = N;
      in[i] = binary_search(divisors.begin(), divisors.end(), N);
    }
    for (int i = 0; i < n - 1; i++) {
      if (!in[i]) {
        cout << N << ' ' << pot[i] << '\n';
        return 0;
      }
    }
    N *= factor_cnt[0].first;
    cout << N << ' ' << N << '\n';
    return 0;
  }

  vector<ull> divisors2;

  auto generate = [&](auto& generate, int i, ull cur) -> void {
    if (i == int(factor_cnt.size())) {
      divisors2.push_back(cur);
      return;
    }
    auto [x, c] = factor_cnt[i];
    ull val = 1;
    for (int j = 0; j <= c; j++) {
      generate(generate, i + 1, cur * val);
      val *= x;
    }
  };

  generate(generate, 0, ull(1));

  for (auto x : divisors2) {
    if (!binary_search(divisors.begin(), divisors.end(), x)) {
      cout << N << ' ' << x << '\n';
      return 0;
    }
  }

  cout << '*' << '\n';
}