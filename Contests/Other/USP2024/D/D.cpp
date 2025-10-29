#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct P3{
  ld x,y,z;
};

ld dist(P3 p1,P3 p2){
  return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) + (p1.z-p2.z)* (p1.z-p2.z);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ld x,y,z,r;
  cin >> x >> y >> z;
  P3 apple;
  cin >> apple.x >> apple.y >> apple.z;
  cin >> r;
  apple.x = min(apple.x,x-apple.x),apple.y = min(apple.y,y-apple.y),apple.z = min(apple.z,z-apple.z);

  ld low = 0,high = min({x/2,y/2,z/2});
  FOR(i,0,100000){
    ld r2 = (low+high)/2;
    P3 apple2 = {x-r2,y-r2,z-r2};
    ld d = dist(apple,apple2);
    if(d>=(r+r2)*(r+r2)) low = r2;
    else high = r2;
  }
  cout << setprecision(15) << fixed;
  cout << low << '\n';

  return 0;
}