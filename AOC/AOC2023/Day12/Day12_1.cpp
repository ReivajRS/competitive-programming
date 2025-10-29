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

#include </home/javier/Escritorio/CompetitiveProgramming/AOC2023/utility.h>

vi subList(vi &groups, int start, int end) {
    vi ret;
    for (int i = start; i < end; i++)
        ret.push_back(groups[i]);
    return ret;
}

bool checkRemaining(string &s, int limit) {
    for (int i = 0; i < limit; i++) {
        if (s[i] != '#' && s[i] != '?')
            return false;
    }
    return true;
}

map<pair<string, vi>, ll> umap;

ll solve(string record, vi groups) {
    pair<string, vi> input(record, groups);
    if (umap.count(input))
        return umap[input];
    if (input.first.empty())
        return input.second.empty();
    
    if (input.first[0] == '.')
        return umap[input] = solve(record.substr(1), groups);
    if (input.first[0] == '?')
        return umap[input] = solve("." + record.substr(1), groups) + solve("#" + record.substr(1), groups);

    if (groups.empty())
        return umap[input] = 0;

    int numDamaged = groups[0];

    if (numDamaged <= record.length() && checkRemaining(record, numDamaged)) {
        vi newGroups = subList(groups, 1, groups.size());
        if (numDamaged == record.length())
            return umap[input] = newGroups.empty();
        if (record[numDamaged] == '.')
            return umap[input] = solve(record.substr(numDamaged + 1), newGroups);
        if (record[numDamaged] == '?')
            return umap[input] = solve("." + record.substr(numDamaged + 1), newGroups);
        return umap[input] = 0;
    }

    return umap[input] = 0;
}

int main(){_
    string record, snums;

    ll sum = 0;

    while(cin>>record>>snums) {
        vi groups;
        vector<string> sp = split(snums, ",");
        for (string &s : sp)
            groups.push_back(stoi(s));
        
        sum += solve(record, groups);
    }

    cout<<sum<<ENDL;

    return 0;
}