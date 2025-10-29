#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = __int128_t;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

constexpr ll LIM = 1e18;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

signed main () { __
    ll r = read(), s = read(), m = read(), d = read(), n = read();
    vi b(r);
    for (auto &x : b) {
      x = read();
    }
    vector<vi> ing(s + m + d+100);
    FOR (i, 0, s + m + d) {
        ll k = read();
        while (k--) {
            ll x = read();
            ing[i].pb(x - 1);
        }
    }
    vector<vector<bool>> ban(s + m + d+100, vector<bool>(s + m + d+100, 0));
    while (n--) {
        ll u = read(), v = read();
        u--, v--;
        ban[min(u, v)][max(u, v)] = 1;
    }
    __int128_t ans = 0;
    FOR (i, 0, s) {
        FOR (j, s, s + m) {
            FOR (k, s + m, s + m + d) {
                if (ban[i][j] || ban [i][k] || ban[j][k])
                    continue;
                vi cnt(1005, 0);
                for (auto &x : ing[i])
                    cnt[x]++;
                for (auto &x : ing[j])
                    cnt[x]++;
                for (auto &x : ing[k])
                    cnt[x]++;
                __int128_t prod = 1;
                FOR (l, 0, r) {
                    if (cnt[l] == 0) continue;
                    prod *= b[l];
                    if (prod > LIM) {
                      cout << "too many" << ENDL;
                      return 0;
                    }
                }
                ans += prod;
                if (ans > LIM) {
                  cout << "too many" << ENDL;
                  return 0;
                }
            }
        }
    }
    print(ans);

    return 0;
}