void dfs1(int p){
	mk[p] = 1;
	SREP(f,v[p]) if(!mk[f]) dfs1(f);
	vv.pb(p);
}
void dfs2(int p){
	mk[p] = 1;
	belong[p] = nscc;
	SREP(f,rv[p]) if(!mk[f]) dfs2(f);
}
void do_scc(){
	MS0(mk);
	REP(i,n){
		if(!mk[i]) dfs1(i);
	}
	MS0(mk);
	RREP(i,n){
		if(!mk[vv[i]]){
			nscc++;
			dfs2(vv[i]);
		}
	}
}
void two_sat(){
	// build graph
	do_scc();
	MS0(mk);
	REP(i,2*n){
		if(!mk[belong[i]]){
			mk[belong[i]] = -1;
			mk[belong[not(i)]] = -2;
		}
	}
	REP(i,n){
		if(mk[belong[i]] == -1) cout<<i<<" YES "<<endl;
		else cout<<i<<" NO "<<endl;
	}
}

void dfs1(int p){
	size[p] = 1;
	son[p] = -1;

	SREP(f,v[p]){
		if(f==fa[p][0]) continue;
		fa[f][0] = 1;
		dep[f] = dep[p] + 1;
		dfs1(f);
		size[p] += size[f];
		if(son[p] == -1 || size[f] > size[son[p]]){
			son[p] = f;
		}
	}
}
void dfs2(int p,int hd){
	head[p] = hd;
	// tl[p] = tr[p] = rr;
	tid[p] = rr++;
	tdi[tid[p]] = p;
	if(son[p] != -1) dfs2(son[p],hd);
	SREP(f,v[p]){
		if(f==fa[p][0] || f==son[p]) continue;
		dfs2(f,f);
		//tr[p] = tr[f];
	}
}
void beizeng(){
	REP1(i,1,20){
		REP(j,n){
			fa[j][i] = fa[fa[j][i-1]][i-1];
		}
	}
}
inline int lca(int a,int b){
	if(a==b) return a;
	if(dep[a] > dep[b]) swap(a,b);
	int d = dep[b] - dep[a];
	REP(i,20) if(d&(1<<i)) b = fa[b][i];
	if(a==b) return a;
	RREP(i,20) {
		if(fa[a][i] != fa[b][i]) {
			a = fa[a][i];
			b = fa[b][i]
		}
	}
	return fa[a][0];
}
inline int ask(int a,int b){
	while(head[a] != head[b]){
		if(dep[head[a]] > dep[head[b]]) swap(a,b);
		query(1,0,n-1,tid[head[b]],tid[b]);
		b = fa[0][head[b]];
	}
	if(dep[a] > dep[b]) swap(a,b);
	query(1,0,n-1,tid[a],tid[b]);
	return ??;
}
struct node{
	int last;
	node *ch[26],fail;
	vector<int> v;
	node(){
		c = _c;
		last = -1;
		fail = NULL;
		REP(i,26) ch[i] = NULL;
	}
}*root;
string s;
void insert(){
	node *p = root;
	SREP(f,s){
		// while(p != root && (!p->ch[f-'a'])) p = p->fail;
		// if(p->ch[f-'a']) p = p->ch[f-'a'];
		if(!p->ch[f-'a']) p->ch[f-'a'] = new node();
		p = p->ch[f-'a'];
	}
}
queue<node*> q;
void get_fail(){
	node *now,*f;
	f = root;
	q.push(root);
	while(!q.empty()){
		now = q.front();
		q.pop();
		REP(i,26){
			if(now->ch[i]){
				while(f!=root && (!f->ch[i])) f = f->fail;
				if(f->ch[i]) {
					f = f->ch[i];
					
				}

				q.push(now->ch[i]);
			}
		}
	}
}



PII extgcd(int a,int b){
	if(b==0) return mp(1,0);
	int p = a/b;
	PII q = extgcd(b,a%b);
	return mp(q.Y,q.X - q.Y*p);
}
stack<int> stk;
void dfs(int p){
	dfsn[p] = low[p] = ++rr;
	stk.push(p);
	SREP(f,v[p]){
		if(!dfsn[f]) {
			dfs(f);
			low[p] = min(low[p],low[f]);
		}
		else{
			low[p] = min(low[p],dfsn[f]);
		}
	}
	if(low[p] >= dfsn[p]){
		while(stk.top() != p){
			bcc[nbcc].pb(stk.top());
			stk.pop();
		}
		nbcc++;
	}
}

