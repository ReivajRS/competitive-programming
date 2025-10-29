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
vector<vector<bool>> wNum;
vector<vi> numIn;
int n, m;
vii poss;
string num = "";

void putNums() {
    int number = stoi(num);
    for (auto &[i, j] : poss)
        numIn[i][j] = number;
}

int check(int i, int j) {
    int num1 = -2, num2 = -2;

    if (i > 0) {
        if (wNum[i-1][j]) {
            if (num1 == -2)
                num1 = numIn[i-1][j];
            else
            if (num2 == -2 && num1 != numIn[i-1][j])
                num2 = numIn[i-1][j];
        }
    }
    if (j > 0) {
        if (wNum[i][j-1]) {
            if (num1 == -2)
                num1 = numIn[i][j-1];
            else
            if (num2 == -2 && num1 != numIn[i][j-1])
                num2 = numIn[i][j-1];
        }
    }
    if (i < n-1) {
        if (wNum[i+1][j]) {
            if (num1 == -2)
                num1 = numIn[i+1][j];
            else
            if (num2 == -2 && num1 != numIn[i+1][j])
                num2 = numIn[i+1][j];
        }
    }
    if (j < m-1) {
        if (wNum[i][j+1]) {
            if (num1 == -2)
                num1 = numIn[i][j+1];
            else
            if (num2 == -2 && num1 != numIn[i][j+1])
                num2 = numIn[i][j+1];
        }
    }

    if (i > 0 && j > 0) {
        if (wNum[i-1][j-1]) {
            if (num1 == -2)
                num1 = numIn[i-1][j-1];
            else
            if (num2 == -2 && num1 != numIn[i-1][j-1])
                num2 = numIn[i-1][j-1];
        }
    }
    if (i < n-1 && j < m-1) {
        if (wNum[i+1][j+1]) {
            if (num1 == -2)
                num1 = numIn[i+1][j+1];
            else
            if (num2 == -2 && num1 != numIn[i+1][j+1])
                num2 = numIn[i+1][j+1];
        }
    }
    if (i > 0 && j < m-1) {
        if (wNum[i-1][j+1]) {
            if (num1 == -2)
                num1 = numIn[i-1][j+1];
            else
            if (num2 == -2 && num1 != numIn[i-1][j+1])
                num2 = numIn[i-1][j+1];
        }
    }
    if (i < n-1 && j > 0) {
        if (wNum[i+1][j-1]) {
            if (num1 == -2)
                num1 = numIn[i+1][j-1];
            else
            if (num2 == -2 && num1 != numIn[i+1][j-1])
                num2 = numIn[i+1][j-1];
        }
    }

    return (num1 != -2 && num2 !=-2 && num1 != num2) ? num1*num2 : 0;
}

int main(){_
    string s;
    ll sum = 0;
    
    while (cin>>s)
        mat.push_back(s);

    n = sz(mat), m = sz(mat[0]);
    wNum.assign(n, vector<bool>(m, false));
    numIn.assign(n, vi(m, -1));

    FOR(i, n)
        FOR(j, m)
            wNum[i][j] = isdigit(mat[i][j]);
    
    FOR(i, n) {
        FOR(j, m) {
            if (wNum[i][j]) {
                num += mat[i][j];
                poss.push_back({i, j});
            }
            else {
                if (num != "")
                    putNums();
                poss.clear(), num = "";
            }
        }
    }

    FOR(i, n)
        FOR(j, m)
            if (mat[i][j] == '*')
                sum += check(i, j);

    cout<<sum<<ENDL;

    return 0;
}