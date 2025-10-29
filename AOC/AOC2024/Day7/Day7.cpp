#include <bits/stdc++.h>
using namespace std;

using ll = long long;

unordered_map<ll, vector<ll>> input;
ll pows10[19];

void read_input() {
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    string t;
    ss >> t;
    ll target = stoll(t.substr(0, s.length()));
    while (ss >> t) {
      input[target].push_back(stoi(t));
    }
  }
}

int log_10(ll x) {
  int cnt = 0;
  while (x) {
    x /= 10;
    cnt++;
  }
  return cnt;
}

bool check(int i, ll current, ll &target) {
  if (current > target) {
    return false;
  }
  if (i == (int)input[target].size()) {
    return current == target;
  }
  return check(i + 1, current + input[target][i], target) || check(i + 1, current * input[target][i], target);
}

bool check2(int i, ll current, ll &target) {
  if (current > target) {
    return false;
  }
  if (i == (int)input[target].size()) {
    return current == target;
  }
  ll next = current * pows10[log_10(input[target][i])] + input[target][i];
  return check2(i + 1, current + input[target][i], target) || check2(i + 1, current * input[target][i], target) || check2(i + 1, next, target);
}

ll part1() {
  ll ans = 0;

  for (auto &[target, v] : input) {
    ll x = target;
    if (check(1, v[0], x)) {
      ans += x;
    }
  }

  return ans;
}

ll part2() {
  ll ans = 0;

  for (auto &[target, v] : input) {
    ll x = target;
    if (check2(1, v[0], x)) {
      ans += x;
    }
  }

  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  pows10[0] = 1;
  for (int i = 1; i < 19; i++) {
    pows10[i] = pows10[i - 1] * 10;
  }
  
  read_input();
  cout << "Part 1: " << part1() << '\n';
  cout << "Part 2: " << part2() << '\n';

  return 0;
}