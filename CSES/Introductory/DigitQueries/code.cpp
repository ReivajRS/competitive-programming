#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll k;
  cin >> k;

  ll sum = 0, num = 0, x = 9, len = 1;
  while (sum + x * len < k) {
    sum += x * len;
    num += x;
    x *= 10;
    len += 1;
  }
  
  ll rem = k - sum;
  ll before = (rem + len - 1) / len;

  num += before;
  rem -= (before - 1) * len;

  vector<int> digits;
  while (num != 0) {
    int d = int(num % 10);
    num /= 10;
    digits.push_back(d);
  }

  reverse(digits.begin(), digits.end());

  cout << digits[rem - 1] << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int q;
  cin >> q;

  while (q--) {
    solve();
  }
}