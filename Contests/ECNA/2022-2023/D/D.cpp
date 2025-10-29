#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  
  string s;
  cin >> s;
  int n = SZ(s);
  vi prefixA(n+1,0);
  vi prefixT(n+1,0);
  vi prefixG(n+1,0);
  vi prefixC(n+1,0);
  FOR(i,0,n){
    prefixA[i+1] = prefixA[i] + (s[i] == 'A');
    prefixT[i+1] = prefixT[i] + (s[i] == 'T');
    prefixG[i+1] = prefixG[i] + (s[i] == 'G');
    prefixC[i+1] = prefixC[i] + (s[i] == 'C');
  }
  int q;
  cin >> q;
  while(q--){
    int x,y;
    cin >> x >> y; x--;
    vector<pair<int,char>> ans;
    ans.pb({-(prefixA[y] - prefixA[x]),'A'});
    ans.pb({-(prefixT[y] - prefixT[x]),'B'});
    ans.pb({-(prefixG[y] - prefixG[x]),'C'});
    ans.pb({-(prefixC[y] - prefixC[x]),'D'});
    sort(ALL(ans));
    FOR(i,0,4){
      if(ans[i].second == 'A') cout << 'A';
      if(ans[i].second == 'B') cout << 'T';
      if(ans[i].second == 'C') cout << 'G';
      if(ans[i].second == 'D') cout << 'C';
    }
    cout << ENDL;
  }


  return 0;
}