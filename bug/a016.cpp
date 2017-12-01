#include<stdio.h>
#include<stdlib.h>
int main(){
	int s[9][9],t=0;
	start:;
	t=0;
	while (scanf("%d %d %d %d %d %d %d %d %d",&s[0][0],&s[0][1],&s[0][2],&s[0][3],&s[0][4],&s[0][5],&s[0][6],&s[0][7],&s[0][8])==9){

		for(int i=1;i<9;i++){
			for(int q=0;q<9;q++){
				scanf("%d",&s[i][q]);
			}
		}
		for(int i=0;i<9;i++){
			for(int q=0;q<9;q++){
				t+=s[i][q];
			}
				if(t!=45){
					printf("no\n");
					goto start;
				}
			t=0;
		}
		for(int i=0;i<9;i++){
			for(int q=0;q<9;q++){
				t+=s[q][i];
			}
				if(t!=45){
					printf("no\n");
					goto start;
				}
			t=0;
		}
			printf("yes\n");
	}

    return 0;
}
