#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

struct Frac {
  ll a, b;
  Frac() {}
  Frac(ll _a, ll _b) {
    //assert(_b > 0);
    if ((_a < 0 && _b < 0) || (_a > 0 && _b < 0)) {
      _a = -_a;
      _b = -_b;
    }

    ll GCD = gcd(abs(_a), abs(_b));

    a = _a / GCD;
    b = _b / GCD;
  }
  Frac operator+(Frac other) const {
    ll sup = a * other.b + b * other.a, inf = b * other.b;
    return Frac(sup, inf);
  }
  Frac operator-(Frac other) const {
    ll sup = a * other.b - b * other.a, inf = b * other.b;
    return Frac(sup, inf);
  }
};

signed main() { __
  ll n;
  cin >> n;
  
  vi h(n);
  for (auto &x : h)
    cin >> x;
  
  Frac ans(0,1);
  FOR (it, 0, 2) {
    stack<pi> st;
    while(SZ(st))st.pop();
    FOR (i, 0, n) {
      while(!st.empty() && st.top().first < h[i]) st.pop();
      if((i && h[i] < h[i - 1]) || !SZ(st)) {
        if (i)
          st.push({h[i - 1], i-1});
        continue;
      }

      pi x = st.top();
      int idxL = x.second;
      int idxR = i;

      // cout << x.first << " " << h[i] << ENDL;
      Frac fraccion(h[idxL]-h[idxR],h[idxL]-h[idxL+1]);
      fraccion = fraccion+(Frac(idxL,1));
      fraccion = Frac(idxR,1)-fraccion;
    
      //fraccion = fraccion+(Frac(idxR - idxL - 1,1));
      ll aux = fraccion.a/fraccion.b;
      ll res = fraccion.a%fraccion.b;
      if(aux>ll(ans.a/ans.b) || (aux == ll(ans.a/ans.b) && res > ans.a%ans.b)){
        ans = fraccion;
      }

      if (i)
        st.push({h[i - 1], i-1});
    }
    reverse(ALL(h));
  }

  if(ans.b == 1){
    cout << ans.a << ENDL;
    return 0;
  }
  cout << ans.a << "/" << ans.b << ENDL;

  return 0;
}