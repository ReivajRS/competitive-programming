#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

struct T {
  int a, b, c;
  int l[3];
  void init(){
    l[0] = a,l[1] = b,l[2] = c;
    sort(l,l+3);
  }
  void rotate() {
    next_permutation(ALL(l));
    a = l[0], b = l[1], c = l[2];
    // 5 125 130
    // 125 130 5
    // 130 5 125
    // 125 5 130
  }
  bool is_rectangle() {
    return a + b == c || a + c == b || b + c == a;
  }
  bool operator==(T o) const {
    return a == o.a && b == o.b && c == o.c;
  }
};

bool check_l(int a, int b, int l) {
  ll mul = (ll) a * b;
  ll sq = sqrt(mul);
  if (sq * sq != mul) return false;
  return a + b + 2 * sq == l;
}

bool check(vector<T>& b) {
  int l = b[0].a;
  if (
    b[0].is_rectangle() && b[3].is_rectangle()
    && b[0].a == b[3].c
    && check_l(b[1].b, b[3].b, l) && check_l(b[0].c, b[2].c, l)
    && b[0].b == b[1].a && b[1].c == b[2].a && b[2].b == b[3].a
  ) return true;

  l = b[0].b;
  if (
    b[0].is_rectangle() && b[1].is_rectangle() && b[3].is_rectangle()
    && b[0].b == l && b[3].b == l
    && check_l(b[0].a, b[1].a, l) && check_l(b[1].c, b[3].c, l)
    && b[0].c == b[2].a && b[1].b == b[2].c && b[3].a == b[2].b
  ) return true;

  l = b[0].a;
  if (
    b[0].is_rectangle() && b[2].is_rectangle()
    && b[0].a == l && b[3].b == l
    && check_l(b[0].c, b[3].c, l) && check_l(b[1].b, b[2].b, l)
    && b[0].b == b[1].a && b[1].c == b[2].a && b[2].c == b[3].a
  ) return true;

  if (
    b[0].is_rectangle() && b[1].is_rectangle() && b[2].is_rectangle() && b[3].is_rectangle()
    && b[0] == b[1] && b[1] == b[2] && b[2] == b[3]
  ) return true;

  if (
    b[0].is_rectangle() && b[1].is_rectangle() && b[2].is_rectangle()
    && b[0].a == b[0].c
    && check_l(b[1].b, b[2].b, l) && check_l(b[1].a, b[3].a, b[0].b)
    && b[1].c == b[2].a && b[2].c == b[3].b && b[3].c == l
  ) return true;

  if (
    b[0].is_rectangle() && b[3].is_rectangle()
    && b[0].c == b[3].c
    && check_l(b[0].b, b[1].b, l) && check_l(b[2].b, b[3].b, l)
    && b[0].c == b[1].a && b[1].c == b[2].a && b[2].c == b[3].a
  ) return true;

  if (
    b[0].a == b[1].b == b[2].b == b[3].c
    && check_l(b[0].b, b[3].b, b[1].a + b[2].c)
  ) return true;

  return false;
}

void solve() {
  vector<T> a(4);
  FOR (i, 0, 4) {
    cin >> a[i].a >> a[i].b >> a[i].c;
    a[i].init();
  }
  vi p = {0, 1, 2, 3};
  do {
    vector<T> b = {a[p[0]], a[p[1]], a[p[2]], a[p[3]]};
    FOR (i, 0, 9) {
      FOR (j, 0, 9) {
        FOR (k, 0, 9) {
          FOR (l, 0, 9) {
            if (check(b)) {
              cout << 1 << ENDL;
              return;
            }
            b[3].rotate();
          }
          b[2].rotate();
        }
        b[1].rotate();
      }
      b[0].rotate();
    }
  } while (next_permutation(ALL(p)));
  cout << 0 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}