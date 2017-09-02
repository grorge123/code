#include <stdio.h>
int main()
{
 char a[5], i;
 for(i=0; i<5; i++)
   scanf("%s",&a[i]);
 for(i=4; i>=0; i--)
   printf("%s",a[i]);
}
/*#include<stdio.h>
int main(){
char a[4];
for(int i =0;i<5;i++){
	scanf("%s",&a[i]);
	
	}
for(int i=0;i<5;i++){
	printf("%s",a[i]);
	
	}
}*/
