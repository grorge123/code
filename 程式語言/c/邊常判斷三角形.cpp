#include<stdio.h>
int main(){
	int a,b,c,change;
	printf("�п�J3���:");
	scanf("%d%d%d",&a,&b,&c);
	if((a+b<c)||(a+c<b)||(b+c<a)){
		goto end;
	}
	if(a==b&&a==c){
	printf("���T����");
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
//	printf("���y�T����");
//	goto end;
//}
if(b*b+c*c==a*a){
	printf("�����T����");
}
if(b*b+c*c>a*a){
	printf("�U���T����");
}
if(b*b+c*c<a*a){
	printf("�w���T����");
}
if(3>5){
end:;
printf("�S�o�T����");
}
}


