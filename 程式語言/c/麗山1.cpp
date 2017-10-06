#include<stdio.h>
#include<stdlib.h>
int main (){
	int s1,s2,s3,time;
	float money;
	printf("請輸入起始時間和結束時間");
	scanf("%d %d",&s1,&s2);
	if(s1>1200){s1=2400-s1;}
	if(s2>1200){s2=2400-s2;}
	time=s1+s2;
//printf("%d\n",time);
	if(time>100){
    time=(time%100)+((time/100)*60);
}
//printf("%d\n",time);
    if(time%5!=0){
        money=((time/5)+1)*1.7;
    }else{
        money=(time/5)*1.7;
    }
	if(s1>=1800||s1<800){
        money=money-(money*0.5);
	}
	money=money+(money*0.4);
	if(time>=60){
        money=money-(money*0.15);
	}
	printf("%f",money);
}

