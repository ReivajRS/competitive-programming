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

constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a; }
inline int sub(int a, int b, int mod) { a -= b; return a < 0 ? a + mod : a; }
inline int mul(int a, int b, int mod) { return ((ll)a*b) % mod; }

const int MOD[] = {(int)1e9+7, (int)1e9+9};

struct H {
    int x, y;
    H(int _x = 0) : x(_x), y(_x) {}
    H(int _x, int _y) : x(_x), y(_y) {}
    inline H operator+(const H& o) { return {add(x, o.x, MOD[0]), add(y, o.y, MOD[1])}; }
    inline H operator-(const H& o) { return {sub(x, o.x, MOD[0]), sub(y, o.y, MOD[1])}; }
    inline H operator*(const H& o) { return {mul(x, o.x, MOD[0]), mul(y, o.y, MOD[1])}; }
    inline bool operator==(const H& o) { return x == o.x && y == o.y; }
};

const int MAXN = 3e5+5;
const H P = {257, 577};
vector<H> pw;

void computePowers() { pw.resize(MAXN + 1); pw[0] = {1, 1}; for (int i = 0; i < MAXN; i++) pw[i + 1] = pw[i] * P; }

struct Hash {
    vector<H> ha;
    Hash(string& s) {
        if (pw.empty())
            computePowers();
        int l = (int) s.size(); ha.resize(l + 1);
        for (int i = 0; i <  l; i++) ha[i + 1] = ha[i] * P + s[i];
    }

    ll hashInterval(int l, int r) { H ret = ha[r] - ha[l] * pw[r - l]; return ((ll)ret.x << 32) + ret.y; }
};

int main() {_
    string s;
    cin >> s;

    Hash h(s);

    int l = 1, r = SZ(s);

    auto check = [&](int len) -> bool {
        unordered_map<ll, int> umap;
        FOR(i, 0, SZ(s) - len + 1) {
            int hv = h.hashInterval(i, i + len);
            umap[hv]++;
        }

        for (auto &[k, v] : umap)
            if (v == 1)
                return true;
        
        return false;
    };

    while (l < r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    auto getAns = [&](int len) -> string {
        unordered_map<int, pi> umap;
        FOR(i, 0, SZ(s) - len + 1) {
            int hv = h.hashInterval(i, i + len);
            umap[hv] = {umap[hv].first + 1, i};
        }

        int mn = SZ(s) + 5;

        for (auto &[k, v] : umap)
            if (v.first == 1)
                mn = min(mn, v.second);
        
        return s.substr(mn, len);
    };

    cout << getAns(l) << ENDL;

    return 0;
}