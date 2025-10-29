#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using ll = long long;

void f(ll a, ll b, int& mnFound, int steps) {
  if (a > b) {
    swap(a, b);
  }
  if (steps >= mnFound) {
    return;
  }
  if (!a) {
    mnFound = steps;
    return;
  }
  ll g = gcd(a, b);
  f(a - g, b, mnFound, steps + 1), f(a, b - g, mnFound, steps + 1);
}

void solve() {
  ll a, b;
  cin >> a >> b;

  int mnFound = INT_MAX;
  f(a, b, mnFound, 1);

  cout << mnFound << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;

  while (T--) {
    solve();
  }
}