int crt(){
	int alln = 1;
	REP(i,n) alln *= n[i];
	REP(i,n){
		mi = alln / n[i];
		mf = extgcd(mi,n[i]).X;
		ci = mi*(mf%n[i]);
		ans+=a[i]*ci;
	}
	ans%=alln;
	if(ans==0) return alln;
	return ans;
}

void find_fail(){
	int f;
	fail[0] = -1;
	REP1(i,1,n){
		f = fail[i-1];
		while(f!=-1 && s[f+1] != s[i]) f = fail[f];
		if(s[f+1] == s[i]) f++;
		fail[i] = f;
	}
}
int match(){
	int now = -1;
	REP(i,m){
		while(now!=-1 && s[now+1] != s2[i]) now = fail[now];
		if(s2[now+1] == s2[i]) now++;
		if(now == n-1){
			//match
			now = fail[now];
		}
	}
}
inline PII operator-(const PII &a,const PII &b){
	return mp(a.X - b.X,a.Y - b.Y);
}
inline int operator^(const PII &a,const PII &b){
	return a.X * b.Y - a.Y * b.X;
}
void do_tubao(){
	int sz,fsz;
	sz = 0;
	RPE(i,n){
		while(sz>=2 || (t[sz-1]-t[sz-2])^(p[i]-t[sz-2])<=0){
			t.pop_back();
			sz--;
		}
		t.pb(p[i]);
		sz++;
	}
	fsz = sz;
	RREP(i,n){
		while(sz-fsz>1 || (t[sz-1]-t[sz-2])^(p[i]-t[sz-2])<=0){
			t.pop_back();
			sz--;
		}
		t.pb(p[i]);
		sz++;
	}
}
void turn_ruler(){
	op = 1;
	ans = dis(t[0],t[1]);
	RPE(i,LE(t)-1){
		while( ((t[i+1]-t[i])^(t[i+1]-t[op+1])) < ((t[i+1]-t[i])^(t[i+1]-t[op]))){
			op = (op+1)%(LE(t)-1)
		}
		ans = max(ans,max(dis(t[i],t[op]),dis(t[i+1],t[op])));
	}
}
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
__gnu_pbds:: priority_queue<int,cmp,pairing_heap_tag> heap;

#include <ext/rope>
using namespace __gnu_cxx;
rope<int> *rp[Z];
rp[0] = new rope(rt,rt+n);

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> TT;

int match(int i){
	REP2(j,1,n){
		if(vsy[j]) continue;
		if(g[i][j]){
			mk[j] = 1;
			if(!Left[j] || match(Left[j])){
				Left[j] = i;
				return 1;
			}
		}
	}
	return 0;
}
void hungry(){
	REP2(i,1,n){
		if(match(i)) ans++;
	}
	cout<<ans<<endl;
}


int match(int i){
	vsx[i] = 0;
	REP2(j,1,n){
		if(vsy[j]) continue;
		if(w[i][j] == lx[i] + ly[j]){
			vsy[j] = 1;
			if(!Left[j] || match(Left[j])){
				Left[j] = i;
				return 1;
			}
		}
		else tarsh[j] = min(tarsh[j],-w[i][j]+lx[i]+ly[j])
	}
	return 0;
}
void update(){
	int a = INF;
	REP2(i,1,n) if(!vsy[i]) a = min(a,tarsh[i]);
	REP2(i,1,n){
		if(vsx[i]) lx[i] -= a;
		if(vsy[i]) ly[i] += a;
	}
}
void km(){
	REP2(i,1,n){
		lx[i] = ly[i] = 0;
		REP2(j,1,n) lx[i] = max(lx[i],w[i][j]);
	}
	REP2(i,1,n){
		MSF(tarsh);
		while(1){
			MS0(vsx);
			MS0(vsy);
			if(match(i)) break;
			else update();
		}
	}
}
REP(i,Z) magic[i] = i;
REP1(i,1,Z) for(int j=i*2;j<Z;j+=i) magic[j] -= magic[i];

MS0(magic2);
magic2[1] = 1;
REP1(i,1,Z) for(int j=i*2;j<Z;j+=i) magic2[j] -= magic2[i];

