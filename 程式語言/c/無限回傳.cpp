#include<stdio.h>
int a(int n){
	if (n<1000){
		return a(n);
	}
	return 0;
}
int main (){
	int s=11;
	printf("%d",a(s));
}
