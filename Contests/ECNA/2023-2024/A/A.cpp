#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  int a[n];
  FOR( i, 0, n) {
    cin >> a[i];
  }

  int lg[n], rs[n];
  stack<int> st;
  FOR (i, 0, n) {
    while (!st.empty() && a[st.top()] <= a[i]) {
      st.pop();
    }
    lg[i] = (st.empty() ? -1 : st.top());
    st.push(i);
  }
  while (!st.empty()) st.pop();
  ROF (i, n, 0) {
    while (!st.empty() && a[st.top()] > a[i]) {
      st.pop();
    }
    rs[i] = (st.empty() ? n : st.top());
    st.push(i);
  }

  vi ans;
  FOR (i, 0, n) {
    if (lg[i] == -1 && rs[i] == n) {
      ans.push_back(a[i]);
    }
  }
  cout << (int) (ans.size());
  FOR (i, 0, min((int)ans.size(), 100)) {
    cout << " " << ans[i];
  }
  cout << ENDL;

  return 0;
}