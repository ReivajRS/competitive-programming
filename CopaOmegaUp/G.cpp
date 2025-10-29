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

// '0' 48
// 'a' 97
// 'A' 65

signed main() { __
  string s1, s2;
  cin >> s1 >> s2;

  ll p1 = 0, p2 = 0;
  for (auto &c : s1) {
    if (c >= '0' && c <= '9') {
      p1 += c - '0';
    }
    else if (c >= 'a' && c <= 'z') {
      p1 += c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'Z') {
      p1 += (c - 'A' + 10) * 2;
    }
  }

  for (auto &c : s2) {
    if (c >= '0' && c <= '9') {
      p2 += c - '0';
    }
    else if (c >= 'a' && c <= 'z') {
      p2 += c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'Z') {
      p2 += (c - 'A' + 10) * 2;
    }
  }

  if (p1 > p2) {
    cout << "Ana " << p1 << ENDL;
  } else {
    cout << "Carolina " << p2 << ENDL;
  }

  return 0;
}