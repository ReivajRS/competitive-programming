#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n, m;
  cin >> n >> m;

  vector<map<char, int>> occ(m);

  FOR (i, 0, n) {
    string s;
    cin >> s;
    FOR (j, 0, m) {
      occ[j][s[j]]++;
    }
  }

  FOR (i, 0, m) {
    int mx = 0;
    char c = char(123);
    for (auto &[k, v] : occ[i]) {
      if (v > mx)
        mx = v, c = k;
      if (v == mx && k < c)
        mx = v, c = k;
    } 
      
    cout << c;
  }

  cout << ENDL;

  return 0;
}