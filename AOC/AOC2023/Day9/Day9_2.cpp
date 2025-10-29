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
typedef vector<ll> vi;
typedef vector<ii> vii;
const ll MOD = 1e9+7, INF = 1e18;

vector<vi> valuesLine;

void process(vi values) {
    valuesLine.clear();
    valuesLine.push_back(values);
    ll lastDiff = -INF;
    bool flag = false;
    while (!flag) {
        vi tempValues;
        lastDiff = -INF;
        flag = true;
        FOR(i, sz(values)-1) {
            ll diff = values[i+1]-values[i];
            if (lastDiff == -INF)
                lastDiff = diff;
            else
                if (diff != lastDiff)
                    flag = false;
            tempValues.push_back(diff);
        }
        values = tempValues;
        valuesLine.push_back(tempValues);
    }
}

ll getNewValue() {
    ll newValue = 0;
    FORR(i, sz(valuesLine)-1, 0) {
        newValue = *valuesLine[i].begin() - newValue;
    }
    return newValue;
}

int main(){_
    string line, w;
    ll sum = 0;
    
    while (getline(cin, line)) {
        stringstream ss(line);
        vi values;
        while (ss>>w)
            values.push_back(stoi(w));
        process(values);
        sum += getNewValue();
    }

    cout<<sum<<ENDL;

    return 0;
}