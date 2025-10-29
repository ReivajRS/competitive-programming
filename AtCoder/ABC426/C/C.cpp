#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<int> cnt(n + 1, 1);
  cnt[0] = 0;

  while (q--) {
    int x, y;
    cin >> x >> y;
    int sum = 0;
    while (cnt[x]) {
      sum += cnt[x];
      cnt[x] = 0;
      x--;
    }
    cnt[y] += sum;
    cout << sum << '\n';
  }
}