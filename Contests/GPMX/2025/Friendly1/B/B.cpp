#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

typedef double T;
const double EPS = 1e-9;
const double INF = 1e16;

struct Point{
  T x,y;
  Point operator+(Point p) const {return {x+p.x,y+p.y};}
  Point operator-(Point p) const {return {x-p.x,y-p.y};}

  T dot(Point p) {return x*p.x + y*p.y;}
  T cross(Point p) const { return x*p.y - y*p.x;}

  Point operator*(T d) const {return {x*d,y*d};}
};

struct HalfPlane{
  Point p,pq;
  T angle;
  HalfPlane() {}
  HalfPlane(Point _p,Point _q) : p(_p), pq(_q-_p),angle(atan2(pq.y,pq.x)) {}
  bool operator<(HalfPlane b)const {return angle<b.angle;}
  bool out(Point q) {return pq.cross(q-p)<EPS;}
  Point intersect(HalfPlane l){
    if(abs(pq.cross(l.pq))<EPS) return Point{INF,INF};
    return l.p + l.pq * ((p-l.p).cross(pq)/l.pq.cross(pq));
  }
};

vector<Point> intersect(vector<HalfPlane> &b){
  vector<Point> bx = {Point{INF,INF},Point{-INF,INF},Point{-INF,-INF},Point{INF,-INF}};
  for(int i=0;i<4;i++) b.emplace_back(bx[i],bx[(i+1)%4]);
  sort(b.begin(),b.end());
  int n = SZ(b),q = 1,h = 0;
  vector<HalfPlane> c(b.size()+10);
  FOR(i,0,n){
    while(q<h && b[i].out(c[h].intersect(c[h-1]))) h--;
    while(q<h && b[i].out(c[q].intersect(c[q+1]))) q++;
    c[++h] = b[i];
    if(q<h && abs(c[h].pq.cross(c[h-1].pq)) < EPS) {
      if(c[h].pq.dot(c[h-1].pq)<=0) return {};
      h--;
      if(b[i].out(c[h].p)) c[h] = b[i];
    }
  }
  while(q<h-1 && c[q].out(c[h].intersect(c[h-1]))) h--;
  while(q<h-1 && c[h].out(c[q].intersect(c[q+1]))) q++;
  if(h-q<=1) return {};
  c[h+1] = c[q];
  vector<Point> s;
  for(int i=q;i<h+1;i++) s.push_back(c[i].intersect(c[i+1]));
  return s;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Point> a(n);
  FOR(i,0,n){
    cin >> a[i].x >> a[i].y;
  }
  vector<HalfPlane> b(n);
  FOR(i,0,n){
    b[i] = HalfPlane(a[i],a[(i-1+n)%n]);
  }

  vector<Point> res = intersect(b);
  double area = 0.0;
  int m = SZ(res);
  FOR(i,0,m){
    area += res[i].cross(res[(i+1)%m]);
  }
  cout << setprecision(9) << fixed;
  cout << abs(area)/2.0 << '\n';
  
  return 0;
}