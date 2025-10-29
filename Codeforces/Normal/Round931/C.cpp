#include <bits/stdc++.h>
using namespace std;
 
#define ENDL '\n'
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
 
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

vi dp(101, INF);

void pre() {
  vi c = {1,3,6,10,15};
  for (auto &v : c) {
    dp[v] = 1;
  }

  FOR (i, 0, 100) {
    for (auto &v : c) {
      if (i >= v)
        dp[i] = min(dp[i], dp[i - v] + 1);
    }
  }
}
 
int main() {_
    int x;
    cin >> x;

    pre();

    FOR (i, 1, x) {
      cout << dp[i] << ',';
    }
 
    return 0;
}