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
	printf("%f\n",b);//17����3�M���p���I��h���A��float 
	printf("%lf\n",f(a));//17����double x�b��2 
	printf("%d",r(a));//17����double x�b��2,�b��p���I��h����int 
}
