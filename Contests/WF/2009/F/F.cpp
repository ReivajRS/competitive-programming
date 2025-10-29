#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

typedef ll T;
struct Point{
  T x,y;

  Point operator+(Point p) const { return {x+p.x,y+p.y};}
  Point operator-(Point p) const { return {x-p.x,y-p.y};}

  bool operator<(Point p) const { return tie(x,y)<tie(p.x,p.y);}
  bool operator==(Point p) const {return tie(x,y) == tie(p.x,p.y);}


  T cross(Point p) const {return x*p.y - y * p.x;}
  T cross(Point a,Point b) const { return (a-*this).cross(b-*this);}
};

vector<Point> convexHull(vector<Point> pts){
  if(SZ(pts)<=1) return pts;
  sort(pts.begin(),pts.end());
  vector<Point> h(SZ(pts)+1);
  int s = 0,t = 0;
  for(int it = 2;it--;s = --t, reverse(pts.begin(),pts.end()))
    for(Point p:pts){
      while(t>=s+2 && h[t-2].cross(h[t-1],p)<=0) t--;
      h[t++] = p;
    }
  return {h.begin(),h.begin()+t-(t==2 && h[0] == h[1])};
}

const double PI = acos(-1.0);

double dist(Point p1,Point p2){
  return hypot(p1.x-p2.x,p1.y-p2.y);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t=1;
  int n,m;
  while(cin >> n >> m && n){
    vector<Point> a(n);
    FOR(i,0,n){
      cin >> a[i].x >> a[i].y;
    }
    vector<double> dp(1<<n);
    FOR(msk,0,(1<<n)){
      vector<Point> currPoints;
      FOR(k,0,n){
        if((msk>>k)&1) currPoints.push_back(a[k]);
      }
      vector<Point> ch = convexHull(currPoints);
      dp[msk] = 2*PI * m;
      int nn = SZ(ch);
      FOR(i,0,nn){
        dp[msk] += dist(ch[i],ch[(i+1)%nn]);
      }
    }
    FOR(msk,0,(1<<n)){
      for(int submsk = msk;submsk; submsk = (submsk-1) & msk){
        dp[msk] = min(dp[msk],dp[submsk] + dp[msk xor submsk]);
      }
    }
    cout << setprecision(2) << fixed;
    cout << "Case " << t++ << ": length = ";
    cout << dp[(1<<n)-1] << '\n';
  }
  
  

  return 0;
}