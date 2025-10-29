#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;

#define SZ(x) (int)(x.size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

struct Point {
    double x, y;
};
double EPS = 1e-7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    double X, Y;
    cin >> X >> Y;

    int n;
    cin >> n;
    vector<Point> points(n);
    FOR (i, 0, n) {
        cin >> points[i].x >> points[i].y;
    }

    auto is_red = [&](Point p, double r) -> bool {
        return X - p.x <= r || p.y <= r;
    };

    auto is_blue = [&](Point p, double r) -> bool {
        return p.x <= r || Y - p.y <= r;
    };

    auto are_adyascent = [&](Point p1, Point p2, double r) -> bool {
        double sq1 = (p1.x - p2.x) * (p1.x - p2.x), sq2 = (p1.y - p2.y) * (p1.y - p2.y); 
        double dist = sq1+sq2;
        double dist2 = 4.0*r*r;
        //cout << dist << " " << dist2 << ENDL;
        return dist < dist2;
    };

    //cout << are_adyascent(points[0],points[1],2.25) << ENDL;

    auto can = [&](double r) -> bool { 
        queue<Point> q;
        bool vis[n];
        FOR (i, 0, n) {
            vis[i] = 0;
            if (is_red(points[i], r)) {
                if (is_blue(points[i], r))
                    return false;
                vis[i] = 1;
                q.push(points[i]);
            }
        }
        while (!q.empty()) {
            Point p = q.front();
            q.pop();

            FOR (i, 0, n) {
                Point p2 = points[i];
                if (!(p.x == p2.x && p.y == p2.y) && !vis[i] && are_adyascent(p, p2, r)) {
                    if (is_blue(p2, r))
                        return false;
                    q.push(p2);
                    vis[i] = 1; 
                }
            }
        }
        return true;
    };

    double l = 0, r = min(X, Y)+10;
    FOR (itr, 0, 200) {
        double mid = l + (r - l) / 2.0;
        if (can(mid)) {
            l = mid;
        }   
        else {
            r = mid;
        }    
    }
    //cout << can(2.25) << ENDL;
    cout << setprecision(7) << fixed << l << ENDL;
}