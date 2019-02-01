const ll mod = 1e9+7;
ll mei[500005];
void init(){
	int i;
	mei[0] = 1;
	for(i=1;i<=500000;i++) 
		mei[i] = (mei[i-1]*123457)%mod;
}
string s;
int Len;
void read(){
	cin>>s;
	Len = LE(s);
}
ll hh[500005],rh[500005];
void do_hash(){
	int i;
	hh[0] = s[0];
	for(i=1;i<Len;i++)
		hh[i] = (hh[i-1]*123457 + s[i]) % mod;
	rh[Len-1] = s[Len-1];
	for(i=Len-2;i>=0;i--)
		rh[i] = (rh[i+1]*123457 + s[i]) % mod;
}
inline ll chk(int L, int R){
	if(L==0) return hh[R];
	else return (hh[R]-hh[L-1]*mei[R-L+1]+mod)%mod;
}
inline ll rchk(int L,int R){
	if(R==Len-1) return rh[L];
	else return (rh[L]-rh[R+1]*mei[R-L+1]+mod)%mod;
}
inline int is_pal(int L,int R){
	return ( chk( L , R ) == rchk( L , R) );
}
void solve(){
	int i,ans,lim,j;
	do_hash();
	for(i=ans=0;i<Len;i++){
		lim=min( i , Len-1-i );
		for(j=ans/2 ; j<=lim ; j++){
			if(is_pal(i-j,i+j)) ans=j*2+1;
			else break;
		}
	}
	for(i=0;i<Len-1;i++){
		if(s[i] == s[i+1]){
			lim=min(i,Len-1-i-1);
			for(j=ans/2;j<=lim;j++){
				if(is_pal(i-j,i+1+j)) ans=j*2+2;
				else break;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int nn=1;
	nn=rit();
	init();
	while(nn--){
		read();
		solve();
	}
	return 0;
}