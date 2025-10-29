#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct Point{
  long double x,y;
};

long double dist(Point a,Point b){
  return hypot(a.x-b.x,a.y-b.y);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<Point> b,g;
  FOR(i,0,n){
    Point p;
    cin >> p.x >> p.y;
    if(s[i] == 'B') b.push_back(p);
    else g.push_back(p);
  }
  long double ans = 0;
  int n1 = SZ(b);
  FOR(i,0,n1/2){
    ans += dist(b[i],b[i+ n1/2]);
  }
  int n2 = SZ(g);
  FOR(i,0,n2/2){
    ans += dist(g[i],g[i+ n2/2]);
  }
  cout << setprecision(12) << fixed;
  cout << ans << '\n';

  return 0;
}