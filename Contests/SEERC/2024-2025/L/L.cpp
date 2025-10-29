#include <bits/stdc++.h>
using namespace std;

using ll =  long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

struct FT {
  vector<int> s;
  FT(int n) : s(n + 1) {}
  void update(int pos, int dif) {
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  int query(int pos) {
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n);
  vi pos(n);
  FOR(i,0,n){
    cin >> a[i];
    a[i]--;
    pos[a[i]] = i;
  }
  int N = n-1;
  for(int i = n-1;i>=0;i--){
    if(a[i] == N){
      N--;
    }
  }
  vector<pair<int,int>> ans;
  FT bit(n+5);
  for(int i=N;i>=0;i--){
    int aux = bit.query(n+1) - bit.query(pos[i]);
    ans.push_back({pos[i]+1+aux,1});
    bit.update(pos[i],1);
  }

  cout << SZ(ans) << " " << SZ(ans) << ENDL;
  for(auto [x,y]:ans){
    cout << x << " " << y << ENDL;
  }

  return 0;
}