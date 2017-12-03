#include <stdio.h>
#include <string.h>
#include<math.h>
int main(){
	int m;
	scanf("%d",&m);
	for(int ss=0;ss<m;ss++){
		long long int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		switch(a){
			case 1:
				printf("%lu\n",b+c);
				break;
			case 2:
				printf("%lu\n",b-c);
				break;
			case 3:
				printf("%lu\n",b*c);
				break;
			case 4:
				printf("%lu\n",b/c);
				break;
		}
	}
} 
