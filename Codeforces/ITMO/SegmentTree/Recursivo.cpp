template <class T>
class SegmentTree {
 private:
    const T DEFAULT = 0;
    int n;
    vector<T> st;

    int lc(int x) { return (x << 1); }
    int rc(int x) { return (x << 1) + 1; }

    void build(vector<T>& initial, int x, int l, int r) {
        if (l == r) {
            st[x] = initial[l];
            return;
        }
        int m = (l + r) / 2;
        build(initial, lc(x), l, m);
        build(initial, rc(x), m + 1, r);
        st[x] = st[lc(x)] + st[rc(x)];
    }
    void update(int idx, T val, int x, int l, int r) {
        if (l == r) {
            st[x] = val;
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m)
            update(idx, val, lc(x), l, m);
        else
            update(idx, val, rc(x), m + 1, r);
        st[x] = st[lc(x)] + st[rc(x)];
    }
    T query(int a, int b, int x, int l, int r) {
        if (r < a || l > b)
            return DEFAULT;
        if (a <= l && r <= b)
            return st[x];
        int m = (l + r) / 2;
        return query(a, b, lc(x), l, m) + query(a, b, rc(x), m + 1, r);
    }
 public:
    SegmentTree(int sz) : n(sz), st(4 * n, DEFAULT) {}
    SegmentTree(vector<T>& initial) : SegmentTree(initial.size()) {
        build(initial, 1, 0, n - 1);
    }
    void update(int idx, T val) {
        update(idx, val, 1, 0, n - 1);
    }
    T query(int a, int b) {
        return query(a, b, 1, 0, n - 1);
    }
};