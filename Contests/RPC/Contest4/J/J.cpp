#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (int)a;i<(int)b;++i)

typedef ll T;

struct Point{
  T x, y;
  Point operator-(Point p) const {return {x - p.x, y - p.y};}
  T cross(Point p) const {return x * p.y - y * p.x;}
};

double area(vector<Point> &p){
  double area = 0;
  int n = SZ(p);
  FOR(i,0,n){
    area += p[i].cross(p[(i+1)%n]);
  }
  return abs(area)/2.0;
}

signed main() {

  int n;
  cin >> n;
  vector<Point> pts(n);
  FOR(i,0,n){
    cin >> pts[i].x >> pts[i].y;
  }


  auto solve = [&](int a,int b) -> double {
    vector<Point> poly1;
    vector<Point> poly2;
    FOR(i,0,a+1){
      poly1.pb(pts[i]);
    }
    FOR(i,b,n){
      poly1.pb(pts[i]);
    }

    double area1 = area(poly1);
    FOR(i,a,b+1){
      poly2.pb(pts[i]);
    }
    double area2 = area(poly2);

    return abs(area1-area2);
  };

  double ans = 3e8;
  FOR(i,0,n){
    FOR(j,i+2,n-(i==0)){
      ans = min(ans,solve(i,j));
    }
  }

  cout << setprecision(1) << fixed;
  cout << ans << '\n';
  
  return 0;
}