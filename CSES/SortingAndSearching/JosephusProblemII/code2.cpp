#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  oset<int> st;

  for (int i = 1; i <= n; i++) {
    st.insert(i);
  }

  int x = 0;
  while (!st.empty()) {
    x = (x + k) % int(st.size());
    auto it = st.find_by_order(x);
    cout << *it << ' ';
    st.erase(it);
  }
  
  cout << '\n';
}