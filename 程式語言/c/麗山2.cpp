#include<stdio.h>
#include<stdlib.h>
int main (){
    int a,ans=1;
    while(a){
        scanf("%d",&a);
        if(!a){
                if(ans==1){
                    ans=0;
                }
                break;
        }
        ans=a*ans;
    }
    printf("%d",ans);
}

