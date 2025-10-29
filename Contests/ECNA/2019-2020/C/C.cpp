#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

using ld = long double;
using vd = vector<ld>;
ld eps = 1e-9;
int inf = 1e9;

vi X, Y;
ld Z; 
int n, m;
vd b, c;  // Cantidades, costos
vector<vd> a;  // Variables, restricciones
void pivot(int x, int y){
  swap(X[y], Y[x]);
  b[x] /= a[x][y];
  FOR(j,0, m) if(j != y) a[x][j] /= a[x][y];
  a[x][y] = 1 / a[x][y];
  FOR(i,0, n) if(i != x && abs(a[i][y]) > eps){
    b[i] -= a[i][y] * b[x];
    FOR(j,0, m) if(j != y) a[i][j] -= a[i][y] * a[x][j];
    a[i][y] = -a[i][y] * a[x][y];
  }
  Z += c[y] * b[x];
  FOR(j,0, m) if(j != y) c[j] -= c[y] * a[x][j];
  c[y] = -c[y] * a[x][y];
}

pair<ld, vd> simplex(){  // maximizar Z = c * x dado ax <= b, x_i >= 0
  X.resize(m),  iota(ALL(X), 0);
  Y.resize(n),  iota(ALL(Y), m);
  while(1){
    int x = min_element(ALL(b)) - b.begin(), y = -1;
    if(b[x] > -eps) break; 
    FOR(j,0, m) if(a[x][j] < -eps){ y = j; break; }
    if(y == -1) return {-1, {}}; // no solution to Ax<=b
    pivot(x, y);
  }
  while(1){
    int x = -1, y = max_element(ALL(c)) - c.begin();
    if(c[y] < eps) break; 
    ld mn = inf;
    FOR(i,0, n) if(a[i][y] > eps && b[i] / a[i][y] < mn) mn = b[i] / a[i][y], x = i;
    if(x == -1) return {inf, {}};   // c^T x is unbounded
    pivot(x, y);
  }
  vd ans(m);
  FOR(i,0, n) if(Y[i] < m) ans[Y[i]] = b[i];
  return {Z, ans};
}

signed main() { __

  cin >> m >> n;
  c.resize(m);b.resize(n);
  a.assign(n,vd(m));
  FOR(i,0,n){
    cin >> c[i];
  }
  FOR(i,0,n){
    FOR(j,0,m+1){
      if(j == m) cin >> b[i];
      else {cin >> a[i][j]; a[i][j]/=100;}
    }
  }
  pair<ld, vd> ans = simplex();

  for(auto xx:ans.second){
    cout << xx << ENDL;
  }

  cout << setprecision(2) << fixed;
  cout << ans.first << ENDL;

  return 0;
}