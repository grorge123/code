#include<stdio.h>
int main(){
	int a,b,c,change;
	printf("請輸入3邊長:");
	scanf("%d%d%d",&a,&b,&c);
	if((a+b<c)||(a+c<b)||(b+c<a)){
		goto end;
	}
	if(a==b&&a==c){
	printf("正三角形");
	}else{
		if(a>b&&b<c&&a>c){
			change=b;
			b=c;
			c=change;
		}else{
			if(a<b&&b<c&&a>c){
			change=a;
			a=b;
			b=change;
				}else{
				if(b>c&&b>a&&c>a){
				change=a;
				a=b;
				b=c;
				c=change;
				}else{
					if(c>a&&c>b&&a>b){
						change=b;
						b=a;
						a=c;
						c=change;
					}else{
					change=a;
					a=c;
					c=change;
					}
				}
			}
		}
	}
//if((a==b&&b!=c)||(a==c&&a!=b)||(b==c&&a!=b)){
//	printf("等腰三角形");
//	goto end;
//}
if(b*b+c*c==a*a){
	printf("直角三角形");
}
if(b*b+c*c>a*a){
	printf("銳角三角形");
}
if(b*b+c*c<a*a){
	printf("鈍角三角形");
}
if(3>5){
end:;
printf("沒這三角形");
}
}


