#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

// cbbabcacbb
// aabbbbbbcc aabbbbbccc

// aaaaaabaaa
// aaaaabaaab
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  int n = SZ(s)/2;
  map<char,int> mapa;
  char mx = '%';
  for(auto c:s){
    mapa[c]++;
    if(mapa[c]>n){
      mx = c;
    }
  }
  if(mx == '%'){
    cout  << "YES" << ENDL;
    for(auto [c,cnt]:mapa){
      FOR(_,0,cnt) cout << c;
    }
    cout << ENDL;
    return 0;
  }

  if(SZ(mapa) == 1 || (SZ(mapa) == 2 && mapa[mx] >= n*2-2)){
    cout << "NO" << ENDL;
    return 0;
  }
  cout << "YES" << ENDL;

  FOR(i,0,n){
    cout << mx;
  }
  mapa[mx]-=n;
  for(auto &[c,cnt]:mapa){
    if(c != mx) {
      cout << c;
      cnt--;
      break;
    }
  }
  int cnt2 = mapa[mx];
  FOR(i,0,cnt2) cout << mx;
  mapa[mx] = 0;
  for(auto [c,cnt]:mapa){
      FOR(_,0,cnt) cout << c;
  }
  cout << ENDL;


  return 0;
}

/*
1 [4, 4, 4, 3]
2 [4, 4, 3, 2]
3 [4, 3, 2, 2]
4 [4, 3, 2, 2]
5 [4, 4, 4, 2]
4 + 4 + 4 + 3 + 4 +2 + 4 + 2 + 4 + 4
 */