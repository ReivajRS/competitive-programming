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

pair<string, vi> unfold(string &record, vi &groups, int factor) {
    string s = "";
    vi newGroups;
    for (int i = 0; i < factor; i++) {
        s += record;
        if (i < factor-1)
            s += "?";
        for (auto &x : groups)
            newGroups.push_back(x);
    }

    return {s, newGroups};
}

map<pair<string, vi>, ll> memo;

ll solve(string record, vi groups) {
    pair<string, vi> input(record, groups);
    if (memo.count(input))
        return memo[input];
    
    // Si el record esta vacio y no hay grupos, es una permutacion valida
    if (input.first.empty())
        return input.second.empty();
    
    // Si el primer caracter es un '.', se salta y se continua con los mismos grupos
    if (input.first[0] == '.')
        return memo[input] = solve(record.substr(1), groups);
    
    // Si el primer caracter es un '?', hay 2 posibilidades. Que sea un '.' y continuar con los mismos grupos
    // o que sea un '#' y continuar con los mismos grupos
    if (input.first[0] == '?')
        return memo[input] = solve("." + record.substr(1), groups) + solve("#" + record.substr(1), groups);

    // Si ya no hay grupos y es un '#', es invalido
    if (groups.empty())
        return memo[input] = 0;

    // Numero de resortes dañados del grupo actual
    int numDamaged = groups[0];

    // Si el numero de resortes dañados es menor o igual a la longitud del record y ademas
    // en los siguientes numDamaged caracteres hay solo '#' o '?'
    if (numDamaged <= record.length() && checkRemaining(record, numDamaged)) {
        vi newGroups = subList(groups, 1, groups.size());
        // Si numDamaged es igual al record, se retorna 1 en caso de que este sea el ultimo grupo
        if (numDamaged == record.length())
            return memo[input] = newGroups.empty();
        // Si record[numDamaged] es igual a '.', significa que se toman todos los caracteres hasta esa
        // posicion como resortes dañados y se continua despues del '.' con los grupos restantes
        if (record[numDamaged] == '.')
            return memo[input] = solve(record.substr(numDamaged + 1), newGroups);
        // Si record[numDamaged] es igual a '?', significa que se toma como '.' el caracter actual y se continua
        // despues del '.' con los grupos restantes
        if (record[numDamaged] == '?')
            return memo[input] = solve("." + record.substr(numDamaged + 1), newGroups);
        // Se acaba de completar un grupo de resortes dañados, pero el siguiente tambien lo es. No es valido
        return memo[input] = 0;
    }

    // numDamaged es mayor que la longitud del record o hay puntos en el mismo, lo cual es invalido
    return memo[input] = 0;
}

// Source: https://github.com/ash42/adventofcode/blob/main/adventofcode2023/src/nl/michielgraat/adventofcode2023/day12/Day12.java

int main(){_
    string record, snums;

    ll sum = 0;

    while(cin>>record>>snums) {
        vi groups;
        vector<string> sp = split(snums, ",");
        for (string &s : sp)
            groups.push_back(stoi(s));
        
        auto [s, newGroups] = unfold(record, groups, 5);

        sum += solve(s, newGroups);
    }

    cout<<sum<<ENDL;

    return 0;
}