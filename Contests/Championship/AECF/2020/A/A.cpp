#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i,a,b) for(ll i = (ll)a-1; i >= (ll)b; i--)
#define ENDL '\n'

constexpr ll MOD = 998244353;

ll add(ll &x, ll y) {
  x = (x + y) % MOD;
  return x;
}

ll subs(ll &x, ll y) {
  x = (x - y + MOD) % MOD;
  return x;
}

ll mul(ll &x, ll y) {
  x = x * y % MOD;
  return x;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  map<char, ll> mp;
  FOR (i, 0, 26) mp[char('a' + i)] = i;
  FOR (i, 0, 26) mp[char('A' + i)] = 26 + i;
  FOR (i, 0, 10) mp[char('0' + i)] = 52 + i;

  string s;
  cin >> s;

  ll n = SZ(s);
  vi a(n);
  FOR (i, 0, n) {
    a[i] = mp[s[i]];
  }

  vi cnt_left(62, 0), cnt_right(62, 0);
  vector<vi> left_par(62, vi(62, 0));
  vi left_first(62, 0), left_second(62, 0);
  ll sum = 0;
  FOR (i, 0, n) {
    add(cnt_left[a[i]], 1);
    FOR (j, 0, 62) if (j != a[i]) {
      add(sum, cnt_left[j]);
      add(left_par[j][a[i]], cnt_left[j]);
      add(left_first[j], cnt_left[j]);
      add(left_second[a[i]], cnt_left[j]);
    }
  }

  vector<vi> right_par(62, vi(62, 0)), right_tri(62, vi(62, 0));
  ll ans = 0;
  ROF (i, n, 0) {
    subs(cnt_left[a[i]], 1);
    FOR (j, 0, 62) if (j != a[i]) {
      subs(left_par[j][a[i]], cnt_left[j]);
      subs(left_first[j], cnt_left[j]);
      subs(left_second[a[i]], cnt_left[j]);
      subs(sum, cnt_left[j]);
    }
    FOR (j, 0, 62) if (j != a[i]) {
      ll left = sum;
      subs(left, left_first[a[i]]);
      subs(left, left_second[a[i]]);
      subs(left, left_first[j]);
      subs(left, left_second[j]);
      add(left, left_par[a[i]][j]);
      add(left, left_par[j][a[i]]);
      ll right = right_tri[j][a[i]];
      add(ans, mul(left, right));
    }
    FOR (j, 0, 62) if (j != a[i]) add(right_tri[a[i]][j], right_par[j][a[i]]);
    FOR (j, 0, 62) if (j != a[i]) add(right_tri[a[i]][j], cnt_right[j]);
    add(cnt_right[a[i]], 1);
  }
  cout << ans << ENDL;
  
  return 0;
}