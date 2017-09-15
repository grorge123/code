#include<stdio.h>
int a(int b,int c){
	return b+c;
}
int main(){
int d,e;
scanf("%d%d",&d,&e);
printf("%d",a(d,e));
int f=a(d,e)*2;
printf("%d",f);
}
