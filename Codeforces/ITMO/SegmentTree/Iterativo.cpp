#include <bits/stdc++.h>
using namespace std;

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
            st[idx] = st[2*idx] + st[2*idx+1];
        }
    }

    T query(int a, int b) {
        a += n, b += n;
        T val = DEFAULT;
        while (a <= b) {
            if (a%2 == 1) val += st[a++];
            if (b%2 == 0) val += st[b--];
            a /= 2, b /= 2;
        }
        return val;
    }
};
