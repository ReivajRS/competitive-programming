#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 0, i});
        events.push_back({b, 1, i});
    }

    sort(events.begin(), events.end());

    int used = 0, needed = 0;
    for (auto [x, op, id] : events) {
        if (op == 0) {
            used++;
            needed = max(needed, used);
        }
        else {
            used--;
        }
    }
    
    vector<int> room(n);
    stack<int> st;
    for (int i = needed; i >= 1; i--) {
        st.push(i);
    }
    for (auto [x, op, id] : events) {
        if (op == 0) {
            room[id] = st.top();
            st.pop();
        }
        else {
            st.push(room[id]);
        }
    }

    cout << needed << '\n';
    for (int i = 0; i < n; i++) {
        cout << room[i] << ' ';
    }
    cout << '\n';
}