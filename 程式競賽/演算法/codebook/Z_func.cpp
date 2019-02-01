void zzzzzz(){
	MS0(z);
	int l,r;
	l = 0,r = 1;
	z[0] = LE(s);
	REP1(i,1,LE(s)){
		if(i>=r || z[i-l]>=r-i){
			int x = (i>=r)?i:r;
			while(x<LE(s) && s[x] == s[x-i]) x++;
			z[i] = x-i;
			if(i<x) l=i,r=x;
		}
		else z[i] = z[i-l];
	}

}