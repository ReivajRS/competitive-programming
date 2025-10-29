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

const double PI = acos(-1.0), EPS = 1e-9;

typedef double T;
struct Point {
    T x, y;
    Point operator-(Point p) const { return {x - p.x, y - p.y}; }
    T dot(Point p) { return x * p.x + y * p.y; }
    T cross(Point p) const { return x * p.y - y * p.x; }
    T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
};

int sgn(T x) { return (T(0) < x) - (x < T(0)); }

T orient(Point a, Point b, Point c) {
    return a.cross(b, c);
}

Point circlePoint(Point c, double r, double ang) {
    return Point{c.x + cos(ang) * r, c.y + sin(ang) * r};
}

bool inDisk(Point a, Point b, Point p) {
    return (a - p).dot(b - p) <= EPS;
}

bool onSegment(Point a, Point b, Point p) {
    return abs(a.cross(b,p)) <= EPS && inDisk(a, b, p);
}

bool inPolygonCH(vector<Point>& l, Point p, bool strict = true) {
    int a = 1, b = SZ(l) - 1, r = !strict;
    if (SZ(l) < 3)  return r && onSegment(l[0], l.back(), p);
    if (orient(l[0], l[a], l[b]) > 0)   swap(a, b);
    if (orient(l[0], l[a], p) >= r || orient(l[0], l[b], p) <= -r)
        return false;
    while (abs(a - b) > 1) {
        int c = (a + b) / 2;
        (orient(l[0], l[c], p) > 0 ? b : a) = c;
    }
    return sgn(l[a].cross(l[b], p)) < r;
}

double areaPolygon(vector<Point>& p) {
    double area = 0.0;
    int n = SZ(p);
    FOR (i, 0, n) {
        area += p[i].cross(p[(i + 1) % n]);
    }
    return abs(area) / 2.0;
}

vector<Point> pts;

bool checkAll(int k, double r) {
    double ang = 2*PI/k;
    vector<Point> ch(k);
    FOR (i, 0, k)
        ch[i] = circlePoint({0, 0}, r, ang * i);
    bool flag = true;
    for (auto p : pts)
        flag &= inPolygonCH(ch, p, true);
    return flag;
}

bool checkOne(int k, double r) {
    double ang = 2*PI/k;
    vector<Point> ch(k);
    FOR (i, 0, k)
        ch[i] = circlePoint({0, 0}, r, ang * i);
    bool flag = false;
    for (auto p : pts)
        flag |= inPolygonCH(ch, p, true);
    return flag;
}

double score(int k, double x) {
    double ang = 2*PI/k;

    vector<Point> chO(k), chI(k);
    
    double l = 0.0, r = 1e7;
    FOR (i, 0, 100) {
        double m = (l + r) / 2.0;
        if (checkAll(k, m))
            r = m;
        else
            l = m;
    }

    FOR (i, 0, k)
        chO[i] = circlePoint({0, 0}, l, ang * i);

    l = 0.0, r = 1e7;
    FOR (i, 0, 100) {
        double m = (l + r) / 2.0;
        if (!checkOne(k, m))
            l = m;
        else
            r = m;
    }

    FOR (i, 0, k)
        chI[i] = circlePoint({0, 0}, l, ang * i);
    
    return areaPolygon(chI) / areaPolygon(chO);
}

signed main() { __
    int n;
    cin >> n;

    pts.resize(n);

    double r = 0;
    FOR (i, 0, n) {
        cin >> pts[i].x >> pts[i].y;
        r = max(r, pts[i].x);
    }

    int mxK = 0;
    double mxArea = 0;
    FOR (k, 3, 9) {
        double sc = score(k, r);
        if (sc > mxArea)
            mxK = k, mxArea = sc;
    }

    cout << setprecision(10) << fixed;
    cout << mxK << ' ' << mxArea << ENDL;

    return 0;
}