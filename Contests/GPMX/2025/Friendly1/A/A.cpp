#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

signed main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<ll> a(n);
  FOR(i, 0, n)
      cin >> a[i];
  bool ok = false;
  FOR(i, 0, n)
  {
    string num = to_string(a[i]);
    if (i != 0)
    {

      FOR(k, 0, SZ(num))
      {
        if(SZ(num) == 1){
          num[k] = '0';
          break;
        }
        if (k == 0 && num[k] > '1')
        {
          num[k] = '1';
          break;
        }
        if ((k > 0 && num[k] > '0'))
        {
          num[k] = '0';
          break;
        }
      }

      if (stoll(num) < a[i - 1])
      {
        a[i] = stoll(num);
        ok = true;
        break;
      }
    }
    num = to_string(a[i]);
    if (i < n - 1)
    {
      FOR(k,0,SZ(num)){
        if(num[k] < '9'){
          num[k] = '9';
          break;
        }
      }
      if (stoll(num) > a[i + 1])
      {
        a[i] = stoll(num);
        ok = true;
        break;
      }
    }
  }
  if (!ok)
  {
    cout << "impossible" << '\n';
    return 0;
  }
  for (auto x : a)
    cout << x << " ";
  cout << '\n';

  return 0;
}