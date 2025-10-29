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

struct Point {
    double x, y;
};

void solve() {
    Point p, a, b, o;
    cin >> p.x >> p.y;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    o = {0, 0};

    auto dist = [](Point p1, Point p2) -> double {
        return hypot(p1.x - p2.x, p1.y - p2.y);
    };

    auto check = [&](double m) -> bool {
        if (dist(o, a) <= m && dist(p, a) <= m)
            return true;
        if (dist(o, b) <= m && dist(p, b) <= m)
            return true;
        if (dist(a, b) <= 2.0 * m) {
            if (dist(o, a) <= m && dist(p, b) <= m)
                return true;
            if (dist(o, b) <= m && dist(p, a) <= m)
                return true;
        }
        return false;
    };

    double l = 0, r = 1e7;

    FOR (i, 0, 100) {
        double m = (r + l) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }

    cout << setprecision(8) << fixed;
    cout << l << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}