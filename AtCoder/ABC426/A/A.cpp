#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  map<string, int> mp;
  mp["Ocelot"] = 0;
  mp["Serval"] = 1;
  mp["Lynx"] = 2;

  string x, y;
  cin >> x >> y;
  if (mp[x] >= mp[y]) {
    cout << "Yes" << '\n';
  }
  else {
    cout << "No" << '\n';
  }
}