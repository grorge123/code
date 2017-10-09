#include<stdio.h>
#include<cstdlib>
#include<math.h>
#include <stdlib.h>
#include<string>
#include<iostream>
using namespace std ;
int main(){
	char a[1000]={'0'};
	int a2[1000]={0},ans=0;
	cin.getline(a,1000);
	for(int i=0;i<1000;i++){
		a2[i]=a[i]-'0';
		if(a2[i]>10||a2[i]<0){
			a2[i]=0;
		}
//		printf("%d\n",a2[i]);
	}
	for(int i=0;i<1000;i++){
		ans=ans+a2[i];
//		printf("%d\n",ans);
	}
//	printf("%d",ans);
	if(ans%9==0){
		printf("yes");
	}else{
		printf("no");
	}
}
