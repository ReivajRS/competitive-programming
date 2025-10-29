#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end();
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

long double dp[505][505];
long double comb(int n,int k){
    if(k>n || k< 0) return 0;
    if(n == k || k == 0) return 1;
    if(dp[n][k] >= 0) return dp[n][k];
    return dp[n][k] = comb(n-1,k)+comb(n-1,k-1);
}

int main() { __
    memset(dp,-1,sizeof(dp));
    int n, k;
    cin >> n >> k;

    vector<long double> v(n);
    FOR (i, 0, n)
        cin >> v[i];
    //cout << comb(3,2) << ENDL;
    FOR(i,0,n){
        //int caso1 = comb(n-2,k);
        //int caso2 = comb(n-3,k-1) * sum;
        //int caso3 = comb(n-4,k-2) * sum; (a + b ) / 
        long double ans = 0;
        long double sum = 0;
        FOR (j,0,n-k+1){
            int act = ((i-j+n)%n);
            sum+=v[act];
            //cout << comb(n-(2+j),k-j-1) << ENDL;
            ans += comb(n-j-1,k-1) / comb(n,k) * v[act];
            //cout << ans << ENDL;
        }
        cout << setprecision(12) << fixed;
        cout << ans << ' ';
    }
    cout << ENDL;
    cout << 5;
    
    /*int LIM = 1 << n;
    long double m = 0;
    vector<long double> ans(n,0);
    for (int mask = 0; mask < LIM; mask++) {
        if (__builtin_popcount(mask) != k)
            continue;
        
        m++;

        bool on[n];
        FOR (i, 0, n)
            on[i] = (mask >> i) & 1;

        vector<long double> v2(n, 0.0);
        FOR (i, 0, n) {
            if (!on[i])
                continue;
            v2[i] = v[i];
            for (int j = (i - 1 + n) % n; j != i && !on[j]; j = (j - 1 + n) % n)
                v2[i] += v[j];
        }

        FOR (i, 0, n)
            ans[i] += v2[i];
    }

    FOR (i, 0, n)
        cout << ans[i] / m << ' ';
    cout << ENDL;*/

    return 0;
}