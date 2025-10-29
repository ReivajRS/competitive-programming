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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  string s = "aaaaaaaaaa";
  cout << s << ENDL;
  vi cnt(5,0);
  FOR(i,1,n){

    int curr=0;
    for(;curr<5;curr++){
      cnt[curr]++;
      if(cnt[curr] == 26)cnt[curr] = 0;
      else break;
    }
    s[curr*2]++;
    if(s[curr*2] == 'z'+1) s[curr*2] = 'a';
    cout << s << ENDL;
    s[curr*2+1]++;
    if(s[curr*2+1] == 'z'+1) s[curr*2+1] = 'a';
    if(i!= n-1) cout << s << ENDL;
    i++;
  }

  return 0;
}