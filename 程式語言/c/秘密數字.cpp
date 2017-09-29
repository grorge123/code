#include<stdio.h>
int main(){
	int X,i,A=0,B=0;
	scanf("%d",&X);
	while(X!=0){
		if(i%2==0){
			A=A+X%10;
			X=X/10;
//			printf("%d\n",A);
		}else{
			B=B+X%10;
			X=X/10;
//			printf("%d\n",B);
		}
	i++;
	}
//	printf("%d %d\n",A,B);
	if(A-B<0){
		printf("%d",(A-B)*-1);
	}else{
		printf("%d",A-B);
	}
}
