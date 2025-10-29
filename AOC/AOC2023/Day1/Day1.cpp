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

vector<string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> numbers2 = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

unordered_map<string, int> numeros = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
unordered_map<string, int> numeros2 = {{"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}};

int firstD, lastD, firstP, lastP;

vi kmpPreprocess(string &P) {   // Preprocesamiento
    int m = P.size();
    vi b(m + 1);                // b = Back table
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {                                     // Preprocesamiento de P
        while ((j >= 0) && (P[i] != P[j])) j = b[j];    // Diferente, reset j
        ++i; ++j;                                       // Igual, avanzan ambos
        b[i] = j;
    }
    return b;
}

// T = Cadena donde se busca, P = Patron a buscar
int kmpSearch(string &T, string &P) {                   // Busqueda del patron en la cadena
    vi b = kmpPreprocess(P);
    int freq = 0;
    int i = 0, j = 0;
    int n = T.size(), m = P.size();
    while (i < n) {                                     // Buscar a traves de T
        while ((j >= 0) && (T[i] != P[j])) j = b[j];    // Diferente, reset j
        ++i; ++j;                                       // Igual, avanzan ambos
        if (j == m) {                                   // Una coincidencia es encontrada
            ++freq;
            // printf("P se encuentra en el indice %d de T\n", i-j);
            int idx = i-j;
            int dig = P.length() > 1 ? numeros[P] : numeros2[P];
            if (idx < firstP)
                firstP = idx, firstD = dig;
            if (idx > lastP)
                lastP = idx, lastD = dig;

            j = b[j];                                   // Prepara j para la siguiente
        }
    }
    return freq;
}

int main() {_
    string s;
    ll sum = 0;

    while (cin>>s) {
        firstP = INT_MAX, lastP = INT_MIN;
        for (string sn : numbers) {
            kmpSearch(s, sn);
        }
        for (string sn : numbers2) {
            kmpSearch(s, sn);
        }
        deb(firstD*10 + lastD);
        sum += (firstD*10 + lastD);
    }

    cout<<sum<<ENDL;

    return 0;
}