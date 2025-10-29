#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<pair<string,string>> a(n);
  string _;
  getline(cin,_);
  for(int i=0;i<n;i++){
    string s;
    getline(cin,s);
    for(int j=0;j<s.size();j++){
      if(isupper(s[j])){
        
        a[i] = {s.substr(j),s};
        break;
      }
    }
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    cout << a[i].second << '\n';
  }

  return 0;
}