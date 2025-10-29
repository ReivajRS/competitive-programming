#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

using ld = long double;

struct Point{

  ld x,y;
  Point operator+(Point p) const{ return {x+p.x,y+p.y};}
  Point operator-(Point p) const{ return {x-p.x,y-p.y};}

  Point operator*(ld d) const {return {x*d,y*d};}
  Point operator/(ld d) const {return {x/d,y/d};}

  ld cross(Point p) const { return x*p.y - y*p.x;}
};

struct Line{
  Point v;
  ld c;
  Line(Point v,ld c) : v(v),c(c){}
  Line(Point p,Point q) : v(q-p),c(v.cross(p)){}
};

const ld EPS = 1e-9;

bool areIntersect(Line l1,Line l2,Point &p){
  ld d = l1.v.cross(l2.v);
  if(abs(d)<=EPS) return false;
  p = (l2.v*l1.c - l1.v * l2.c)/d;
  return true;
}

ld rot(ld ang,Point r,Point lamp){
  Point v = r-lamp;
  Point vec2 = {v.x * cos(ang) - v.y * sin(ang),v.x*sin(ang)+v.y*cos(ang)};
  Line l1 = Line(lamp,lamp+vec2);
  Line l2 = Line({0,0},{1,0});
  Point aqui;
  bool b = areIntersect(l1,l2,aqui);
  if(!b) return 1e18;
  if(r.x>aqui.x) return 1e18;
  return aqui.x-r.x;
}
const ld PI = acos(-1);
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, l, r;
  cin >> n >> l >> r;
  vector<ld> ang(n);
  vector<Point> a(n);
  FOR(i,0,n){
    cin >> a[i].x >> a[i].y >> ang[i];
    ang[i] = ang[i] * PI /180.0;
  }
  //cout << rot(PI/4,{0,0},{0,1}) << '\n';

  cout << setprecision(9) << fixed;

  vector<ld> dp(1 << n,-1e18);
  dp[0] = l;
  for (int msk = 0; msk < (1 << n); ++msk) {
    for (int i = 0; i < n; ++i) {
      if (!(msk >> i & 1)) {
        dp[msk | (1 << i)] = max(dp[msk | (1 << i)],min(dp[msk] + rot(ang[i],{dp[msk],0},a[i]),ld(r)));
      }
    }
  }
  cout << dp.back() - l << '\n';
  
  
  return 0;
}