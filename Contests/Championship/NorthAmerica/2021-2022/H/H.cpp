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

  int n, k;
  cin >> n >> k;

  vi cnt(3);
  FOR (i, 0, n) {
    char c;
    cin >> c;
    cnt[c-'A']++;
    FOR (j, 1, k) {
      char ax;
      cin >> ax;
    }
  }
  cout << (max(cnt[2]-cnt[0],0)+max(cnt[1]-cnt[0],0)<=cnt[0]) << ENDL;

  return 0;
}