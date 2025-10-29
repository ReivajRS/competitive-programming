#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

using Team = pair<int, string>;

Team getWinner(int l, int r, vector<Team>& teams) {
  if (l + 1 == r) {
    return max(teams[l], teams[r]);
  }
  int m = (l + r) / 2;
  Team left = getWinner(l, m, teams), right = getWinner(m + 1, r, teams);
  if (!l && r == 7) {
    Team winner = max(left, right), loser = min(left, right);
    cout << winner.second << " beats " << loser.second << '\n';
  }
  return max(left, right);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<Team> teams(8);
  for (auto &[strength, name] : teams) {
    cin >> name >> strength;
  }
  getWinner(0, 7, teams);

  return 0;
}