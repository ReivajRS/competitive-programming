#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using int128 = __int128_t;

void print(int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}

int128 gcd(int128 a, int128 b) {
  return b ? gcd(b, a % b) : a;
}

struct Frac {
  int128 num, den;

  Frac() : num(0), den(1) {}
  Frac(int128 num, int128 den) {
    int128 g = gcd(num, den);
    this->num = num / g;
    this->den = den / g;
  }

  Frac operator*(Frac f) const { return Frac(num * f.num , den * f.den); }
  Frac operator+(Frac f) const { return Frac(num * f.den + den * f.num , den * f.den); }
};

const int MAX_M = 35, MAX_P = 35;
int m, n, p;
Frac dp[MAX_M][MAX_P];
bool ready[MAX_M][MAX_P];

Frac solve(int rem_turns, int rem_squares) {
  if (!rem_turns)
    return Frac(!rem_squares, 1);
  if (!rem_squares)
    return Frac(0, 1);
  Frac &ans = dp[rem_turns][rem_squares];
  if (ready[rem_turns][rem_squares])
    return ans;
  ans = Frac(0, 1);
  int128 total = m - (p - rem_turns);
  int128 useful = rem_squares * 2;
  int128 not_useful = total - useful;
  ans = ans + Frac(useful, total) * solve(rem_turns - 1, rem_squares - 1);
  ans = ans + Frac(not_useful, total) * solve(rem_turns - 1, rem_squares);
  ready[rem_turns][rem_squares] = 1;
  return ans;
}

signed main() { __
  cin >> m >> n >> p;

  memset(ready, 0, sizeof ready);

  Frac ans = solve(p, n);

  print(ans.num);
  putchar('/');
  print(ans.den);
  putchar('\n');

  return 0;
}