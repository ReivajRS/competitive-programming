#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)b - 1; i >= (int)a; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

ld EPS = 1e-8;

using T = long double;
struct Point {
  ll x, y;

  Point operator-(Point p) const { return {x - p.x, y - p.y}; }

  bool operator==(Point p) const { return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS; }
  bool operator!=(Point p) const { return !(*this == p); }

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }

  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }


};

struct Line {
  Point v;
  T c;

  Line(Point p, Point q) : v(q - p), c(v.cross(p)) {

  }

  T side(Point p) { return v.cross(p) - c; }
  double dist(Point p) { return abs(side(p)) / v.norm(); }

  bool cmpProj(Point p, Point q) {
    return v.dot(p) < v.dot(q);
  }
};

double segPoint(Point a, Point b, Point p) {
  if (a != b) {
    Line l(a, b);
    if (l.cmpProj(a, p) && l.cmpProj(p, b)) {
      return l.dist(p);
    }
  }
  return min((p - a).norm(), (p - b).norm());
}

double segSeg(Point a, Point b, Point c, Point d) {
  Point dummy;
  return min({segPoint(a, b, c), segPoint(a, b, d),
              segPoint(c, d, a), segPoint(c, d, b)});
}

struct Circle{
  Point p;
  ll r;
};

signed main() { __

  int c,q,t;
  cin >> c >> q >> t;
  vector<Circle> circulos(c);
  FOR(i,0,c){
    ll x,y,r;
    cin >> x >> y >> r;
    circulos[i] = Circle({{x,y},r});
  }
  FOR(i,0,q){
    Point pt1,pt2;
    cin >> pt1.x >> pt1.y >> pt2.x >> pt2.y;

  }

  vector<vector<Point>> triangulos(t);
  FOR(i,0,t){
    FOR(j,0,3){
      ll x,y;
      cin >> x >> y;
      triangulos[i].pb({x,y});
    }
  }

  FOR(i,0,q){
    FOR(j,0,c){
      
    }
  }
  
  return 0;
}