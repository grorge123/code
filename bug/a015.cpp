#include<stdio.h>
#include<stdlib.h>
int main()
{

	int at[100][100]={},m,n;
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int q=0;q<n;q++){
			scanf("%d",&at[q][i]);
		}
	}
	for(int i=0;i<n;i++){
		for(int q=0;q<m;q++){
			printf("%d ",at[i][q]);
		}
			printf("\n");
	}
    return 0;
}
