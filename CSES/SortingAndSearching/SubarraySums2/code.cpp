#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;
  
  map<long long, int> mp = {{0ll, 1}};
  long long sum = 0;
  long long cnt = 0;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    sum += v;
    cnt += mp[sum - x];
    mp[sum]++;
  }

  cout << cnt << '\n';

  return 0;
}