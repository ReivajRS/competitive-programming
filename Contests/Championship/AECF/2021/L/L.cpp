#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ++n;
    vi a(n);
    vi sum(n,0);
    FOR (i, 1, n) {
      char ch;
      cin >> ch;
      a[i] = ch - '0';
      if(a[i] && i+(i&(-i)) < n) sum[i+(i&(-i))]++;
    }
    int ans = 0;
    FOR (i, 1, n) {
      bool state = sum[i] != 0;
      if(sum[i] >= 2 ) continue;
      if (a[i] == state) continue;
      ans++;
    }
    cout << ans << ENDL;
  }

  return 0;
}