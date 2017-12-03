#include <stdio.h>
#include <string.h>
int main(){
	char a[1000]={};
	start:;
	while(scanf("%s",a)==1){
		int change,cont=0;
		for(int i=0;i<strlen(a);i++){
			if(a[i]>122||(a[i]<97&&a[i]>90)||a[i]<65){
				a[i]=0;
				cont++;
			}
		}
		for(int i=0;i<strlen(a);i++){
			for(int q=0;q<strlen(a)-1;q++){
				if(a[q]==0){
					change=a[q];
					a[q]=a[q+1];
					a[q+1]=change;
				}
			}
		}
		for(int i=0;i<strlen(a);i++){
			if(a[i]>=97)
				a[i]-=32;
		}
		for(int i=0;i<strlen(a);i++){
			for(int q=0;q<strlen(a)-1;q++){
				if(a[q]>a[q+1]){
					change=a[q];
					a[q]=a[q+1];
					a[q+1]=change;
				}
			}
		}
		int b=(strlen(a)-cont),cc=0;
		if(b%2!=0){
			cc=1;
		}
		for(int i=0;i<b;i+=2){
			if(a[i]!=a[i+1]){
				if(cc==0){
					printf("no...\n");
					goto start;
				}
				cc--;
				i++;
			}
		}
		printf("yes !\n");
	}
}
