#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  multiset<int> st;
  for (int i = 0; i < k - 1; i++) {
    st.insert(a[i]);
  }
  for (int i = 0; i + k - 1 < n; i++) {
    st.insert(a[i + k - 1]);
    cout << *st.rbegin() << ' ';
    st.extract(a[i]);
  }
  cout << '\n';
  
  return 0;
}