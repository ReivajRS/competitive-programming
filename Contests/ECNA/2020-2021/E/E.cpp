#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

const int MOD = 37;

signed main() { __
  int n;
  cin >> n;

  vector<vi> mat(n, vi(n, 0));

  FOR (i, 0, n) {
    FOR (j, 0, n) {
      cin >> mat[i][j];
    }
  }

  string s;
  getline(cin, s);
  getline(cin, s);

  while (SZ(s) % n != 0) {
    s += " ";
  }

  map<int, char> mp;
  map<char, int> mp2;
  FOR (i, 0, 26) {
    mp[i] = i + 'A';
    mp2[i + 'A'] = i;
  }
  FOR (i, 0, 10) {
    mp[i + 26] = i + '0';
    mp2[i + '0'] = i + 26;
  }
  mp[36] = ' ';
  mp2[' '] = 36;

  vi a(n, 36);

  auto get = [&mat, &n](vi &a) -> vi {
    vi res(n, 0);
    FOR (i, 0, n) {
      FOR (j, 0, n) {
        res[i] = (res[i] + 1ll * mat[i][j] * a[j]) % MOD;
      }
    }
    return res;
  };

  // cout << s << ENDL;

  FOR (i, 0, SZ(s) + 1) {
    if (i > 0 && i % n == 0) {

      vi res = get(a);
      FOR (j, 0, n) {
        cout << mp[res[j]];
      }

    }
    if (i < SZ(s)) {
      // cout << s[i] << ENDL;
      a[i % n] = mp2[s[i]];
    }
  }
  // MAX(dp(1, M - 1, P - 1), dp(M + 1, L, P))

  cout << ENDL;

  return 0;
}