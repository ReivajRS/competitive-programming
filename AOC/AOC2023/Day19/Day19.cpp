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

struct rule {
    char part, op;
    ll number;
    string destiny;
};

struct workflow {
    vector<rule> rules;
    string nextWF;
    workflow() {}
    workflow(vector<rule> _rules, string _nextWF) {
        rules = _rules, nextWF = _nextWF;
    }
};

struct rating {
    unordered_map<char, ll> parts;
    char status;
    rating() : status('P') {}
    ll getValue() {
        ll val = 0;
        for (auto &p : parts)
            val += p.second;
        return val;
    }
};

struct ratingRange {
    unordered_map<char, pair<ll, ll>> partRanges;
    ratingRange() {
        partRanges['x'] = {1, 4000};
        partRanges['m'] = {1, 4000};
        partRanges['a'] = {1, 4000};
        partRanges['s'] = {1, 4000};
    }
    ll getValue() {
        ll val = 1ll;
        val *= (partRanges['x'].second - partRanges['x'].first + 1);
        val *= (partRanges['m'].second - partRanges['m'].first + 1);
        val *= (partRanges['a'].second - partRanges['a'].first + 1);
        val *= (partRanges['s'].second - partRanges['s'].first + 1);
        return val;
    }
    auto to_tuple() {
        return make_tuple(partRanges['x'], partRanges['m'], partRanges['a'], partRanges['s']);
    }
};

unordered_map<string, workflow> wfs;
vector<rating> rts;
queue<ratingRange> rtsRng;
set<tuple<pair<ll, ll>, pair<ll, ll>, pair<ll, ll>, pair<ll, ll>>> memo;

ll processWF(rating &rt, string wf) {
    if (wf == "A" || wf == "R") {
        rt.status = wf[0];
        return wf == "A" ? rt.getValue() : 0;
    }

    for (auto &r : wfs[wf].rules) {
        char part = r.part, op = r.op;
        ll number = r.number;
        if (op == '<') {
            if (rt.parts[part] < number)
                return processWF(rt, r.destiny);
        }
        else {
            if (rt.parts[part] > number)
                return processWF(rt, r.destiny);
        }
    }

    return processWF(rt, wfs[wf].nextWF);
}

ll processWF(ratingRange &rt, string wf) {
    if (wf == "A" || wf == "R")
        return wf == "A" ? rt.getValue() : 0;

    for (auto &r : wfs[wf].rules) {
        char part = r.part, op = r.op;
        ll number = r.number;
        if (op == '<') {
            auto [lo, hi] = rt.partRanges[part];

            if (hi < number)
                return processWF(rt, r.destiny);
            
            if (lo < number) {
                hi = number - 1;
                ratingRange newRt = rt;
                newRt.partRanges[part] = {lo, hi};
                auto tp = rt.to_tuple();
                if (!memo.count(tp)) {
                    memo.insert(tp);
                    rtsRng.push(newRt);
                    rt.partRanges[part].first = number;
                }
            }
        }
        else {
            auto [lo, hi] = rt.partRanges[part];

            if (lo > number)
                return processWF(rt, r.destiny);
            
            if (hi > number) {
                lo = number + 1;
                ratingRange newRt = rt;
                newRt.partRanges[part] = {lo, hi};
                auto tp = rt.to_tuple();
                if (!memo.count(tp)) {
                    memo.insert(tp);
                    rtsRng.push(newRt);
                    rt.partRanges[part].second = number;
                }
            }
        }
    }

    return processWF(rt, wfs[wf].nextWF);
}

string part1() {
    ll ans = 0;
    
    for (auto &rt : rts)
        ans += processWF(rt, "in");

    return to_string(ans);
}

string part2() {
    rtsRng.push(ratingRange());

    ll ans = 0;

    while (!rtsRng.empty()) {
        auto rt = rtsRng.front();
        rtsRng.pop();
        ans += processWF(rt, "in");
    }
    return to_string(ans);
}

int main() {_
    string s;
    while (getline(cin, s)) {
        if (s.empty())
            break;
        int fp = s.find("{"), sp = s.find("}");
        string id = s.substr(0, fp), wf = s.substr(fp + 1, sp - fp - 1);

        vector<string> vsp = split(wf, ",");

        vector<rule> rules(SZ(vsp) - 1);

        FOR (i, 0, SZ(rules)) {
            rules[i].part = vsp[i][0];
            rules[i].op = vsp[i][1];
            int ddpos = vsp[i].find(":");
            rules[i].number = stoll(vsp[i].substr(2, ddpos - 2));
            rules[i].destiny = vsp[i].substr(ddpos + 1);
        }

        string nextWF = vsp.back();

        wfs[id] = workflow(rules, nextWF);
    }

    while (getline(cin, s)) {
        int fp = 0, sp = s.find("}");
        string p = s.substr(fp + 1, sp - fp - 1);
        vector<string> vsp = split(p, ",");
        rating rt;
        FOR (i, 0, 4) {
            char p = vsp[i][0];
            string v = vsp[i].substr(2);
            rt.parts[p] = stoll(v);
        }
        rts.push_back(rt);
    }

    cout << "Part 1: " << part1() << ENDL;
    cout << "Part 2: " << part2() << ENDL;

    return 0;
}