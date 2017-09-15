#include<stdio.h> 
# include <iostream>
using namespace std ;
int main()
{
	int a;
	printf("請輸入華氏溫度");
	scanf("%d",&a);
	printf("攝氏溫度為%d\n" ,(a-32)*5/9);
	system("PAUSE"); 
return 0; 
}