void mat_mul(int a[Z][Z],int b[Z][Z],int c[Z][Z]){
	REP(i,Z) REP(j,Z) tmp[i][j] = 0;
	REP(i,Z) REP(j,Z) REP(k,Z) tmp[i][j] += a[i][k] * b[k][j];
	REP(i,Z) REP(j,Z) c[i][j] = tmp[i][j];
}
void mat_mul2(int a[Z],int b[Z][Z],int c[Z]){
	REP(i,Z) tmp2[i] = 0;
	REP(i,Z) REP(j,Z) tmp2[i] += a[j] * b[i][j];
	REP(i,Z) c[i] = tmp2[i];
}

inline unsigned myran(){
	static unsigned _x = 20170421;
	return _x = _x*0xdefaced +1;
}
ll mymul(ll a,ll b,ll m){
	return a*b%m;
}
ll mypow(ll a,ll b,ll m){
	if(b==0) return 1;
	if(b==1) return a%m;
	ll f = mypow(a,b/2,m);
	f = mymul(f,f,m);
	if(b&1) f = mymul(f,a,m);
	return f;
}
int miller_rabin(ll n,int s=10){
	if(n<2) return 0;
	if(!(n&1)) return (n==2);
	int m,b,j;
	m = n-1;
	j = 0;
	while(!(m&1)){
		m>>=1;
		j++;
	}
	REP(i,s){
		b = myran()%(n-1) +1 ;
		b = mypow(b,m,n);
		if(b==1) continue;
		REP(k,j+1){
			if(k==j) return 0;
			if(b==n-1) break;
			b = mymul(b,b,n);
		}
	}
	return 1;
}
void zzzzz(){
	MS0(z);
	int l=0,r=1;
	z[0] = LE(s);
	REP1(i,1,LE(s)){
		if(i>=r || z[i-l] >= r-i){
			x = max(i,r);
			while(x<LE(s) && s[x] == s[x-i] ) x++;
			z[i] = x-i;
			if(i<x) l=i,r=x;
		}
		else z[i] = z[i-l];
	}
}

node* merge(node *a,node *b){
	if(!a || !b) return a?a:b;
	if(a->pri > b->pri){
		push(a);
		a->r = merge(a->r,b);
		pull(a);
		return a;
	}
	else{
		push(b);
		b->l = merge(a,b->l);
		pull(b);
		return b;
	}
}
void split(node *t,node *&a,node *&b,int k){
	if(!t){
		a = b = NULL;
		return ;
	}
	if(size(t->l) +1 <=k){
		a = t;
		split(t->r,a->r,b,k-size(t->l)-1);
		pull(a);
	}
	else{
		b = t;
		split(t->l,a,b->l,k);
		pull(b);
	}
}

void do_sa(){
	m = 'z'+1;
	REP(i,m) c[i] = 0;
	REP(i,n) c[x[i] = s[i]]++;
	REP1(i,1,m) c[i] += c[i-1];
	RREP(i,n) sa[--c[x[i]]] = i;
	for(int k=1;k<=n;k<<=1){
		int p=0;
		REP1(i,n-k,n) y[p++] = i;
		REP(i,n) if(sa[i]>=k) y[p++] = sa[i]-k;

		REP(i,m) c[i] = 0;
		REP(i,n) c[x[y[i]]]++;
		REP1(i,1,m) c[i] += c[i-1];
		RREP(i,n) sa[--c[x[y[i]]]] = y[i];	
		swap(x,y);
		x[sa[0]] = 0;
		p = 1;
		REP1(i,1,n) x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k]?p-1:p++);
	}
}
void do_lcp(){
	int h=0;
	REP(i,n) rk[sa[i]] = i;
	REP(i,n){
		if(rk[i] == 0){
			lcp[rk[i]] = 0;
			continue;
		}
		if(h) h--;
		f = sa[rk[i]-1];
		while(f<n && s[f+h] == s[i+h]){
			h++;
		}
		lcp[rk[i]] = h;
	}
}
void upd(int x,int v){
	for(;x<Z;x+=x&-x) bit[x]+=v;
}
int qry(int x){
	int k=0;
	for(;x>0 ;x-=x&-x) k+=bit[x];
	return x;
}

