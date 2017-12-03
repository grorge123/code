#include <stdio.h>
 int main(){
	int a,b;
	while(scanf("%d %d",&a,&b)==2){
		int all=0,q=0;
		for(int i=a;all<b;i++){
			all+=i;
			q++;
			
		}
		printf("%d\n",q);
	}
}

