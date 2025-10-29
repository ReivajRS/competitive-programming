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

struct point {
    double x, y;
    point() : x(0.0), y(0.0) {}
    bool operator==(const point &o) { return x == o.x && y == o.y; }
};

int main() {_
    int X, Y, n;
    cin >> X >> Y >> n;

    vector<point> pts(n);

    FOR(i, 0, n)
        cin >> pts[i].x >> pts[i].y;

    // Left or top
    auto is_red = [&](point &p, double r) -> bool {
        return X - p.x <= r || p.y <= r;
    };

    // Right or bottom
    auto is_blue = [&](point &p, double r) -> bool {
        return p.x <= r || Y - p.y <= r;
    };

    auto intersects = [&](point &p1, point &p2, double r) -> bool {
        return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) <= 4.0 * r * r;
    };

    auto check = [&](double r) {
        queue<point> q;
        vector<bool> visited(n, false);

        FOR (i, 0, n) {
            if (is_red(pts[i], r)) {
                if (is_blue(pts[i], r))
                    return false;
                q.push(pts[i]);
                visited[i] = true;
            }
        }

        while (!q.empty()) {
            point p1 = q.front();
            q.pop();

            FOR (i, 0, n) {
                point p2 = pts[i];
                if (p1 == p2 || visited[i] || !intersects(p1, p2, r))
                    continue;
                if (is_blue(p2, r))
                    return false;
                q.push(p2);
                visited[i] = true;
            }
        }

        return true;
    };

    double l = 0.0, r = min(X, Y);

    FOR (i, 0, 70) {
        double mid = l + (r - l) / 2.0;

        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << setprecision(6) << fixed << l << ENDL;

    return 0;
}