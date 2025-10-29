#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using int128 = __int128_t;
void print(int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

signed main() { __
    int r, s, m, d, n;
    cin >> r >> s >> m >> d >> n;

    vi b(r);
    FOR (i, 0, r)
        cin >> b[i];

    vector<vi> ing(s + m + d + 5);

    FOR (i, 0, s + d + m) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            ing[i].pb(x - 1);
        }
    }

    set<pi> bans;
    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        bans.insert({min(a, b), max(a, b)});
    }

    int128 ans = 0;

    FOR (i, 0, s) {
        FOR (j, s, s + m) {
            FOR (k, s + m, s + m + d) {
                if (bans.count({i, j}) || bans.count({i, k}) || bans.count({j, k}))
                    continue;
                vi cnt(r, 0);
                for (auto &x : ing[i])
                    cnt[x]++;
                for (auto &x : ing[j])
                    cnt[x]++;
                for (auto &x : ing[k])
                    cnt[x]++;
                int128 dinners = 1;
                FOR (l, 0, r) {
                    if (cnt[l] == 0)
                        continue;
                    dinners *= b[l];
                }
                ans += dinners;
                if (ans > (int128)1e18) {
                    cout << "too many" << ENDL;
                    return 0;
                }
            }
        }
    }

    print(ans);

    return 0;
}