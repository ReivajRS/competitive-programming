#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct DSU {
  vector<int> e;
  void init(int n) { e = vi(n, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  s+=s;
  string t = "";
  FOR(i,0,m){
    string t2;
    cin >> t2;
    t+=t2+"#";
  }
  hashing h1(s);
  hashing h2(t);

  auto can = [&](int x) -> bool{
    unordered_set<ll> st;
    FOR(i,0,SZ(t)-x+1){
      st.insert(h2.value(i,i+x));
    }
    int last = -1;
    FOR(i,0,n*2 - x+1){
      if(st.count(h1.value(i,i+x))) last = i;
      if(i+x-last > n) return 0;
    }
    return 1;
  };
  

  int l = 0,r = n;
  while(l<r){
    int mid = (l+r+1)/2;
    if(can(mid)){
      l = mid;
    }else{
      r = mid-1;
    }
  }
  cout << l << '\n';
  

  return 0;
}