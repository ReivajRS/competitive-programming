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

  int k;
  string s;
  
  cin >> k >> s;

  int c = 0;
  if (k == 2) {
    int cnt_s2 = 0;
    string s2 = "";
    FOR (i, 0, SZ(s)) {
      s2 += (char)(c + '0');
      c ^= 1;
    }
    FOR (i, 0, SZ(s)) {
      cnt_s2 += s[i] != s2[i];
    }
    int cnt_s3 = 0;
    string s3 = s2;
    for (char &c : s3) {
      c = c == '0' ? '1' : '0';
    }
    FOR (i, 0, SZ(s)) {
      cnt_s3 += s[i] != s3[i];
    }
    cout << min(cnt_s2, cnt_s3) << ' ' << (cnt_s2 <= cnt_s3 ? s2 : s3) << ENDL;
    return 0;
  }

  int ans = 0, cnt = 1, last = s[0];
  FOR (i, 1, SZ(s)) {
    if (last != s[i]) {
      cnt = 0;
    }
    cnt++;
    if (cnt == k) {
      if (i + 1 < SZ(s)) {
        if (s[i + 1] == s[i]) {
          s[i] = s[i] == '0' ? '1' : '0';
        }
        else {
          s[i - 1] = s[i - 1] == '0' ? '1' : '0';
        }
      }
      else {
        s[i] = s[i] == '0' ? '1' : '0';
      }
      cnt = 1;
      ans++;
    }
    last = s[i];
  }

  cout << ans << ' ' << s << ENDL;
  
  return 0;
}