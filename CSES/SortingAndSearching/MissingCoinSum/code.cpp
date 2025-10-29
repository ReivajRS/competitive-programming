#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] > sum + 1) {
      break;
    }
    else {
      sum += a[i];
    }
  }

  cout << sum + 1 << '\n';
}