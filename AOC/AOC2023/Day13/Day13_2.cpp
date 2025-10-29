#include <bits/stdc++.h>
// Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x)   (int) x.size()
#define FOR(x, b)     for(int x = 0; x < b; x++)
#define FORE(x, a, b) for(int x = a; x <= b; x++)
#define FORR(x, a, b) for(int x = a; x >= b; x--)
#define deb(x)      cerr << #x << " = " << x << '\n';
#define deb2(x, y)  cerr << #x << " = " << x << ", " << #y << " = " << y << '\n';
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ll MOD = 1e9+7, INF = 1e18;

vector<string> mat;

void printMat() {
    for (auto &s : mat)
        cout<<s<<ENDL;
}

string getColumn(int pos) {
    string s = "";
    for (auto &x : mat)
        s += x[pos];
    return s;
}

int check(string s, string w) {
    int fails = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] != w[i])
            fails++;
        if (fails > 1)
            return fails;
    }
    return fails;
}

pair<int, bool> findLine() {
    int n = mat.size(), m = mat[0].size();

    for (int i = 0; i < n; i++) {
        int l = i, r = l + 1;
        bool flag = false;
        int fails = 0;

        while (l >= 0 && r < n) {
            fails += check(mat[l], mat[r]);
            if (fails > 1)
                break;
            l--, r++;
            if (l < 0 || r == n)
                flag = true;
        }

        if (flag && fails == 1) {
            // cout<<"H: "<<i+1<<ENDL;
            return {i, true};
        }
    }

    for (int i = 0; i < m; i++) {
        int l = i, r = l + 1;
        bool flag = false;
        int fails = 0;

        while (l >= 0 && r < m) {
            fails += check(getColumn(l), getColumn(r));
            if (fails > 1)
                break;
            l--, r++;
            if (l < 0 || r == m)
                flag = true;
        }

        if (flag && fails == 1){
            // cout<<"V: "<<i+1<<ENDL;
            return {i, false};
        }
    }

    cout<<"----"<<ENDL;
    return {0, true};
}

int main(){_
    string s;

    vi horizontals, verticals;

    while (getline(cin, s)) {
        if (s.length() == 0) {
            auto [idx, flag] = findLine();
            if (flag)
                horizontals.push_back(idx);
            else
                verticals.push_back(idx);
            mat.clear();
            continue;
        }
        mat.push_back(s);
    }

    auto [idx, flag] = findLine();
    if (flag)
        horizontals.push_back(idx);
    else
        verticals.push_back(idx);

    ll sum = 0;

    for (auto &x : horizontals)
        sum += ((x+1)*100);

    for (auto &x : verticals)
        sum += (x+1);

    cout<<sum<<ENDL;

    return 0;
}