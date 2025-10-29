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

unordered_map<string, int> cubes = {{"red", 12}, {"green", 13}, {"blue", 14}};

int main(){_
    string s, num = "";

    int nGame = 1, iColor = -1, i;

    bool flag = false;

    ll sum = 0;


    while (getline(cin, s)) {
        flag = false;

        for (auto &[color, cnt] : cubes) {
            do {
                iColor = s.find(color, iColor+1);
                i = iColor-2;
                num = "";
                while (isdigit(s[i])) {
                    num = s[i]+num;
                    i--;
                }
                if (iColor == -1)
                    break;

                if (stoi(num) > cubes[color])
                    flag = true;
                
            } while(iColor != -1);
        }

        if (!flag) {
            sum += nGame;
        }

        nGame++;
    }

    cout<<sum<<ENDL;

    return 0;
}