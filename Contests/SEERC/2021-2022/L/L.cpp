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
  
  int n;
  string s;
  cin >> n >> s;

  vector<vi> pref(3, vi(SZ(s) + 1, 0));

  FOR (i, 0, SZ(s)) {
    pref[0][i + 1] = pref[0][i] + (s[i] == 'A');
    pref[1][i + 1] = pref[1][i] + (s[i] == 'B');
    pref[2][i + 1] = pref[2][i] + (s[i] == 'C');
  }

  int tot_a = pref[0].back();
  int tot_b = pref[1].back();
  int tot_c = pref[2].back();

  if (tot_a == n && tot_b == n && tot_c == n) {
    cout << 0 << ENDL;
    return 0;
  }

  /*
    Se buscan tot_a - n = goal_a
    Se buscan tot_b - n = goal_b
    Se buscan tot_c - n = goal_c
    2 punteros [l, r]
    Si cnt_b < goal_b || cnt_c < goal_c, r++
    Si l < r && (cnt_b > goal_b || cnt_c > goal_c), l++, recalcular cnt
    Si cnt_b == goal_b && cnt_c && goal_c, ans = {l, r, c}
    Nota: Minimizar intervalo
    
    Repetir para cada letra
  */
  // ABABCABAB

  auto check_a = [&]() -> pi {
    pi ans = {1, 1000000};
    int l = 1;
    int goal_b = tot_b - n;
    int goal_c = tot_c - n;
    for (int r = 1; r <= 3 * n; r++) {
      int cnt_b = pref[1][r] - pref[1][l - 1];
      int cnt_c = pref[2][r] - pref[2][l - 1];
      if (cnt_b < goal_b || cnt_c < goal_c) {
        continue;
      }
      while (l < r && (cnt_b > goal_b || cnt_c > goal_c)) {
        l++;
        cnt_b = pref[1][r] - pref[1][l - 1];
        cnt_c = pref[2][r] - pref[2][l - 1];
      }
      if (r - l < ans.second - ans.first && cnt_b == goal_b && cnt_c == goal_c) {
        ans = {l, r};
      }
    }
    return ans;
  };

  auto check_b = [&]() -> pi {
    pi ans = {1, 1000000};
    int l = 1;
    int goal_a = tot_a - n;
    int goal_c = tot_c - n;
    for (int r = 1; r <= 3 * n; r++) {
      int cnt_a = pref[0][r] - pref[0][l - 1];
      int cnt_c = pref[2][r] - pref[2][l - 1];
      if (cnt_a < goal_a || cnt_c < goal_c) {
        continue;
      }
      while (l < r && (cnt_a > goal_a || cnt_c > goal_c)) {
        l++;
        cnt_a = pref[0][r] - pref[0][l - 1];
        cnt_c = pref[2][r] - pref[2][l - 1];
      }
      if (r - l < ans.second - ans.first && cnt_a == goal_a && cnt_c == goal_c) {
        ans = {l, r};
      }
    }
    return ans;
  };

  auto check_c = [&]() -> pi {
    pi ans = {1, 1000000};
    int l = 1;
    int goal_a = tot_a - n;
    int goal_b = tot_b - n;
    for (int r = 1; r <= 3 * n; r++) {
      int cnt_a = pref[0][r] - pref[0][l - 1];
      int cnt_b = pref[1][r] - pref[1][l - 1];
      if (cnt_a < goal_a || cnt_b < goal_b) {
        continue;
      }
      while (l < r && (cnt_a > goal_a || cnt_b > goal_b)) {
        l++;
        cnt_a = pref[0][r] - pref[0][l - 1];
        cnt_b = pref[1][r] - pref[1][l - 1];
      }
      if (r - l < ans.second - ans.first && cnt_a == goal_a && cnt_b == goal_b) {
        ans = {l, r};
      }
    }
    return ans;
  };

  pi ans_a = check_a();
  pi ans_b = check_b();
  pi ans_c = check_c();

  vector<tuple<int, pi, char>> v;
  if (ans_a.second <= 3*n)
    v.pb({ans_a.second - ans_a.first, ans_a, 'A'});
  if (ans_b.second <= 3*n)
    v.pb({ans_b.second - ans_b.first, ans_b, 'B'});
  if (ans_c.second <= 3*n)
    v.pb({ans_c.second - ans_c.first, ans_c, 'C'});

  if (SZ(v)) {
    sort(ALL(v));
    auto [_, p, c] = v[0];
    cout << 1 << ENDL;
    cout << p.first << ' ' << p.second << ' ' << c << ENDL;
    return 0;
  }

  cout << 2 << ENDL;

  auto it = lower_bound(ALL(pref[0]), n);
  if (it != pref[0].end()) {
    int pos = it - pref[0].begin();
    int cnt_b = pref[1][pos];
    int l1 = pos + 1, r1 = pos + n - cnt_b;
    int l2 = pos + n - cnt_b + 1, r2 = 3 * n;
    if (l1 <= r1 && r1 < l2 && l2 <= r2 && r2 <= 3 * n) {
      cout << l1 << ' ' << r1 << " B" << ENDL;
      cout << l2 << ' ' << r2 << " C" << ENDL;
      return 0;
    }
  }
  it = lower_bound(ALL(pref[1]), n);
  if (it != pref[1].end()) {
    int pos = it - pref[1].begin();
    int cnt_a = pref[0][pos];
    int l1 = pos + 1, r1 = pos + n - cnt_a;
    int l2 = pos + n - cnt_a + 1, r2 = 3 * n;
    if (l1 <= r1 && r1 < l2 && l2 <= r2 && r2 <= 3 * n) {
      cout << l1 << ' ' << r1 << " A" << ENDL;
      cout << l2 << ' ' << r2 << " C" << ENDL;
      return 0;
    }
  }
  it = lower_bound(ALL(pref[2]), n);
  if (it != pref[2].end()) {
    int pos = it - pref[2].begin();
    int cnt_a = pref[0][pos];
    int l1 = pos + 1, r1 = pos + n - cnt_a;
    int l2 = pos + n - cnt_a + 1, r2 = 3 * n;
    if (l1 <= r1 && r1 < l2 && l2 <= r2 && r2 <= 3 * n) {
      cout << l1 << ' ' << r1 << " A" << ENDL;
      cout << l2 << ' ' << r2 << " B" << ENDL;
      return 0;
    }
  }
  
  return 0;
}