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
    int x, y;
    point() { x = y = 0; }
    bool operator==(const point o) { return x == o.x && y == o.y; }
};

void solve() {
    int c, w, h;
    cin >> c >> w >> h;

    point pts[c];

    FOR (i, 0, c)
        cin >> pts[i].x >> pts[i].y;
    
    auto is_red = [&](point &p, double r) {
        return p.x <= r;
    };

    auto is_blue = [&](point &p, double r) {
        return w - p.x <= r;
    };

    auto intersects = [&](point &p1, point &p2, double r) {
        return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) <= 4 * r * r;
    };

    auto check = [&](double r) {
        queue<point> q;
        vector<bool> visited(c, false);

        FOR (i, 0, c) {
            if (is_red(pts[i], r)) {
                if (is_blue(pts[i], r))
                    return false;
                visited[i] = true;
                q.push(pts[i]);
            }
        }

        while (!q.empty()) {
            point p1 = q.front();
            q.pop();

            FOR (i, 0, c) {
                point p2 = pts[i];
                if (p1 == p2 || visited[i] || !intersects(p1, p2, r))
                    continue;
                if (is_blue(pts[i], r))
                    return false;
                visited[i] = true;
                q.push(p2);
            }
        }

        return true;
    };

    double l = 0.0, r = w;

    const double EPS = 0.1;

    while (r - l > EPS) {
        double mid = l + (r-l) / 2.0;

        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << (l <= 2 ? "RISKY" : "SAFE") << ENDL;
}

int main() {_
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}