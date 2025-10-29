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

#define NEUT 1
#define oper(a, b) (a * b)
template <class T>
class SegmentTree {
 private:
  vector<T> ST;
  int len;

 public:
  SegmentTree(int len) : len(len), ST(len * 2) {}
  SegmentTree(vector<T>& v) : SegmentTree(v.size()) {
    for (int i = 0; i < len; i++)
      set(i, v[i]);
  }

  void set(int ind, T val) {
    ind += len;
    ST[ind] = val;
    for (; ind > 1; ind /= 2)
      ST[ind / 2] = oper(ST[ind], ST[ind ^ 1]);
  }

  // [start, end]
  T query(int start, int end) {
    end++;
    T ans = NEUT;
    for (start += len, end += len; start < end; start /= 2, end /= 2) {
      if (start % 2 == 1) {
        ans = oper(ans, ST[start++]);
      }
      if (end % 2 == 1) {
        ans = oper(ans, ST[--end]);
      }
    }
    return ans;
  }
};

signed main() { __
  int n, q;
  cin >> n >> q;

  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
    if (x > 0)
      x = 1;
    if (x < 0)
      x = -1;
  }

  SegmentTree<ll> st(a);

  while (q--) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    if (c == 'M') {
      a--, b--;
      if (a > b)
        swap(a, b);
      ll ans = st.query(a, b);
      if (ans == 0) {
        cout << 0 << ENDL;
      } else if (ans > 0) {
        cout << '+' << ENDL;
      } else {
        cout << '-' << ENDL;
      }
    }
    if (c == 'C') {
      a--;
      int x = b;
      if (x > 0)
        x = 1;
      if (x < 0)
        x = -1;
      st.set(a, x);
    }
  }

  return 0;
}