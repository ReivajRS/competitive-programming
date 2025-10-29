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

vector<string> mat;
int n, m;
pi moves[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int NUMBER_OF_MOVES = 4;

struct state {
    int cost, lastMove, lastMoveCount;
    pi pos;
    state(int _cost, pi _pos, int _lastMove, int _lastMoveCount) {
        cost = _cost, pos = _pos, lastMove = _lastMove, lastMoveCount = _lastMoveCount;
    }
    
    bool operator<(const state &o) const { return cost < o.cost; }
    bool operator>(const state &o) const { return cost > o.cost; }
};

inline int leftMove(int move) { return (move - 1 + 4) % 4; }
inline int rightMove(int move) { return (move + 1) % 4; }

int dijkstra(const int MIN_SAME_DIRECTION, const int MAX_SAME_DIRECTION) {
    priority_queue<state, vector<state>, greater<state>> pq;
    vector<vector<vector<vi>>> dist(n, vector<vector<vi>>(m, vector<vi>(NUMBER_OF_MOVES, vi(MAX_SAME_DIRECTION + 1, INF))));

    FOR (i, 0, NUMBER_OF_MOVES)
        FOR (j, 0, MAX_SAME_DIRECTION + 1)
            dist[0][0][i][j] = 0;

    int costRight = 0, costDown = 0;
    FOR (i, 1, MIN_SAME_DIRECTION + 1) {
        costRight += mat[0][i] - '0';
        costDown += mat[i][0] - '0';
    }

    pq.push({costRight, {0, MIN_SAME_DIRECTION}, 1, MIN_SAME_DIRECTION}); // Derecha
    pq.push({costDown, {MIN_SAME_DIRECTION, 0}, 2, MIN_SAME_DIRECTION}); // Abajo

    while (!pq.empty()) {
        auto st = pq.top();
        pq.pop();

        if (st.pos.first == n-1 && st.pos.second == m-1)
            return st.cost;

        vi availableMoves;
        availableMoves.pb(leftMove(st.lastMove));
        availableMoves.pb(rightMove(st.lastMove));
        if (st.lastMoveCount < MAX_SAME_DIRECTION)
            availableMoves.pb(st.lastMove);

        for (auto &move : availableMoves) {
            if (move != st.lastMove) {
                // Se dio una vuelta
                
                int y = st.pos.first + moves[move].first * MIN_SAME_DIRECTION;
                int x = st.pos.second + moves[move].second * MIN_SAME_DIRECTION;
                if (y < 0 || y >= n || x < 0 || x >= m)
                    continue;
                
                int cost = st.cost;
                FOR (k, 1, MIN_SAME_DIRECTION + 1) {
                    int i = st.pos.first + moves[move].first * k, j = st.pos.second + moves[move].second * k;
                    cost += mat[i][j] - '0';
                }

                if (cost >= dist[y][x][move][MIN_SAME_DIRECTION])
                    continue;
                
                dist[y][x][move][MIN_SAME_DIRECTION] = cost;
                pq.push({cost, {y, x}, move, MIN_SAME_DIRECTION});

                continue;
            }

            // Se continua en la misma direccion

            int i = st.pos.first + moves[move].first, j = st.pos.second + moves[move].second;
            if (i < 0 || i >= n || j < 0 || j >= m)
                continue;
            
            int cost = st.cost + mat[i][j] - '0';
            if (cost >= dist[i][j][move][st.lastMoveCount + 1])
                continue;
            
            dist[i][j][move][st.lastMoveCount + 1] = cost;
            pq.push({cost, {i, j}, move, st.lastMoveCount + 1});
        }
    }

    return -1;
}

string part1() {
    return to_string(dijkstra(1, 3));
}

string part2() {
    return to_string(dijkstra(4, 10));
}

int main() {_
    string s;
    while (cin >> s)
        mat.pb(s);
    
    n = SZ(mat), m = SZ(mat[0]);

    cout << "Part 1: " << part1() << ENDL;
    cout << "Part 2: " << part2() << ENDL;

    return 0;
}