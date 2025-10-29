#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)(x.size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'


int n;
vector<vi> g;
vi dist;

void bfs(int source){
    dist.assign(n,-1);
    queue<int> q;
    q.push(source);
    dist[source ] = 0;
    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (auto &v : g[f]) {
            if (dist[v] != -1)
                continue;
            dist[v] = dist[f] + 1;
            q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    g.assign(n,vi());
    FOR(i,0,m){
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    bfs(0);
    int mx = 0,posmx = 0;
    FOR(i,0,n){
        if(mx< dist[i]){
            mx = dist[i];
            posmx = i;
        }
    }

    bfs(posmx);
    mx = 0,posmx = 0;
    FOR(i,0,n){
        if(dist[i] == -1){
            cout << -1 << ENDL;
            return 0;
        }
        if(mx< dist[i]){
            mx = dist[i];
            posmx = i;
        }
    }

    cout << ceil(log2(mx)) << ENDL;

    return 0;
}