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

struct plan {
    char move;
    int meters;
    string rgb;
    plan(char _move, int _meters, string _rgb) : move(_move), meters(_meters), rgb(_rgb) {}
};

vector<plan> plans;
unordered_map<char, pi> moves = {{'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}};
unordered_map<int, char> directions = {{0, 'R'}, {1, 'D'}, {2, 'L'}, {3, 'U'}};

struct point {
    ll x, y;
    point(ll _x, ll _y) : x(_x), y(_y) {}
};

double area(const vector<point> &P) {
    double ans = 0.0;
    for (int i = 0; i < (int)P.size()-1; ++i)
        ans += (P[i].x*P[i+1].y - P[i+1].x*P[i].y);
    return fabs(ans)/2.0;
}

ll getAns() {
    int y = 0, x = 0;

    vector<point> pts;
    pts.pb({x, y});

    ll i, b = 0;

    for (plan p : plans) {
        b += p.meters;
        switch (p.move) {
            case 'U':
                y -= p.meters;
                pts.pb({x, y});
                break;
            case 'R':
                x += p.meters;
                pts.pb({x, y});
                break;
            case 'D':
                y += p.meters;
                pts.pb({x, y});
                break;
            case 'L':
                x -= p.meters;
                pts.pb({x, y});
                break;
        }
    }

    i = area(pts) - (b/2) + 1;

    return i + b;
}

string part1() {
    return to_string(getAns());
}

string part2() {
    for (plan &p : plans) {
        stringstream ss(p.rgb.substr(1, 5));
        ss >> hex >> p.meters;
        p.move = directions[p.rgb.back() - '0'];
    }

    return to_string(getAns());
}

// Shoelace formula to get the area of the polygon

// Pick's theorem
// A = i + (b/2) - 1;
// Where:
// A = Area of the polygon
// i = Interior points of the polygon
// b = Boundary points of the polygon

// i = A - (b/2) + 1

// answer = i + b

int main() {_
    char move;
    int meters;
    string rgb;

    while (cin >> move >> meters >> rgb) {
        plans.pb({move, meters, rgb.substr(1, 7)});
    }

    cout << "Part 1: " << part1() << ENDL;
    cout << "Part 2: " << part2() << ENDL;

    return 0;
}