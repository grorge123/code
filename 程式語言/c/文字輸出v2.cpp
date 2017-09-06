#include <stdio.h>
int main(){
char a[10];
int i=0;
while(i<5){
	scanf("%c/n",&a[i]);
	i=i+1;
	scanf("%c/n",&a[i+1]);
	printf("%d",i);
	}
i=0;
while(i<5){
	printf("%c\n",a[i]);
	printf("%c\n",a[i+1]);
	i=i+1;
	
	}
}
