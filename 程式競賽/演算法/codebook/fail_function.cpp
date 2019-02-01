int fail[Z];
string a,b;
void find_fail(){
	int i,last;
	fail[0] = -1;
	for(i=1;i<LE(b);i++){
		last = fail[i-1];
		while(last>0 && b[last+1]!=b[i]) last = fail[last];
		fail[i] = (b[last+1] ==b[i]?last+1:last);
	}	
}
void match(){
	int i,now;
	for(i=0,now=-1;i<LE(a);i++){
		while(now!=-1 && b[now+1]!=a[i]) now = fail[now];
		if(b[now+1] == a[i]) now++;
		if(now == LE(b)-1){
			//Match ! a[i-lenB+1 , i] = B
			now = fail[now];
		}
	}
}