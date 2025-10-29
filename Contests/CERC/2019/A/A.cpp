#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

array<vi,2> manacher(const string &s){
  int n = SZ(s);
  array<vi,2> p = {vi(n+1),vi(n)};
  FOR(z,0,2)
  for(int i=0,l=0,r=0;i<n;i++){
    int t = r-i + !z;
    if(i<r) p[z][i] = min(t,p[z][l+t]);
    int L = i-p[z][i],R = i+p[z][i]-!z;
    while(L>=1 && R +1<n && s[L-1] == s[R+1])
      p[z][i]++,L--,R++;
    if(R>r) l = L,r=R;
  }
  return p;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin>>n;
  string s;
  cin >>s;
  array<vi,2> man = manacher(s);
  int ans = 1;
  for(int i=n-1;i>=0;i--){
    if(man[1][i]+i+1 == n) ans = max(ans,man[1][i]*2+1);
    if(man[0][i]+i == n) ans = max(ans,man[0][i]*2);
  }
  cout << n-ans << ENDL;

  return 0;
}