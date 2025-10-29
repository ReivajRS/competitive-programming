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

constexpr double EPS = 1e-9;

struct point {
    double x, y;
};

struct shield {
    int l, u;
    double f;
    bool operator<(shield& o) const {
        return tie(l, u) < tie(o.l, o.u);
    }
};

signed main() { __
    int x, y, n;
    cin >> x >> y >> n;

    vector<shield> vs(n);
    FOR (i, 0, n)
        cin >> vs[i].l >> vs[i].u >> vs[i].f;
    
    sort(ALL(vs));

    bool neg = (x < 0);
    x = abs(x);

    point p = {(double)x, (double)y};

    auto dist = [](point p1, point p2) {
        return hypot(p1.x - p2.x, p1.y - p2.y);
    };

    auto check = [&](double hv) {
        point mal = {0.0, 0.0};
        double v = hv;
        FOR (i, 0, n) {
            // Under the shield
            if (y < vs[i].l || abs(y - vs[i].l) <= EPS) {
                mal.x += (y - mal.y) * hv;
                mal.y = y;
                return dist(mal, p);
            }
            mal.x += (vs[i].l - mal.y) * hv;
            mal.y = vs[i].l;

            // In the shield
            hv *= vs[i].f;
            if (y < vs[i].u || abs(y - vs[i].u) <= EPS) {
                mal.x += (y - mal.y) * hv;
                mal.y = y;
                return dist(mal, p);
            }
            mal.x += (vs[i].u - mal.y) * hv;
            mal.y = vs[i].u;

            // After the shield
            hv = v;
        }
        mal.x += (y - mal.y) * hv;
        mal.y = y;
        return dist(mal, p);
    };

    double l = 0.0, r = 1e10;

    FOR (i, 0, 200) {
        double dif = (r - l) / 3;
        double m1 = l + dif;
        double m2 = r - dif;
        if (check(m1) > check(m2))
            l = m1;
        else
            r = m2;
    }

    if (neg)
        l *= -1;
    cout << setprecision(12) << fixed << l << ENDL;

    return 0;
}