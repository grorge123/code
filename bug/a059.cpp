#include <stdio.h>
#include <string.h>
#include<math.h>
int main(){
	int t,a,b;
	scanf("%d",&t);
	for(int q=0;q<t;q++){
		int all=0;
		scanf("%d",&a);
		scanf("%d",&b);
		for(int i=a;i<=b;i++){
			double as=sqrt(i);
			if(as==(int)as){
				all+=i;
			}
		}
		printf("Case %d: %d\n",q+1,all); 
	}
} 
