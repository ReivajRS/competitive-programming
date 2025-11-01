#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    int64_t t = 0, reward = 0;

    for (auto [a, d] : tasks) {
        t += a;
        reward += d - t;
    }

    cout << reward << '\n';
}