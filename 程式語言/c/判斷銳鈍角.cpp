#include<stdio.h>
int main(){
	int a,b,c;
	printf("�п�J3�ӫ׼�");
	scanf("%d%d%d",&a,&b,&c);
	if(a+b+c!=180){
		goto end;
	}
	if(a==90||b==90||c==90){
		printf("�����T����");
	}else{	
	if(a>90||b>90||c>90){
		printf("�w���T����");
	}else{
		printf("�U���T����");
	}
	}
if(5<3){
end:;
printf("�S�o�T����");
}

}
