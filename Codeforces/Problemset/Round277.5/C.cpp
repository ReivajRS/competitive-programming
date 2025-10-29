#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  int m, s;
  cin >> m >> s;

  if (m == 1 && s == 0) {
    cout << "0 0" << ENDL;
    return 0;
  }

  string n1(m, '_'), n2(m, '_');
  int sum = s;

  FOR (i, 0, m) {
    if (sum > 9) {
      n2[i] = '9';
      sum -= 9;
      continue;
    }
    n2[i] = sum + '0';
    sum = 0;
  }

  sum = s;

  auto check = [](char c, int rem, int sum) -> bool {
    return sum - c >= 0 && sum - c <= 9 * rem;
  };

  FOR (i, 0, m) {
    FOR (j, 0, 10) {
      if ((i > 0 || j > 0) && check(j, m - i - 1, sum)) {
        n1[i] = j + '0';
        sum -= j;
        break;
      }
    }
  }

  int s1 = 0, s2 = 0;
  for (char &c : n1)
    s1 += c - '0';
  for (char &c : n2)
    s2 += c - '0';

  if (s1 != s || s2 != s) {
    cout << "-1 -1" << ENDL;
    return 0;
  }

  cout << n1 << ' ' << n2 << ENDL;
  
  return 0;
}