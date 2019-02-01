struct Node {
	Node *par, *ch[2], *mx;
	int id, sz, rev_tag, val;
	Node(int _id = 0, int _val = 0): par(), ch(), mx(this), id(_id), sz(1), rev_tag(), val(_val) {}
};
struct Edge {
	int x, y, a, b;
	Edge() {}
	Edge(int _x, int _y, int _a, int _b): x(_x), y(_y), a(_a), b(_b) {}
	bool operator < (const Edge &rhs) const {
		return a < rhs.a;
	}
};
Node *tr[maxn];
vector<Edge> edges;
void rev(Node *o) {
	swap(o->ch[0], o->ch[1]);
	o->rev_tag ^= 1;
}
int sz(Node *o) {
	return o ? o->sz : 0;
}
void push(Node *o) {
	if (o->rev_tag) {
		for (auto ch : o->ch)
			if (ch)
				rev(ch);
		o->rev_tag ^= 1;
	}
}
void pull(Node *o) {
	o->sz = sz(o->ch[0]) + 1 + sz(o->ch[1]);
	o->mx = o;
	for (auto ch : o->ch)
		if (ch && ch->mx->val > o->mx->val)
			o->mx = ch->mx;
}
int get_ch_id(Node *p, Node *o) {
	for (int i = 0; i < 2; i++)
		if (p->ch[i] == o)
			return i;
	return -1;
}
void rotate(Node *o, int d) {
	push(o);
	push(o->ch[d]);
	Node *u = o;
	o = o->ch[d];
	Node *p = u->par;
	int t;
	if (p && (t = get_ch_id(p, u)) != -1)
		p->ch[t] = o;
	o->par = p;
	u->par = o;
	if (o->ch[d^1])
		o->ch[d^1]->par = u;
	u->ch[d] = o->ch[d^1];
	o->ch[d^1] = u;
	pull(u);
	pull(o);
}
void rotate(Node *o) {
	if (sz(o->ch[0]) > sz(o->ch[1]))
		rotate(o, 0);
	else if (sz(o->ch[0]) < sz(o->ch[1]))
		rotate(o, 1);
}
void all_push(Node *o) {
	if (o->par && get_ch_id(o->par, o) != -1)
		all_push(o->par);
	push(o);
}
void splay(Node *o) {
	all_push(o);
	Node *p;
	for (int d; (p = o->par) && (d = get_ch_id(p, o)) != -1; ) {
		rotate(p, d);
		rotate(p);
	}
}
Node* access(Node *o) {
	Node *last = 0;
	while (o) {
		splay(o);
		o->ch[1] = last;
		pull(o);
		last = o;
		o = o->par;
	}
	return last;
}
void make_root(Node *o) {
	rev(access(o));
	splay(o);
}
void link(Node *a, Node *b) {
	make_root(b);
	b->par = a;
}
void cut(Node *a, Node *b) {
	make_root(a);
	access(b);
	splay(b);
	b->ch[0] = 0;
	a->par = 0;
	pull(b);
}
Node* find_root(Node *o) {
	o = access(o);
	while (o->ch[0])
		o = o->ch[0];
	splay(o);
	return o;
}
void add_edge(int n, int i, int x, int y, int v) {
	tr[n + i] = new Node(n + i, v);
	if (find_root(tr[x]) == find_root(tr[y])) {
		make_root(tr[x]);
		access(tr[y]);
		splay(tr[x]);
		int id = tr[x]->mx->id - n;
		if (edges[id].b > v) {
			cut(tr[edges[id].x], tr[n + id]);
			cut(tr[edges[id].y], tr[n + id]);
			link(tr[x], tr[n + i]);
			link(tr[y], tr[n + i]);
		}
	} else {
		link(tr[x], tr[n + i]);
		link(tr[y], tr[n + i]);
	}
}
