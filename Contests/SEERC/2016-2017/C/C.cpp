#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

constexpr int MAX = 2e6;

int n = 0;
int p[MAX];
char s[MAX];
int ans[MAX];
bool vacio = true;


void kmp(char c){
  vacio = false;
  s[++n] = c;
  if(n == 1) return;
  int g = p[n-1];
  while(g && c != s[g+1]) g = p[g];
  p[n] = g + (c == s[g+1]);

  ans[n] = ans[p[n]];
}

signed main() { __

  int m,q;
  cin >> m >> q;
  string s2;
  cin >> s2;
  FOR(i,0,m){
    kmp(s2[i]);
  }
  while(q--){
    int p2;
    cin >> p2;
    if(p2 == 1){
      char c;
      cin >> c;
      kmp(c);
    }else if(p2 == 2){
      if(vacio) continue;
      vacio = true;
      ans[n]++;
    }else{
      cout << ans[n] << ENDL;
    }
  }

  // abababa
   
  return 0;
}