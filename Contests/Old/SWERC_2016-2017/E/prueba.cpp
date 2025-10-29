#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(nullptr);

struct vertex {
	map<char,int> next,go;
	int p,link;
	char pch;
	vector<int> leaf;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.push_back(vertex());
}
void add_string(string s, int id){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.push_back(vertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.push_back(id);
}
int go(int v, char c);
int get_link(int v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
int go(int v, char c){
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}

signed main() { __

    aho_init();
    add_string("carlos",1);
    add_string("olan",2);
    add_string("an",4);
    add_string("javier",3);
    int estado = 0;
    //estado = go(estado,'o');
    //cout << estado << " " << get_link(estado) << ENDL;
    estado = go(estado,'l');
    cout << estado << " " << get_link(estado) << ENDL;
    estado = go(estado,'a');
    cout << estado << " " << get_link(estado) << ENDL;
    estado = go(estado,'n');
    cout << estado << " " << get_link(estado) << ENDL;

    for(auto x:t[estado].leaf){
        cout << x << ENDL;
    }
    estado = get_link(estado);
     for(auto x:t[estado].leaf){
        cout << x << ENDL;
    }

    estado = get_link(estado);
    cout << estado << ENDL;

    return 0;
}