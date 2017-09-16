#include<stdio.h>
int a(int b){
	int i;
	i=b-60;
	return i;
}
int main(){
	int i,change,best,worst2=0;
	int worst=-100;
	scanf("%d",&i);
	int s[i];
	for(int d=0;d<i;d++){
		scanf("%d",&s[d]);
	}
// 5 3 9 6 
	for(int d=i;d>=0;d--){
		for(int e=0;e<=d;e++){
			if(s[e]>s[e+1]){
				change=s[e];
				s[e]=s[e+1];
				s[e+1]=change;
			}
		}
	}
	for(int d=1;d<=i;d++){
		printf("%d ",s[d]);
	}
	printf("\n");
//	for(int d=1;d<=i;d++){
//		printf("%d ",a(s[d]));
//	} 
	for(int d=1;d<=i;d++){
		if(a(s[d])>worst&&a(s[d])<0){
			worst=a(s[d]);
			worst2=s[d];
		}
		if(a(s[d])>best&&a(s[d])>0){
			best=s[d];
		}	
	}
	if(best!=0&&worst2!=0){
		printf("最幸運:%d\n最不幸運:%d",best,worst2);
	}else{
		if(best==0&&worst2!=0){
			printf("best case\n%d",worst2);
		}else{
			if(best!=0&&worst2==0){
				printf("%d\nworst case",best);
			}else{
				printf("best case\nworst case");
			}
		} 
	}
} 
