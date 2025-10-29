#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int s1 = a + c, s2 = b + d;
  if (s1 > s2) {
    cout << "A";
    return 0;
  }
  if (s1 == s2) {
    cout << "D";
    return 0;
  }
  cout << "P";
}