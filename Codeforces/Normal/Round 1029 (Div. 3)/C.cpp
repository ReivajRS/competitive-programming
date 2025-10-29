#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  int l = 0, r = 0;
  set<int> st;
  set<int> seen = {a[0]};
  bool active = 0;
  for (int i = 1; i < n; i++) {
    if (!active) {
      if (seen.count(a[i])) {
        // cout << "segmento nuevo en " << i << '\n';
        r = i;
        for (int j = l; j < i; j++) {
          st.insert(a[j]);
        }
        seen.clear();
        st.erase(a[i]);
        cnt++;
        active = 1;
      }
      else {
        seen.insert(a[i]);
      }
    }
    else {
      st.erase(a[i]);
    }
    if (active && st.empty()) {
      // cout << "segmento completado en " << i << '\n';
      // cnt++;
      for (int j = r; j <= i; j++) {
        // st.insert(a[j]);
        seen.insert(a[j]);
      }
      active = 0;
      l = r;
    }
  }

  // if (l < n - 1) {
  //   cnt++;
  // }

  if (active) {
    cnt++;
  }
  // if (!seen.empty()) {
  //   cout << "hola" << '\n';
  //   cnt++;
  // }

  // cout << l << ' ' << r << '\n';

  cout << cnt << '\n';


  /*
    {}
    l   r - -
    1 2 1 3 2 1 3 2
    
    {}
        l     r - -
    1 2 1 3 2 1 3 2
  */
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}