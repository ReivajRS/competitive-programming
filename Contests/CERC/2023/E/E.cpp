#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  map<string, int> mp[2];
  set<string> names;
  for (int i = 0; i < 2; ++i) {
    string line;
    while (getline(cin, line) && line[0] >= '0' && line[0] <= '9') {
      stringstream ss(line);
      string name;
      int s, e;
      ss >> s >> e >> name;
      mp[i][name] += e - s;
      names.insert(name);
    }
  }

  bool found = 0;
  for (auto &s : names) {
    int d = mp[0][s] - mp[1][s];
    if (d) {
      cout << s << ' ' << "-+"[d < 0] << abs(d) << '\n';
      found = true;
    }
  }
  if (!found) {
    cout << "No differences found.\n";
  }

  return 0;
}