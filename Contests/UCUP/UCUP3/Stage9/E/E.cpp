#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<bitset<5005>> f(n);
  vector<int> grados(n,0);
  for(int i=0;i<n;i++){
    f[i][i] = 1;
    for(int j = 0;j<n;j++){
      char c;
      cin >> c;
      if(c == '1'){
        f[i][j] = 1;
        grados[i]++;
      }
    }
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return grados[i] > grados[j];
  });
  bitset<5005> curr;
  vector<int> ans;
  for(int i=0;i<n;i++){
    curr = f[p[i]];
    for(int j = 0;j<n;j++){
      if(f[p[i]][j]){
        curr |= f[j];
      }
    }
    bool can = true;
    for(int j = 0;j<n;j++){
      if(!curr[j]){
        can = false;
        break;
      }
    }
    if(can){
      ans.push_back(p[i]);
      if(SZ(ans) == 3) break;
    }
  }
  if(SZ(ans) == 3){
    for(int k=0;k<3;k++){
      cout << ans[k]+1 << " ";
    }
    cout << '\n';
  }else{
    cout << "NOT FOUND\n";
  }

  return 0;
}