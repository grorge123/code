#include<stdio.h>
int main (){
	int a;
	scanf("%d",&a);
	printf("%d",a);
	int *b=&a;
	scanf("%d",&*b);
	printf("%d\n%d",a,*b);
	
}
