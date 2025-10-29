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
int n, m;
string num;

bool check(int i, int j) {
    bool ret = false;

    if (i > 0)
        ret |= (!isdigit(mat[i-1][j]) && mat[i-1][j] != '.');
    if (j > 0)
        ret |= (!isdigit(mat[i][j-1]) && mat[i][j-1] != '.');
    if (i < n-1)
        ret |= (!isdigit(mat[i+1][j]) && mat[i+1][j] != '.');
    if (j < m-1)
        ret |= (!isdigit(mat[i][j+1]) && mat[i][j+1] != '.');

    if (i > 0 && j > 0)
        ret |= (!isdigit(mat[i-1][j-1]) && mat[i-1][j-1] != '.');
    if (i < n-1 && j < m-1)
        ret |= (!isdigit(mat[i+1][j+1]) && mat[i+1][j+1] != '.');
    if (i > 0 && j < m-1)
        ret |= (!isdigit(mat[i-1][j+1]) && mat[i-1][j+1] != '.');
    if (i < n-1 && j > 0)
        ret |= (!isdigit(mat[i+1][j-1]) && mat[i+1][j-1] != '.');

    return ret;
}

int main(){_
    string s;
    
    while (cin>>s)
        mat.push_back(s);

    n = sz(mat), m = sz(mat[0]);

    bool flag = false;

    ll sum = 0;

    FOR(i, n) {
        FOR (j, m) {
            if (isdigit(mat[i][j]))
                num += mat[i][j], flag |= check(i, j);
            else {
                if (num != "" && flag)
                    sum += stoi(num);
                num = "", flag = false;
            }
        }
    }

    cout<<sum<<ENDL;

    return 0;
}