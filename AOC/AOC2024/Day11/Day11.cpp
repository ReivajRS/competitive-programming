#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

using ll = long long;

list<ll> input;

void read_input() {
  ll x;
  while (cin >> x) {
    input.push_back(x);
  }
}

int part1() {
  int ans = 0;

  list<ll> stones = input;

  int t = 25;
  while (t--) {
    for (list<ll>::iterator it = stones.begin(); it != stones.end(); it++) {
      if (*it == 0) {
        *it = 1;
        continue;
      }
      string s = to_string(*it);
      if (SZ(s) & 1) {
        *it *= 2024;
        continue;
      }
      int half = SZ(s) / 2;
      string l = s.substr(0, half);
      string r = s.substr(half);
      *it = stoll(r);
      stones.insert(it, stoll(l));
    }
  }

  return ans = SZ(stones);
}

map<pair<ll, int>, ll> dp;

ll solve(ll x, int blinks) {
  if (blinks == 0) return 1;
  if (dp.count({x, blinks})) {
    return dp[{x, blinks}];
  }
  ll &ans = dp[{x, blinks}];
  if (x == 0) {
    return ans = solve(1, blinks - 1);
  }
  string s = to_string(x);
  if (SZ(s) & 1) {
    return ans = solve(x * 2024, blinks - 1);
  }
  int half = SZ(s) / 2;
  string l = s.substr(0, half);
  string r = s.substr(half);
  return ans = solve(stoll(l), blinks - 1) + solve(stoll(r), blinks - 1);
}

ll part2() {
  ll ans = 0;

  list<ll> stones = input;

  int t = 75;

  for (auto x : stones) {
    ans += solve(x, t);
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