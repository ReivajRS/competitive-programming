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

template <class T>
class SegmentTree {
 private:
    const T DEFAULT = 0;
    int n;
    vector<T> st;
 public:
    SegmentTree(int _n) : n(_n), st(2 * _n, DEFAULT) {}
    SegmentTree(vector<T>& a) : SegmentTree(a.size()) {
        for (int i = 0; i < n; i++)
            update(i, a[i]);
    }

    void update(int idx, T val) {
        idx += n;
        st[idx] = val;
        for (idx /= 2; idx >= 1; idx /= 2) {
            st[idx] = st[2*idx] ^ st[2*idx+1];
        }
    }

    T query(int a, int b) {
        a += n, b += n;
        T val = DEFAULT;
        while (a <= b) {
            if (a%2 == 1) val ^= st[a++];
            if (b%2 == 0) val ^= st[b--];
            a /= 2, b /= 2;
        }
        return val;
    }
};

signed main() { __
    int n, q;
    cin >> n >> q;

    SegmentTree<ll> st(n);

    FOR (i, 0, n) {
        ll x;
        cin >> x;
        st.update(i, x);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << st.query(a-1, b-1) << ENDL;;
    }

    return 0;
}