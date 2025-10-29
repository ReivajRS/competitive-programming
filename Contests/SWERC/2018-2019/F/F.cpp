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

const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef double T;
struct Point {
    T x, y;
    Point operator-(Point p) const { return {x - p.x, y - p.y}; }
};

T sq(Point p ) { return p.x * p.x + p.y * p.y; }

T dot(Point v, Point w) { return v.x * w.x + v.y * w.y; }

Point toVector(Point &p1, Point p2) { return p2 - p1; }

double angle(Point a , Point o, Point b) {
    Point oa = toVector(o, a), ob = toVector(o, b);
    return acos(dot(oa, ob) / sqrt(sq(oa) * sq(ob)));
}

double cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }

bool ccw(Point p, Point q, Point r) { return cross(toVector(p, q), toVector(p, r)) > -EPS; }

signed main() { __
    int n;
    cin >> n;

    vector<Point> pts(n);
    vi val(n);

    FOR (i, 0, n)
        cin >> pts[i].x >> pts[i].y >> val[i];

    ll mn = LLONG_MAX;

    FOR (i, 0, n) {
        vector<pair<double, ll>> angles;
        FOR (j, 0, n) {
            angles.pb({i == j ? 0.0 : angle({1e18, pts[i].y}, pts[i], pts[j]), val[j]});
            if (!ccw(pts[i], {1e18, pts[i].y}, pts[j]))
                angles.back().first = 2*PI - angles.back().first;
        }
        sort(ALL(angles));

        vector<ll> presum(n);
        presum[0] = angles[0].second;
        FOR (j, 1, n)
            presum[j] = presum[j - 1] + angles[j].second;

        FOR (j, 0, n) {
            if (i == j)
                continue;
           
            double ang = angles[j].first, begang, endang;
            if (ang + PI >= 2*PI)
                endang = ang, begang = ang - PI;
            else
                begang = ang, endang = ang + PI;

            int begpos = lower_bound(ALL(angles), pair<double, ll>{begang, 0}) - angles.begin();
            int endpos = lower_bound(ALL(angles), pair<double, ll>{endang, 0}) - angles.begin();

            if (angles[endpos].first > endang || endpos == n)
                endpos--;

            ll side1 = presum[endpos] - (begpos > 0 ? presum[begpos - 1] : 0) + angles[0].second;
            ll side2 = presum.back() - side1 + angles[0].second + angles[j].second;

            mn = min(mn, abs(side1 - side2));
        }
    }

    cout << mn << ENDL;

    return 0;
}