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

  bool operator<(Point other) const {
    return tie(x,y) < tie(other.x,other.y);
  }

};

double areaTriangle(Point a, Point b, Point c) {
  return abs((b - a).cross(c - a)) / 2.0;
}

int n, cnt = 0;
double ans = 3e8;
vector<Point> pts;
vector<vector<Point>> grupos;
set<vector<vector<Point>>> st;

double solve2(){
  double mx = 0,mn = 3e8;
  FOR(i,0,n){
    if (SZ(grupos[i]) != 3) continue;
    double area = areaTriangle(grupos[i][0],grupos[i][1],grupos[i][2]);
    mx = max(mx,area);
    mn = min(mn,area);
  }
  return mx-mn;
}

void solve(int curr){
  if (solve2() > ans) return;
  
  cnt++;
  if(curr == 3*n){
    ans = min(ans,solve2());
    return;
  }

  //if(st.count(grupos)) return;
  //st.insert(grupos);

  FOR(i,0,n){
    if (SZ(grupos[i]) == 3) continue;
    
    grupos[i].pb(pts[curr]);
    solve(curr+1); 
    grupos[i].pop_back();
  }
}

signed main() {
  cin >> n;
  pts.resize(3*n);
  FOR (i, 0, 3*n) {
    cin >> pts[i].x >> pts[i].y;
  }
  grupos.assign(n,vector<Point>());

  solve(0);
  
  
  cout << setprecision(1) << fixed;
  cout << ans << '\n';

  return 0;
}