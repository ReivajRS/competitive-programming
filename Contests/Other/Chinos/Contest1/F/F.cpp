#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  map<string,int> mapa;
  FOR(i,0,n){
    string s;
    cin >> s;
    mapa[s]++;
  }

  for(auto &[s,x]:mapa){
    if(x*2>n){
      cout << s << ENDL;
      return 0;
    }
  }
  cout << "uh-oh" << ENDL;

  return 0;
}