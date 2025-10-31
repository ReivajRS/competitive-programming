#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cin >> s;
    if (s[0] == 'm') {
        if (n <= 29) {
            cout << "12" << '\n';
        }
        else if (n == 31) {
            cout << '7' << '\n';
        }
        else {
            cout << "11" << '\n';
        }
    }
    else {
        if (n == 5 || n == 6) {
            cout << "53" << '\n';
        }
        else {
            cout << "52" << '\n';
        }
    }
}