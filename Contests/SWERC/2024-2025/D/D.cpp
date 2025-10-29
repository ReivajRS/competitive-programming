#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<ll> a(n);
  FOR(i,0,n) cin >> a[i];
  stack<int> st;
  vector<int> leftG(n),rightG(n);
  FOR(i,0,n){
    while(SZ(st) && a[st.top()] < a[i]) st.pop();
    leftG[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  while(SZ(st)) st.pop();
  for(int i=n-1;i>=0;i--){
    while(SZ(st) && a[st.top()] < a[i]) st.pop();
    rightG[i] = st.empty() ? n : st.top();
    st.push(i);
  }

  ll ans = 0;
  FOR(i,0,n){
    if(leftG[i] == -1 && rightG[i] == n) continue;
    if(leftG[i] == -1){
      ans += abs(rightG[i] - i);
    
      continue;
    }
    if(rightG[i] == n){
      ans += abs(leftG[i] - i);
      
      continue;
    }
    ans += min(abs(rightG[i]-i),abs(leftG[i]-i));
    
  }
  cout << ans << '\n';

  return 0;
}