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
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

constexpr double EPS = 1e-9;

struct Point {
    double x, y;
    bool operator<(Point o) const {
        if (fabs(x - o.x) > EPS)
            return x < o.x;
        return y < o.y;
    }
    Point operator-(Point o) const { return {x - o.x, y - o.y}; }
    Point operator*(double v) const { return {x * v, y * v}; }
    Point operator/(double v) const { return {x / v, y / v}; }
};

double cross(Point v, Point w) { return v.x * w.y - v.y * w.x; }

double cross(Point a, Point b, Point c) { return cross(b - a, c - a); }

int sgn(double x) { return (0.0 < x) - (x < 0.0); }

double dot(Point v, Point w) { return v.x * w.x + v.y * w.y; }

bool onSegment(Point s, Point e, Point p) { return cross(p, s, e) == 0 && dot(s - p, e - p) <= 0; }

vector<Point> segInter(Point a, Point b, Point c, Point d) {
    auto oa = cross(c, d, a), ob = cross(c, d, b),
    oc = cross(a, b, c), od = cross(a, b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return {(a * ob - b * oa) / (ob - oa)};
    set<Point> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return {ALL(s)};
}

vector<vi> g;
vi colors;

bool dfs(int u, int color) {
    colors[u] = color;
    for (auto &v : g[u]) {
        if (colors[v] != -1) {
            if (colors[v] == color)
                return false;
            continue;
        }
        if (!dfs(v, color ^ 1))
            return false;
    }
    return true;
}

signed main () { __
    int w, p;
    cin >> w >> p;

    vector<Point> wells(w), endPoints(p);
    set<Point> st;
    FOR (i, 0, w) {
        cin >> wells[i].x >> wells[i].y;
        st.insert(wells[i]);
    }

    vector<pi> pipes(p);
    FOR (i, 0, p) {
        int a;
        cin >> a >> endPoints[i].x >> endPoints[i].y;
        pipes[i] = {a - 1, i};
    }

    g.assign(p, vi());

    FOR(i, 0, p) {
        FOR (j, i + 1, p) {
            vector<Point> inter = segInter(wells[pipes[i].first], endPoints[pipes[i].second], wells[pipes[j].first], endPoints[pipes[j].second]);
            if (inter.empty() || st.count(inter[0]))
                continue;
            g[i].pb(j);
            g[j].pb(i);
        }
    }

    colors.assign(p, -1);
    
    bool flag = true;

    FOR (i, 0, p) {
        if (colors[i] == -1)
            flag &= dfs(i, 0);
    }

    cout << (flag ? "possible" : "impossible") << ENDL;

    return 0;
}