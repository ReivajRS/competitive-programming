#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  int n = SZ(s);
  stack<char> st;
  FOR(i,0,n){
    if(st.empty() or st.top() != s[i]) st.push(s[i]);
    else st.pop();
  }
  vector<char> ans;
  while(SZ(st)){
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(),ans.end());
  for(auto c:ans) cout << c;
  cout << '\n';
  return 0;
}