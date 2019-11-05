#include<bits/stdc++.h>
using namespace std;
struct CMP{
	int len,k,*rank,a,b;
	inline bool operator()(int i,int j){
		if(rank[i]!=rank[j])return rank[i]<rank[j];
		a=(i+=k)<len?rank[i]:-1;
		b=(j+=k)<len?rank[j]:-1;
		return a<b;
	}
};
inline void suffix_array(const char *s,int len,int *sa,int *rank,int *tmp){
	for(int i=0;i<len;++i){
		sa[i]=i;
		rank[i]=s[i];
	}
	CMP cmp={len,1};
	for(;;cmp.k<<=1){
		cmp.rank=rank;
		std::sort(sa,sa+len,cmp);
		tmp[sa[0]]=0;
		for(int i=1;i<len;++i)tmp[sa[i]]=tmp[sa[i-1]]+cmp(sa[i-1],sa[i]);
		if(tmp[sa[len-1]]==len-1)break;
		std::swap(rank,tmp);
	}
}
int main(){
    char a[50];
    cin >> a;
    int sa[50]={},rank[50]={},tmp[50]={};
    suffix_array(a,strlen(a),sa,rank,tmp);
    for(int i = 0 ; i < strlen(a) ; i++){
        cout << sa[i]<<' ';
    }
    cout << endl;
    for(int i = 0 ; i < strlen(a) ; i++){
        cout << rank[i]<<' ';
    }
    return 0;
}
