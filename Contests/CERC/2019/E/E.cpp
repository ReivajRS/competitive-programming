#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

typedef double T;
double EPS = 1e-6;

int sgn(T x) {return (T(0)<x)-(x<T(0));}

struct Point{
  T x,y;
  Point operator+(Point p) const {return {x+p.x,y+p.y};}
  Point operator-(Point p) const {return {x-p.x,y-p.y};}

  Point operator+(T d) const {return {x+d,y+d};}
  Point operator*(T d) const {return {x*d,y*d};}
  Point operator/(T d) const {return {x/d,y/d};}

  bool operator<(Point p)const {return (x<p.x - EPS || (abs(x-p.x)<=EPS && y<p.y-EPS));}

  T cross(Point p) const {return x*p.y - y*p.x;}
  T sq() {return x*x+y*y;}
  double norm() {return sqrt(sq());}
  Point perp() { return {-y,x};}
};

struct Line {
  Point v;
  T c;
  Line(Point p,Point q) : v(q-p),c(v.cross(p)){}

  T side(Point p){return v.cross(p)-c;}

  double sqDist(Point p) {return side(p)*side(p)/(double)v.sq();} 
  Point proj(Point p) { return p-v.perp()*side(p)/v.sq();}
};

int circleLine(Point o,double r,Line l, pair<Point,Point> &out){
  double h2 = r*r-l.sqDist(o);
  if(h2>=0){
    Point p = l.proj(o);
    Point h = l.v*sqrt(h2) /l.v.norm();
    out = {p-h,p+h};
  }
  return 1 + sgn(h2);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,r,a,b;
  cin >> n >> r >> a >> b;
  Line line({0,0},{a,b});
  vector<pair<Point,int>> events;
  FOR(i,0,n){
    double x,y;
    cin >> x >> y;
    pair<Point,Point> out;
    int inter = circleLine({x,y},r,line,out);
    if(!inter) continue;
    if(inter == 1){
      events.push_back({out.first,-1});
      events.push_back({out.first,+1});
    }else{
      Point a = out.first,b = out.second;
      if(b<a) swap(a,b);
      events.push_back({a,-1});
      events.push_back({b,+1});
    }
  }
  sort(events.begin(),events.end());
  int ans = 0;
  int curr = 0;
  for(auto &[_,plus]:events){
    //cout << _ << " " << plus << ENDL;
    curr-=plus;
    ans = max(ans,curr);
  }
  cout << ans << ENDL;
  
  return 0;
}