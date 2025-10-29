#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<int> word(30,-1);
  int n;
  cin >> n;
  vector<string> a(n);
  FOR(i,0,n){
    cin >> a[i];
    word[a[i][0]-'A'] = i;
  }

  auto isValid = [&](string s) -> bool {
    for(auto c:s){
      if(word[c-'A'] == -1) return false;
    }
    return true;
  };
  FOR(i,0,n){ 
    if(isValid(a[i])){
      cout << SZ(a[i]) << ENDL;
      for(auto c:a[i]){
        cout << a[word[c-'A']] << " ";
      }
      cout << ENDL;
      return 0;
    }
  }
  cout << -1 << ENDL;

  return 0;
}