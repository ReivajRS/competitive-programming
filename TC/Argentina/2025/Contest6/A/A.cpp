#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

typedef double T;
struct Point{
  T x,y;

  Point operator+(Point p) const {return {x+p.x,y+p.y};}
  Point operator-(Point p) const {return {x-p.x,y-p.y};}

  Point operator*(T d) const {return {x*d,y*d};}
  Point operator/(T d) const {return {x/d,y/d};}

  T sq() { return x*x+y*y;}
  double norm(){return sqrt(sq());}

  Point perp() { return {-y,x};}

  T cross(Point p) const { return x*p.y - y*p.x;}
};

Point circumCenter(Point A,Point B,Point C){
  Point b = C-A,c = B-A;
  return A + (b*c.sq()-c*b.sq()).perp() / b.cross(c) / 2;
}

pair<Point,double> mec(vector<Point> pts){
  shuffle(pts.begin(),pts.end(), mt19937(time(0)));
  Point o = pts[0];
  double r = 0,EPS = 1+1e-8;
  FOR(i,0,SZ(pts)) if((o-pts[i]).norm() > r * EPS){
    o = pts[i],r = 0;
    FOR(j,0,i) if((o-pts[j]).norm()>r*EPS){
      o = (pts[i]+pts[j])/2;
      r = (o-pts[i]).norm();
      FOR(k,0,j) if((o-pts[k]).norm()>r * EPS){
        o = circumCenter(pts[i],pts[j],pts[k]);
        r = (o-pts[i]).norm();
      }
    }
  }
  return {o,r};
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m;
  cin >> n;
  vector<Point> a(n);
  FOR(i,0,n) cin >> a[i].x >> a[i].y;
  cin >> m;
  vector<Point> b(m);
  FOR(i,0,m) cin >> b[i].x >> b[i].y;
  vector<Point> c;
  for(auto x:a){
    for(auto y:b){
      c.push_back(y-x);
    }
  }
  pair<Point,double> ans = mec(c);
  cout << setprecision(10) << fixed;
  cout << ans.second << " " << ans.first.x << " " << ans.first.y  << '\n';

  return 0;
}