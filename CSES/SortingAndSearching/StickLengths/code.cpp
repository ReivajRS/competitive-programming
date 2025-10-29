#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int m1 = a[n / 2], m2 = a[(n + 1) / 2];
  ll sum1 = 0, sum2 = 0;

  for (int i = 0; i < n; i++) {
    sum1 += abs(a[i] - m1);
    sum2 += abs(a[i] - m2);
  }

  cout << min(sum1, sum2) << '\n';
}