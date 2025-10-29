#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  pi q, ks, ke;
  cin >> n >> q.first >> q.second >> ks.first >> ks.second >> ke.first >> ke.second;

  auto vertical = [&](pi q, pi k) -> int {
    return k.first > q.first;
  };

  auto horizontal = [&](pi q, pi k) -> int {
    return k.second > q.second;
  };

  cout << (vertical(q, ks) == vertical(q, ke) && horizontal(q, ks) == horizontal(q, ke) ? "YES" : "NO") << ENDL;

  return 0;
}