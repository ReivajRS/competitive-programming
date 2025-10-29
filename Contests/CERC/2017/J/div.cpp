#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int N = 1e6;

  vector<int> div(N + 1);
  int mx = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = i; j <= N; j += i) {
      ++div[j];
    }
    mx = max(mx, i * div[i]);
  }
  cout << mx << '\n';
}