#include<stdio.h>
#include<stdlib.h>
int main(){
	char b[12];
	int a;
	while(scanf("%s",b)==1){
		int all=b[0]-57,q=1,c[11];
		for (int i=1;i<10;i++){
			c[i]=b[i]-'0';
		}
		all+=(all%10*9)+(all/10)-all;
		for(int i=8;i>0;i--){
			c[q]*=i;
			all+=c[q];
			q++;
		}

		all+=c[9];
		if(all%10==0){
			printf("real\n");
		}else{
			printf("fake\n");
		}	
		
	}
    return 0;
}
