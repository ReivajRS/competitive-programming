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

  int tc;
  cin >> tc;

  while (tc--) {
    vector<int> num(3);
    cin >> num[0] >> num[1] >> num[2];
    
    int sum = (num[0] ^ num[1]) + (num[0] ^ num[2]) + (num[1] ^ num[2]);
    cout << sum << '\n';

    bitset<30> bs;
    bs = num[0];
    cout << bs.to_string() << '\n';
    bs = num[1];
    cout << bs.to_string() << '\n';
    bs = num[2];
    cout << bs.to_string() << '\n';
  }
  
  return 0;
}