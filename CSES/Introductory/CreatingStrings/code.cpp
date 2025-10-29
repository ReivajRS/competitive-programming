#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  vector<string> ans;
  sort(s.begin(), s.end());
  do {
    ans.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << int(ans.size()) << '\n';
  for (auto& x : ans) {
    cout << x << '\n';
  }
}