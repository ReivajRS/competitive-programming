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

  stack<int> st;
  vector<int> prev_smaller(n, -1), next_smaller(n, -1);

  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      st.pop();
    }
    if (!st.empty()) {
      prev_smaller[i] = st.top();
    }
    st.push(i);
  }

  for (int i = 0; i < n; i++) {
    cout << prev_smaller[i] + 1 << ' ';
  }

  cout << '\n';
}