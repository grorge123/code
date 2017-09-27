#include<stdio.h>
int main(){
	int a,b,c;
	printf("請輸入角度大小");
	scanf("%d%d%d",&a,&b,&c);
	if(a+b+c!=180){
		goto end;
	}
	if(a==90||b==90||c==90){
		printf("正三角形");
	}else{
	if(a>90||b>90||c>90){
		printf("鈍角三角形");
	}else{
		printf("銳角三角形");
	}
	}
if(5<3){
end:;
printf("沒這三角形");
}

}
