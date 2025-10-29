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
  int n;
  cin >> n;

  map<string, map<char, int>> mp;

  FOR (i, 0, n) {
    string par;
    char pro;
    int pun;
    cin >> par >> pro >> pun;
    mp[par][pro] = max(mp[par][pro], pun);
  }

  vector<pair<int, string>> res;

  for (auto &p : mp) {
    ll sum = 0;
    for (auto &v : p.second) {
      sum += v.second;
    }
    res.pb({sum, p.first});
  }

  sort(ALL(res), [](pair<int, string> i, pair<int, string> j){
    if (i.first == j.first)
      return i.second < j.second;
    return i.first > j.first;
  });

  for (auto &p : res) {
    cout << p.second << ENDL;
  }

  return 0;
}