#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

typedef ll T;
struct Point {
  T x, y;

  Point operator-(Point p) const { return {x - p.x, y - p.y}; }

   Point operator*(T d) const { return {x * d, y * d}; }

  T dot(Point p) { return x * p.x + y * p.y; }
  T sq() { return x * x + y * y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  Point perp() {return {-y,x};}
};

ll dist(Point p1, Point p2) {
  return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}


struct Line{
  Point v;
  T c;
  Line(Point p,Point q) : v(q-p),c(v.cross(p)){}

  T side(Point p){return v.cross(p)-c;}
};

bool areParallel(Line l1,Line l2){return (l1.v.cross(l2.v) == 0);}



signed main() { __
  vector<Point> pts(4);
  
  FOR(i, 0, 4) {
    cin >> pts[i].x >> pts[i].y;
  }

  bool isEqualSide = (dist(pts[0], pts[1]) == dist(pts[1],pts[2]) && dist(pts[0],pts[1]) == dist(pts[2],pts[3]) && dist(pts[0],pts[1]) == dist(pts[3],pts[0]));
  bool isEqualAngle = ((pts[3]-pts[0]).dot(pts[1]-pts[0]) == 0 && (pts[0]-pts[1]).dot(pts[2]-pts[1]) == 0 && (pts[3]-pts[2]).dot(pts[1]-pts[2]) == 0);

  // Square or rectangle
  if(isEqualAngle){
    if(isEqualSide) cout << "square" << ENDL;
    else cout << "rectangle" << ENDL;
    return 0;
  }
  if(isEqualSide){
    cout << "rhombus" << ENDL;
    return 0;
  }

  Line l1 = Line(pts[0],pts[1]);
  Line l2 = Line(pts[1],pts[2]);
  Line l3 = Line(pts[2],pts[3]);
  Line l4 = Line(pts[3],pts[0]);

  int cnt = 0;
  cnt += areParallel(l1,l2);
  cnt += areParallel(l1,l3);
  cnt += areParallel(l1,l4);

  cnt += areParallel(l2,l3);
  cnt += areParallel(l2,l4);

  cnt += areParallel(l3,l4);

  if(cnt == 2){
    cout << "parallelogram" << ENDL;
    return 0;
  }
  if(cnt == 1){
    cout << "trapezium" << ENDL;
    return 0;
  }

  //kite
  ll ab = dist(pts[0],pts[1]);
  ll ad = dist(pts[0],pts[3]);
  ll cd = dist(pts[2],pts[3]);
  ll bc = dist(pts[1],pts[2]);

  if((ab == ad && bc == cd) || (ab == bc && ad == cd)){
    cout << "kite" << ENDL;
    return 0;
  }


  cout << "none" << ENDL;

  return 0;
}