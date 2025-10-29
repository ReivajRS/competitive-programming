#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  string s1, s2;
  cin >> s1 >> s2;

  vi p1, p2;
  int m = 0, n = 0;
  FOR (i, 0, SZ(s1)) {
    if (s1[i] == '*') {
      m++;
      p1.pb(i);
    }
  }
  FOR (i, 0, SZ(s2)) {
    if (s2[i] == '*') {
      n++;
      p2.pb(i);
    }
  }

  auto reduce = [](string &s) -> void {
    int cnt = 0;
    for (char &c : s)
      if (c == '0') cnt++;
      else break;
    s.erase(0, cnt);
  };

  auto can = [&reduce](string &n1, string &n2) -> bool {
    if (SZ(n1) > SZ(n2)) return true;
    if (SZ(n1) < SZ(n2)) return false;
    FOR (i, 0, SZ(n1)) {
      if (n1[i] > n2[i]) return true;
      if (n1[i] < n2[i]) return false;
    }
    return true;
  };

  auto sub = [](string &n1, string &n2) -> string {
    string res = "";
    bool borrow = 0;
    for (int i = SZ(n1) - 1, j = SZ(n2) - 1; i >= 0; i--, j--) {
      int x = n1[i] - '0';
      int y = (j >= 0) ? n2[j] - '0' : 0;
      if (borrow) {
        if (y == 1) y = 0;
        else y = 1, borrow = 0;
      }
      if (x == y) {
        res.pb('0');
        continue; 
      }
      res.pb('1');
      if (y > x) borrow = 1;
    }
    reverse(ALL(res));
    return res;
  };

  auto check = [&can, &sub, &reduce](string n1, string n2) -> bool {
    reduce(n1), reduce(n2);
    if (n2.empty()) return false;
    string now = "";
    FOR (i, 0, SZ(n1)) {
      now += n1[i];
      if (can(now, n2)) {
        now = sub(now, n2);
      }
      reduce(now);
    }
    return now.empty();
  };

  FOR (msk1, 0, (1 << m)) {
    int i = 0;
    for (int x : p1) {
      s1[x] = (1 & (msk1 >> i)) + '0';
      i++;
    }
    FOR (msk2, 0, (1 << n)) {
      int j = 0;
      for (int x : p2) {
        s2[x] = (1 & (msk2 >> j)) + '0';
        j++;
      }
      if (check(s1, s2)) {
        cout << s1 << ENDL;
        return 0;
      }
    }
  }

  cout << "-1" << ENDL;
    
  return 0;
}