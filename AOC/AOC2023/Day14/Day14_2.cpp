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

vector<ii> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void move(int i, int j, int moveNum) {
	int y = i + moves[moveNum].first, x = j + moves[moveNum].second;
	while (y >= 0 && y < n && x >= 0 && x < m) {
		if (mat[i][j] == 'O' && mat[y][x] == '.')
			swap(mat[i][j], mat[y][x]);
		i = y, j = x;
		y += moves[moveNum].first, x += moves[moveNum].second;
	}
}

ll lineValue(int i) {
	int ret = 0;
	for (char &c : mat[i])
		ret += (c == 'O') * (n - i);
	return ret;
}

void printMat() {
	FOR(i, n) {
		FOR(j, m) {
			cout<<mat[i][j];
		}
		cout<<ENDL;
	}
}

string flatMat() {
    string s = "";
    for (string &w : mat)
        s += w;
    return s;
}

unordered_map<string, int> umap;

int main(){_
	string s;
	
	while (cin>>s) {
		mat.push_back(s);
	}
	
	n = sz(mat), m = sz(mat[0]);

    int mod = 0, last = 0, k = 0;
	
    while (true) {
        FOR (moveNum, 4) {
            if (moveNum <= 1)
                FOR(i, n)   FOR(j, m)   move(i, j, moveNum);
            else
                FORR(i, n-1, 0)   FORR(j, m-1, 0)   move(i, j, moveNum);
        }
        string flat = flatMat();
        if (umap.count(flat)) {
            mod = k - umap[flat];
            last = k;
            break;
        }
        umap[flat] = k;
        k++;
    }

    int remaining = 1000000000ll - last-1;

    remaining %= mod;

    FOR(k, remaining){
        FOR (moveNum, 4) {
            if (moveNum <= 1)
                FOR(i, n)   FOR(j, m)   move(i, j, moveNum);
            else
                FORR(i, n-1, 0)   FORR(j, m-1, 0)   move(i, j, moveNum);
        }
    }
	
	ll sum = 0;
	
	FOR (i, n) {
	    sum += lineValue(i);
	}
		
	cout<<sum<<ENDL;
	
    return 0;
}
