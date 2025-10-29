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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

#include </home/javier/Escritorio/CompetitiveProgramming/AOC2023/utility.h>

ll hash_string(string s, int p, int mod) {
    ll hash = 0;
    for (char &c : s) {
        hash += c;
        hash *= p;
        hash %= mod;
    }
    return hash;
}

string part1(vector<string> &sp) {
    ll ans = 0;
    for (string &s : sp) {
        ll hash = hash_string(s, 17, 256);
        ans += hash;
    }
    return to_string(ans);
}

void erase(string &s, vector<pair<string, int>> &vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (it->first == s) {
            vec.erase(it);
            return;
        }
    }
}

void insert(string &s, int val, vector<pair<string, int>> &vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (it->first == s) {
            it->second = val;
            return;
        }
    }
    vec.pb({s, val});
}

string part2(vector<string> &sp) {
    ll ans = 0;

    unordered_map<int, vector<pair<string, int>>> umap;

    for (string &s : sp) {
        int hash;
        if (s.back() == '-') {
            string substr = s.substr(0, SZ(s)-1);
            hash = hash_string(substr, 17, 256);
            erase(substr, umap[hash]);
        }
        else {
            string substr = s.substr(0, SZ(s)-2);
            hash = hash_string(substr, 17, 256);
            insert(substr, stoi(to_string(s.back()-'0')), umap[hash]);
        }
    }

    for (auto &[k, v] : umap) {
        FOR (i, 0, SZ(v))
            ans += (1+k) * (i+1) * v[i].second;
    }

    return to_string(ans);
}

int main() {_
    string s;
    getline(cin, s);

    vector<string> sp = split(s, ",");

    cout << "Part 1: " << part1(sp) << ENDL;
    cout << "Part 2: " << part2(sp) << ENDL;
    
    return 0;
}