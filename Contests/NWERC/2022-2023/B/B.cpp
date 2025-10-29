#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

long double h,r,da,dw;

long double solve(long double hw){
  long double ha = h-hw;
  long double m1 = dw*hw;
  long double m2 = da*ha;
  long double cw = hw/2;
  long double ca = h - (ha/2);
  long double cm = (m1*cw+m2*ca) / (m1+m2);
  return cm;
}

signed main() { __

  cin >> h >> r >> da >> dw;

  long double l = 0, r = 1000;
  FOR(i,0,500){
    long double m1 = l + (r-l)/3;
    long double m2 = r - (r-l)/3;
    long double f1 = solve(m1);
    long double f2 = solve(m2);
    if(f1 > f2){
      l = m1;
    }else{
      r = m2;
    }
  }
  cout << setprecision(8) << fixed;
  cout << solve(l) << ENDL;
  
  return 0;
}