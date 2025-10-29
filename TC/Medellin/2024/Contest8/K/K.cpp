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

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) {
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) {
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi ys(n);
  vector<pi> pts(n);
  FOR (i, 0, n) {
    cin >> pts[i].first >> pts[i].second;
    ys[i] = pts[i].second;
  }
  sort(ALL(ys));
  ys.erase(unique(ALL(ys)), ys.end());

  sort(ALL(pts));

  FOR (i, 0, SZ(pts)) {
    int j = lower_bound(ALL(ys), pts[i].second) - ys.begin();
    pts[i].second = j;
  }

  ll ans = 0;

  auto process = [&]() -> void {
    FT ft(SZ(ys) + 5);
    int last_x = -1;
    vi waiting;
    for (auto &[x, y] : pts) {
      if (x != last_x) {
        for (auto &y_w : waiting) ft.update(y_w, 1);
        last_x = x;
        waiting.clear();
      }
      ans += ft.query(SZ(ys)) - ft.query(y + 1);
      waiting.pb(y);
    }
  };
  
  process();
  reverse(ALL(pts));
  process();

  cout << ans << ENDL;

  return 0;
}