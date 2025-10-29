#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  stack<char> st;
  for (char c : s) {
    if (c == ')') {
      if (!st.empty()) {
        st.pop();
      }
    }
    else {
      st.push('(');
    }
  }
  if (!st.empty()) {
    cout << "impossible" << '\n';
  }
  else {
    cout << s << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}