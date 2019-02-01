#define Lp (p*2)
#define Rp (p*2+1)
#define mid (L+R)/2
int tree[4*Z],tag[4*Z];
void push(int p){
	if(tag[p]){
		tree[Lp]+=tag[p];
		tree[Rp]+=tag[p];
		tag[Lp]+=tag[p];
		tag[Rp]+=tag[p];
	}
	tag[p] = 0;
}
void pull(int p){
	tree[p] = max(tree[Lp],tree[Rp]);
}
void update(int p,int L,int R,int QL,int QR,int f){
	if( R<QL || L>QR ) return;
	if( QL<=L && R<=QR ){
		tree[p]+=f;
		tag[p]+=f;
		return ;
	}
	push(p);
	update(Lp,L,mid,QL,QR,f);
	update(Rp,mid+1,R,QL,QR,f);
	pull(p);
}