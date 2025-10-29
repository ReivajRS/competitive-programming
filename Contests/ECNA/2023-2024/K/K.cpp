#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

signed main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  string s[n];
  FOR(i, 0, n)
  {
    cin >> s[i];
  }

  map<array<int, 6>, int> mp;
  FOR(i, 0, n)
  {
    FOR(j, i + 1, n)
    {
      if (SZ(s[i]) != SZ(s[j]))
      {
        continue;
      }
      int dif = 0, m = SZ(s[i]);
      FOR(k, 0, m)
      {
        dif += s[i][k] != s[j][k];
      }

      if (dif != 2)
      {
        continue;
      }

      FOR(k, 0, m - 1)
      {
        if (s[i][k] != s[j][k] && s[i][k + 1] != s[j][k + 1])
        {
          char ca = s[i][k], cb = s[i][k + 1], cc = s[j][k], cd = s[j][k + 1];
          if (ca > cc || (ca == cc && cb > cd))
          {
            swap(ca, cc);
            swap(cb, cd);
          }
          array<int, 6> arr = {ca, cb, cc, cd, k, m};
          mp[arr]++;
          break;
        }
      }
    }
  }

  int ans = 0;
  for (auto &[x, cnt] : mp) {
    ans += cnt == 1;
  }

  cout << ans << ENDL;

  return 0;
}