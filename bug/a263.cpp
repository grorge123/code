#include <stdio.h>
#include <string.h>
#include<math.h>
int abs(int a){
	if(a>0)
		return a;
	return a*-1;
}
int main(){
	int a,b,n,a2,b2,n2;
	while(scanf("%d %d %d %d %d %d",&a,&b,&n,&a2,&b2,&n2)==6){
		int all=0;
		all+=abs((a-a2)*365);
		all+=abs((b-b2)*7);
		all+=abs((n-n2));
		printf("%d\n",all);
	}
} 
