#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i>= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  string n1, n2, res;
  char op, eq;
  cin >> n1 >> op >> n2 >> eq >> res;

  auto check = [&](ll num1, ll num2, ll res, char op) -> bool {
    if (op == '+')
      return num1 + num2 == res;
    return num1 * num2 == res;
  };


  FOR (i, 1, SZ(n1)) {
    FOR (j, 1, SZ(n2)) {
      string num1, num2;
      num1 = n2.substr(0, j) + n1.substr(i);
      num2 = n1.substr(0, i) + n2.substr(j);
      if (check(stoll(num1), stoll(num2), stoll(res), op)) {
        cout << num1 << ' ' << op << ' ' << num2 << ' ' << '=' << ' ' << res << ENDL; 
        return 0;
      }
    }
  }

  FOR (i, 1, SZ(n1)) {
    FOR (j, 1, SZ(res)) {
      string num1, resu;
      num1 = res.substr(0, j) + n1.substr(i);
      resu = n1.substr(0, i) + res.substr(j);
      if (check(stoll(num1), stoll(n2), stoll(resu), op)) {
        cout << num1 << ' ' << op << ' ' << n2 << ' ' << '=' << ' ' << resu << ENDL; 
        return 0;
      }
    }
  }

  FOR (i, 1, SZ(n2)) {
    FOR (j, 1, SZ(res)) {
      string num2, resu;
      num2 = res.substr(0, j) + n2.substr(i);
      resu = n2.substr(0, i) + res.substr(j);
      if (check(stoll(n1), stoll(num2), stoll(resu), op)) {
        cout << n1 << ' ' << op << ' ' << num2 << ' ' << '=' << ' ' << resu << ENDL; 
        return 0;
      }
    }
  }

  return 0;
}