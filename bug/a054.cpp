#include<stdio.h>
#include<stdlib.h>
int main(){
	char b[9];
	while(scanf("%s",b)==1){
		int all=0,q=0,c[9],blog[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
		char ch[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		for(int i=0;i<=26;i++){
			if(ch[i]==b[0]){
				all=blog[i];
				break;
			}
		}
		for (int i=0;i<9;i++){
			c[i]=b[i]-'0';
		}
		for(int i=8;i>0;i--){
			c[q]*=i;
			all+=c[q];
			q++;		
		}
		all+=c[8];
		for(int i=0;i<26;i++){
				int ans=(blog[i]%10*9)+(blog[i]/10)+all;
			if(ans%10==0){
				printf("%c",ch[i]);
			}
		}
		printf("\n");
	}
    return 0;
}
