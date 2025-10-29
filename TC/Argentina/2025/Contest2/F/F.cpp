#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

using ull = uint64_t;
struct H {
  ull x;
  H(ull x = 0) : x(x) {}
  H operator+(H o) { return x + o.x + (x + o.x < x); }
  H operator-(H o) { return *this + ~o.x; }
  H operator*(H o) {
    auto m = (__uint128_t)x * o.x;
    return H((ull)m) + (ull)(m >> 64);
  }
  ull get() const {
    return x + !~x;
  }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator!=(H o) const { return get() != o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};

static const H C = (ll)1e11 + 3;

struct HashInterval {
  vector<H> ha, pw;
  HashInterval(string& str) : ha(SZ(str) + 1), pw(ha) {
    pw[0] = 1;
    FOR(i, 0, SZ(str)) {
      ha[i + 1] = ha[i] * C + str[i];
      pw[i + 1] = pw[i] * C;
    }
  }
  H hashInterval(int a, int b) {
    return ha[b] - ha[a] * pw[b - a];
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s, t;
  cin >> s >> t;

  int n = s.size(), m = t.size();
  vector<int> v(n), cnt(2);
  for (int i = 0; i < n; ++i) {
    v[i] = s[i] - '0';
    ++cnt[v[i]];
  }
  vector<int> nxtDifferent(n);
  nxtDifferent.back() = n;
  for (int i = n - 2; i >= 0; --i) {
    nxtDifferent[i] = v[i] != v[i + 1] ? i + 1 : nxtDifferent[i + 1];
  }
  HashInterval h(t);

  vector<vector<bool>> ok(2, vector<bool>(m + 1));
  for (int fixed = 0; fixed < 2; ++fixed) {
    for (int sz = 1; sz * cnt[fixed] < m; ++sz) {
      int res = m - sz * cnt[fixed];
      if (res % cnt[fixed ^ 1]) {
        continue;
      }
      int otherSz = res / cnt[fixed ^ 1];
      H r = v[0] == fixed ? h.hashInterval(0, sz)
                          : h.hashInterval(otherSz * nxtDifferent[0], otherSz * nxtDifferent[0] + sz);
      ok[fixed][sz] = true;
      for (int i = 0, j = 0; i < n; ++i) {
        if (v[i] != fixed) {
          j += (nxtDifferent[i] - i) * otherSz;
          i = nxtDifferent[i];
          if (i == n) {
            break;
          }
        }
        if (h.hashInterval(j, j + sz) != r) {
          ok[fixed][sz] = false;
          break;
        }
        j += sz;
      }
    }
  }

  int ans = 0;
  for (int sz0 = 1; sz0 * cnt[0] < m; ++sz0) {
    int res = m - sz0 * cnt[0];
    int sz1 = res / cnt[1];
    if (res % cnt[1] || !ok[0][sz0] || !ok[1][sz1]) {
      continue;
    }
    H r0, r1;
    if (!v[0]) {
      r0 = h.hashInterval(0, sz0);
      int p = nxtDifferent[0] * sz0;
      r1 = h.hashInterval(p, p + sz1);
    } else {
      r1 = h.hashInterval(0, sz1);
      int p = nxtDifferent[0] * sz1;
      r0 = h.hashInterval(p, p + sz0);
    }
    ans += r0 != r1;
  }
  cout << ans << '\n';

  return 0;
}