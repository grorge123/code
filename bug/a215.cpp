#include <stdio.h>
 int main(){
	long a,b;
	while(scanf("%lu %lu",&a,&b)==2){
		int all=0,q=0;
		for(int i=a;all<b;i++){
			all+=i;
			q++;
			
		}
		printf("%lu\n",q);
	}
}

