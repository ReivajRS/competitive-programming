#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

template<class T>
struct SparseTable{
  vector<vector<T>> jmp;
  void init(const vector<T>& V){
    if(SZ(jmp)) jmp.clear();
    jmp.emplace_back(V);
    for(int pw = 1,k=1;pw*2<=SZ(V);pw*=2,k++){
      jmp.emplace_back(SZ(V)-pw*2+1);
      FOR(j,0,SZ(jmp[k]))
        jmp[k][j] = max(jmp[k-1][j],jmp[k-1][j+pw]);
    }
  }
  T query(int l,int r){
    if(l == r) return 0;
    int dep = 31-__builtin_clz(r-l);
    return max(jmp[dep][l],jmp[dep][r-(1<<dep)]);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n*3);
  int mx = 0;
  FOR(i,0,n){
    cin >> a[i];
    a[i+n] = a[i];
    a[i+n*2] = a[i];
    mx = max(mx,a[i]);
  }

  auto check = [&]() -> bool {
    FOR(i,0,n){
      if(a[i]*2<mx) return false;
    }
    return true;
  };

  if(check()){
    FOR(i,0,n) cout << "-1 ";
    return 0;
  }
  SparseTable<int> st;
  st.init(a);
  int j=0;
  
  FOR(i,0,n){
    while(j<=SZ(a) && a[j]*2 >= st.query(i,j)) j++;

    cout << j-i << " ";
  }


  return 0;
}