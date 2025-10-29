#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

typedef ll T;
struct Point {
    T x, y;

    Point operator+(Point p) const { return {x + p.x, y + p.y}; }
    Point operator-(Point p) const { return {x - p.x, y - p.y}; }

    bool operator<(Point o) const {
        return tie(x, y) < tie(o.x, o.y);
    }
    bool operator==(Point o) const {
        return tie(x, y) == tie(o.x, o.y);
    }
};

T cross(Point v, Point w) { return v.x * w.y - v.y * w.x; }
T cross(Point a, Point b, Point c) { return cross(b - a, c - a); }
int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}
T sq(Point p) { return p.x * p.x + p.y * p.y; }

int orientation(Point a, Point b, Point c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1;
    if (v > 0) return +1;
    return 0;
}

bool cw(Point a, Point b, Point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(Point a, Point b, Point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

vector<Point> convex_hull(vector<Point>& a, bool include_collinear = false) {
    if (SZ(a) == 1)
        return a;

    sort(ALL(a));
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.pb(p1);
    down.pb(p1);
    for (int i = 1; i < (int)SZ(a); i++) {
        if (i == SZ(a) - 1 || cw(p1, a[i], p2, include_collinear)) {
        while (SZ(up) >= 2 && !cw(up[SZ(up) - 2], up[SZ(up) - 1], a[i], include_collinear))
            up.pop_back();
        up.pb(a[i]);
        }
        if (i == SZ(a) - 1 || ccw(p1, a[i], p2, include_collinear)) {
        while (SZ(down) >= 2 && !ccw(down[SZ(down) - 2], down[SZ(down) - 1], a[i], include_collinear))
            down.pop_back();
        down.pb(a[i]);
        }
    }

    if (include_collinear && SZ(up) == SZ(a)) {
        reverse(ALL(a));
        return a;
    }
    vector<Point> ans;
    for (int i = 0; i < (int)SZ(up); i++)
        ans.pb(up[i]);
    for (int i = SZ(down) - 2; i > 0; i--)
        ans.pb(down[i]);

    return ans;
}

bool pointInTriangle(Point a, Point b, Point c, Point p) {
    T s1 = abs(cross(a, b, c));
    T s2 = abs(cross(p, a, b)) + abs(cross(p, b, c)) + abs(cross(p, c, a));
    return s1 == s2;
}

vector<Point> seq;
Point translation;
int n;

void prepare(vector<Point>& points) {
    n = SZ(points);
    int pos = 0;
    FOR(i, 1, n) {
        if (points[i] < points[pos])
        pos = i;
    }
    rotate(points.begin(), points.begin() + pos, points.end());
    n--;
    seq.resize(n);
    FOR(i, 0, n) {
        seq[i] = points[i + 1] - points[0];
    }
    translation = points[0];
}

bool pointInConvexPolygon(Point point) {
    point = point - translation;
    if (cross(seq[0], point) != 0 &&
        sgn(cross(seq[0], point)) != sgn(cross(seq[0], seq[n - 1])))
        return false;
    if (cross(seq[n - 1], point) != 0 &&
        sgn(cross(seq[n - 1], point)) != sgn(cross(seq[n - 1], seq[0])))
        return false;

    if (cross(seq[0], point) == 0)
        return sq(seq[0]) >= sq(point);

    int l = 0, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int pos = mid;
        if (cross(seq[pos], point) >= 0)
        l = mid;
        else
        r = mid;
    }
    int pos = l;
    return pointInTriangle(seq[pos], seq[pos + 1], Point{0, 0}, point);
}

signed main() {_
    int L, S;
    cin >> L;

    vector<Point> pts(L);

    FOR (i, 0, L) {
        ll x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }

    vector<Point> ch = convex_hull(pts);

    reverse(ALL(ch));
    prepare(ch);
    int ans = 0;

    cin >> S;

    FOR (i, 0, S) {
        ll x, y;
        cin >> x >> y;
        ans += pointInConvexPolygon({x, y});
    }

    cout << ans << ENDL;

    return 0;
}