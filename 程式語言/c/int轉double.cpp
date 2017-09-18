#include<stdio.h>
double f(double x){
	return x/2;
}
int r(double x){
	return x/2;
}
int main(){
	int a=17;
	float b=a/3;
	printf("%f\n",b);//17先除3然後把小數點後去掉再轉float 
	printf("%lf\n",f(a));//17先轉double x在除2 
	printf("%d",r(a));//17先轉double x在除2,在把小數點後去掉轉int 
}
