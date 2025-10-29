#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
const double PI = acos(-1);
inline double RAD_TO_DEG(double r) {return r*180.0 / PI;}
typedef ll T;
struct Point{
  T x,y;

  Point operator+(Point p) const {return {x+p.x,y+p.y};}
  Point operator-(Point p) const {return {x-p.x,y-p.y};}

  double angle(){ return atan2(y,x);}
  Point perp() {return {-y,x};}
  T cross(Point p) const {return x*p.y-y*p.x;}
  T cross(Point a,Point b) const {return (a-*this).cross(b-*this);}
};


T orient(Point a,Point b,Point c){
  return a.cross(b,c);
}

void solve(){
  int n,q;
  cin >> n >> q;
  vector<Point> pts(n);
  FOR(i,0,n){
    cin >> pts[i].x >> pts[i].y;
  }

  vector<vector<double>> ang(n);
  FOR(i,0,n){
    FOR(j,0,n){
      if(i == j) continue;
      Point v = pts[j]-pts[i];
      double x = v.angle();
      if(x<0) x+=2*PI;
      ang[i].push_back(x);
      ang[i].push_back(x+2*PI);
    }
    sort(ang[i].begin(),ang[i].end());
  }
  while(q--){
    int a,b,c;
    cin >> a >> b >> c;
    a--,b--,c--;
    if(orient(pts[a],pts[b],pts[c]) < 0){
      swap(a,c);
    }
    // AC
    double angAC = (pts[c]-pts[a]).angle();
    if(angAC < 0 ) angAC+=2*PI;
    double angBA = (pts[a]-pts[b]).angle();
    if(angBA < 0 ) angBA+=2*PI;
    if(angBA < angAC) angBA+=2*PI;

    int cntAC = lower_bound(ang[a].begin(),ang[a].end(),angBA) -lower_bound(ang[a].begin(),ang[a].end(),angAC);

    // AB
    angBA = (pts[a]-pts[b]).angle();
    if(angBA < 0 ) angBA+=2*PI;
    double angCB = (pts[b]-pts[c]).angle();
    if(angCB < 0) angCB+=2*PI;
    if(angCB < angBA) angCB += 2*PI;

    int cntAB = lower_bound(ang[b].begin(),ang[b].end(),angCB) -lower_bound(ang[b].begin(),ang[b].end(),angBA);

    //BC
    angCB = (pts[b]-pts[c]).angle();
    if(angCB < 0) angCB+=2*PI;
    angAC = (pts[c]-pts[a]).angle();
    if(angAC < 0) angAC+=2*PI;
    if(angAC < angCB) angAC += 2*PI;

    int cntBC = lower_bound(ang[c].begin(),ang[c].end(),angAC) -lower_bound(ang[c].begin(),ang[c].end(),angCB);

    if(cntAB+cntAC+cntBC == n){
      cout << "YES" << '\n';
    }else{
      cout << "NO" << '\n';
    }
  }


}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int z;
  cin >> z;
  while(z--) solve();
  
  return 0;
}