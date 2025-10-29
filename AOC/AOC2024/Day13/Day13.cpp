#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

using ll = long long;

vector<tuple<array<int, 2>, array<int, 2>, array<int, 2>>> input;

void read_input() {
  int x[3], y[3];
  while (scanf("Button A: X+%d, Y+%d\n", &x[0], &y[0]) != EOF) {
    // printf("%d, %d\n", x[0], y[0]);
    scanf("Button B: X+%d, Y+%d\n", &x[1], &y[1]);
    // printf("%d, %d\n", x[1], y[1]);
    scanf("Prize: X=%d, Y=%d\n", &x[2], &y[2]);
    // printf("%d, %d\n", x[2], y[2]);
    input.push_back({{x[0], y[0]}, {x[1], y[1]}, {x[2], y[2]}});
  }
}

const int INF = 1e9;
map<pair<int, int>, int> dp;

int solve1(int x, int y, array<int, 2> &d1, array<int, 2> &d2) {
  if (x == 0 && y == 0) return 0;
  if (x < 0 || y < 0) return INF;
  if (dp.count({x, y})) return dp[{x, y}];
  int &ans = dp[{x, y}];
  ans = INF;
  ans = min(ans, solve1(x - d1[0], y - d1[1], d1, d2) + 3);
  ans = min(ans, solve1(x - d2[0], y - d2[1], d1, d2) + 1);
  return ans;
}

array<ll, 2> cramer(array<ll, 2> r1, array<ll, 2> r2, array<ll, 2> obj) {
  ll d1 = obj[0] * r2[1] - r1[1] * obj[1];
  ll d2 = r1[0] * obj[1] - r2[0] * obj[0];
  ll D = r1[0] * r2[1] - r1[1] * r2[0];
  return {d1 / D, d2 / D};
}

int part1() {
  int ans = 0;

  // for (int i = 0; i < SZ(input); i++) {
  //   auto [d1, d2, obj] = input[i];
  //   dp.clear();
  //   int cost = solve1(obj[0], obj[1], d1, d2);
  //   if (cost == INF) continue;
  //   ans += cost;
  //   // cout << cost << '\n';
  // }

  for (int i = 0; i < SZ(input); i++) {
    auto [d1, d2, obj] = input[i];
    auto [a, b] = cramer({d1[0], d2[0]}, {d1[1], d2[1]}, {obj[0], obj[1]});
    if ((d1[0] * a + d2[0] * b) == (obj[0]) && (d1[1] * a + d2[1] * b) == (obj[1])) {
      ans += a * 3 + b;
    }
  }

  return ans;
}

ll part2() {
  ll ans = 0;

  const ll EXTRA = 10000000000000;
  
  for (int i = 0; i < SZ(input); i++) {
    auto [r1, r2, obj] = input[i];
    auto [a, b] = cramer({r1[0], r2[0]}, {r1[1], r2[1]}, {EXTRA + obj[0], EXTRA + obj[1]});
    if ((1ll * r1[0] * a + r2[0] * b) == (EXTRA + obj[0]) && (1ll * r1[1] * a + r2[1] * b) == (EXTRA + obj[1])) {
      ans += a * 3 + b;
    }
  }

  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  read_input();
  cout << "Part 1: " << part1() << '\n';
  cout << "Part 2: " << part2() << '\n';

  return 0;
}