struct Node {
	int fail, ch[26], len;
	long long dp;
	Node(): fail(), ch(), len(), dp() {}
};
char s[maxn + 1];
Node mem[maxn + 2];
int pmem, last;
int new_node() {
	int id = pmem++;
	mem[id] = Node();
	return id;
}
void init() {
	pmem = 0;
	int a = new_node(), b = new_node();
	mem[a].fail = b;
	mem[b].len = -1;
	last = b;
}
void insert(int i, int c) {
	c -= 'a';
	int p = last, np;
	while (s[i - mem[p].len - 1] != s[i])
		p = mem[p].fail;
	if (!mem[p].ch[c]) {
		np = new_node();
		mem[np].len = mem[p].len + 2;
		int q = mem[p].fail;
		while (s[i - mem[q].len - 1] != s[i])
			q = mem[q].fail;
		mem[np].fail = mem[q].ch[c];
		mem[p].ch[c] = np;
	}
	else np = mem[p].ch[c];
	mem[np].dp++;
	last = np;
}
