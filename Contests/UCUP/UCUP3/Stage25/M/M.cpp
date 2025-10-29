#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ENDL '\n'

using ll = long long;

template<class T>
struct SparseTable {
  vector<vector<T>> jmp;
  void init(const vector<T>& V) {
    if (SZ(jmp)) jmp.clear();
    jmp.emplace_back(V);
    for (ll pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
      jmp.emplace_back(SZ(V) - pw * 2 + 1);
      FOR (j, 0, SZ(jmp[k]))
        jmp[k][j] = gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(ll l, ll r) { // [a, b)
    ll dep = 63 - __builtin_clzll(r - l);
    return gcd(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

bool can(ll x, vector<ll> a, vector<ll>& leftMin, vector<ll>& rightMin) {
  // cout << x << ENDL;
  for (ll& y : a) {
    y += x;
  }

  ll n = (ll)a.size();

  SparseTable<ll> spt;
  spt.init(a);

  for (ll i = 0; i < n; ++i) {
    if (gcd(spt.query(leftMin[i] + 1, i + 1), spt.query(i, rightMin[i])) != a[i]) {
      return false;
    }
  }
  return true;
}

void solve(){
  ll n,k;
  cin >> n >> k;
  vector<bool> xd(2);
  vector<ll> a(n);
  set<ll> settt;
  ll mn = 1e15;
  FOR(i,0,n) {
    cin >> a[i];
    mn = min(mn, a[i]);
    settt.insert(a[i]);
  }
  if(SZ(settt) == 1){
    cout << k << " " << (ll)k*(k+1)/2 << ENDL;
    return;
  }



  ll g = 0;
  FOR(i,1,n) {
    g = gcd(g, abs(a[i] - a[i-1]));
  }
  // cout << g << '\n';

  vector<ll> leftMin(n);
  stack<ll> st;
  for (ll i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] > a[i]) {
      st.pop();
    }
    leftMin[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }

  while (!st.empty()) {
    st.pop();
  }

  vector<ll> rightMin(n);
  for (ll i = n - 1; i >= 0; --i) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      st.pop();
    }
    rightMin[i] = st.empty() ? n : st.top();
    st.push(i);
  }

  // for (ll x : leftMin) {
  //   cout << x << ' ';
  // }
  // cout << ENDL;
  // for (ll x : leftMin) {
  //   cout << x << ' ';
  // }
  // cout << ENDL;


  // cout << mn << ' ' << g << '\n';

  vector<ll> v;
  v.push_back(1);
  for (ll i = 2; i * i <= g; ++i) {
    if (g % i == 0) {
      v.push_back(i);
      if (i != g / i) {
        v.push_back(g / i);
      }
    }
  }
  v.push_back(g);

  ll valid = 0, suma = 0;
  for (ll d : v) {
    // cout << d << ' ';
    if (d > mn && can(d - mn, a, leftMin, rightMin)) {
      ++valid;
      suma += d - mn;
    }
  }
  cout << valid << ' ' << suma << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while(t--) solve();

  return 0;
}