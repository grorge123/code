#include<stdio.h>
int main(){
	int s,m,n,maxans,con=0;
	scanf("%d %d",&n,&m);
	int t[n][m]={0},max[n]={0};
	for(int i=0;i<n;i++){
		for(int i2=0;i2<m;i2++){
		scanf("%d",&t[i][i2]);
//printf("OKi=%d i2=%d\n",i,i2);
//printf("%d\n",t[i][i2]);
		}
	}
	for(int i=0;i<n;i++){
		for(int i2=0;i2<m;i2++)
		if(t[i][i2]>max[i])
		max[i]=t[i][i2];
	}
	for(int i=0;i<n;i++){
		maxans+=max[i];
	}
	printf("%d\n",maxans);
	for(int i=0;i<n;i++){
		if(maxans%max[i]==0){
			printf("%d ",max[i]);
			con++;
		}
	}	
	if(con==0){
		printf("-1");
	}

}
