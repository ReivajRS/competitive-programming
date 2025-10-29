#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)

signed main() {
  int O, A, K;
  cin >> O >> A >> K;

  for (int i = 1; A * i < O; i++) {
    if ((O - A * i) % K == 0) {
      cout << 1 << '\n';
      return 0;
    } 
  }
  cout << 0 << '\n';

  return 0;
}