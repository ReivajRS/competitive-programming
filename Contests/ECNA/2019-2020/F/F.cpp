#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n;
  cin >> n;
  list<pi> ls;

  FOR (i, 0, n) {
    int x;
    cin >> x;
    ls.push_back({x - 1, i + 1});
  }

  int act = 0;
  auto it = ls.begin();

  while (SZ(ls) > 1) {
    act = it->first % SZ(ls);
    FOR (i, 0, act) {
      it++;
      if (it == ls.end())
        it = ls.begin();
    }
    it = ls.erase(it);
    if (it == ls.end())
      it = ls.begin();
  }

  cout << it->second << ENDL;

  return 0;
}