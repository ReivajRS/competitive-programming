#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  set<long long> st = {0};
  long long sum = 0;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    sum += v;
    if (st.count(sum - x)) {
      cnt++;
    }
    st.insert(sum);
  }

  cout << cnt << '\n';

  return 0;
}