#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random_int() {
  return uniform_int_distribution<int>(0, int(1e9))(rng);
}

vector<int> a;

struct Node {
  Node *l, *r;
  int data, priority, size;
  ll sum, lazy;
  bool rev;
  Node(int data) : l(NULL), r(NULL), data(data), priority(random_int()), size(1), sum(a[data]), lazy(0), rev(false) {}
};

ll sum(Node* n) {
  return n ? n->sum : 0;
}
int size(Node* n) {
  return n ? n->size : 0;
}
void recalc(Node* n) {
  n->size = size(n->l) + size(n->r) + 1;
  n->sum = sum(n->l) + sum(n->r) + a[n->data];
}

void apply_rev(Node* n) {
  if (n) {
    n->rev ^= 1;
    swap(n->l, n->r);
  }
}

void apply_lazy(Node* n, int lazy) {
  if (n) {
    n->lazy += lazy;
    n->sum += lazy * n->size;
  }
}

void push(Node* n) {
  if (n->rev) {
    apply_rev(n->l);
    apply_rev(n->r);
    n->rev = false;
  }
  if (n->lazy) {
    apply_lazy(n->l, n->lazy);
    apply_lazy(n->r, n->lazy);
    n->lazy = 0;
  }
}

pair<Node*, Node*> split(Node* n, int k) {
  if (!n) {
    return {NULL, NULL};
  }
  push(n);
  if (size(n->l) >= k) {
    auto [L, R] = split(n->l, k);
    n->l = R;
    recalc(n);
    return {L, n};
  }
  else {
    auto [L, R] = split(n->r, k - size(n->l) - 1);
    n->r = L;
    recalc(n);
    return {n, R};
  }
}

Node* merge(Node* l, Node* r) {
  if (!l) {
    return r;
  }
  if (!r) {
    return l;
  }
  push(l);
  push(r);
  if (l->priority > r->priority) {
    l->r = merge(l->r, r);
    recalc(l);
    return l;
  }
  else {
    r->l = merge(l, r->l);
    recalc(r);
    return r;
  }
}

void reverse(Node*& n, int l, int r) {
  Node *a, *b, *c;
  tie(a, b) = split(n, l);
  tie(b, c) = split(b, r - l);
  apply_rev(b);
  n = merge(merge(a, b), c);
}

void update(Node*& n, int l, int r, int val) {
  Node *a, *b, *c;
  tie(a, b) = split(n, l);
  tie(b, c) = split(b, r - l);
  apply_lazy(b, val);
  n = merge(merge(a, b), c);
}

ll sum(Node*& n, int l, int r) {
  Node *a, *b, *c;
  tie(a, b) = split(n, l);
  tie(b, c) = split(b, r - l);
  ll ans = sum(b);
  n = merge(merge(a, b), c);
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  Node* treap = NULL;
  for (int i = 0; i < n; i++) {
    treap = merge(treap, new Node(i));
  }

  while (m--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      reverse(treap, l - 1, r);
    }
    else {
      cout << sum(treap, l - 1, r) << '\n';
    }
  }
  
  return 0;
}