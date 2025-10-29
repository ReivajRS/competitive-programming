#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

typedef ll T;
struct Point{
  T x,y;

  Point operator+(Point p) const {return {x+p.x,y+p.y};}
  Point operator-(Point p) const {return {x-p.x,y-p.y};}

  Point operator*(T d) const {return {x*d,y*d};}
  Point operator/(T d) const {return {x/d,y/d};}

  bool operator<(Point p) const {return tie(x,y)< tie(p.x,p.y);}
  bool operator==(Point p) const {return tie(x,y) == tie(p.x,p.y);}

  T sq() { return x*x+y*y;}


  Point perp() { return {-y,x};}

  T cross(Point p) const { return x*p.y - y*p.x;}
  T cross(Point a,Point b) const { return (a-*this).cross(b-*this);}
};

vector<Point> convexHull(vector<Point> pts){
  if(SZ(pts)<=1) return pts;
  sort(pts.begin(),pts.end());
  vector<Point> h(SZ(pts)+1);
  int s = 0,t = 0;
  for(int it= 2;it--;s=--t, reverse(pts.begin(),pts.end()))
    for(Point p:pts){
      while(t>=s+2 && h[t-2].cross(h[t-1],p) <= 0) t--;
      h[t++] = p;
    }
  return {h.begin(),h.begin()+t - (t==2 && h[0] == h[1])};
}

ll areaTriangle(Point a,Point b,Point c){
  return abs((b-a).cross(c-a));
}

ll areaPolygon(vector<Point> &p){
  ll area = 0;
  int n = SZ(p);
  FOR(i,0,n){
    area += p[i].cross(p[(i+1)%n]);
  }
  return area;
}

void solve(){
  int n;
  cin >> n;
  vector<Point> pts(n);
  FOR(i,0,n) cin >> pts[i].x >> pts[i].y;
  vector<Point> ch1 = convexHull(pts);
  set<Point> eliminar;
  for(auto p:ch1) eliminar.insert(p);
  vector<Point> pts2;
  for(auto p:pts){
    if(!eliminar.count(p)) pts2.push_back(p);
  }
  vector<Point> ch2 = convexHull(pts2);
  int m = SZ(ch2);
  if(m == 0){
    cout << -1 << '\n';
    return;
  }
  ll mnArea = 9e18,best=-1;
  FOR(i,0,m){
    ll area = areaTriangle(ch1[0],ch1[1],ch2[i]);
    if(area < mnArea) {
      mnArea = area;
      best = i;
    }
  }
  n = SZ(ch1);
  ll areaTotal = areaPolygon(ch1);
  ll ans = areaTotal - areaTriangle(ch1[0],ch1[1],ch2[best]);
  FOR(i,1,n){
    ll curr = areaTriangle(ch1[i],ch1[(i+1)%n],ch2[best]);
    while(true) {
      ll aux = areaTriangle(ch1[i],ch1[(i+1)%n],ch2[(best+1)%m]);
      if (aux >= curr) {
        break;
      }
      curr = aux;
      (best+=1)%=m;
    }
    ans = max(ans,areaTotal - curr);
  }
  cout << ans << '\n';

}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}