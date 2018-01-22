#include <stdio.h>
#include <ctype.h>
bool isAnagram(
char str1[],char str2[]
)
{

    int t=0;
    int des[26]={},des2[26]={};
    while(str1[t]!='\0'){
        if(str1[t]!=' '){
            if(str1[t]>='a'&&str1[t]<='z'){
                des[str1[t]-'a']++;
//                printf("%d\n",str1[t]-'a');
            }else{
                des[str1[t]-'A']++;
//                printf("%d\n",str1[t]-'A');
            }
        }
        t++;
    }
    t=0;
    while(str2[t]!='\0'){
        if(str2[t]!=' '){
            if(str2[t]>='a'&&str2[t]<='z'){
                des2[str2[t]-'a']++;
//                printf("%d\n",str2[t]-'a');
            }else{
                des2[str2[t]-'A']++;
//                printf("%d\n",str2[t]-'A');
            }
        }
        t++;
    }
    for(int i=0;i<26;i++){
        if(des[i]!=des2[i])
            return false;
    }
    return true;

}
// ----------------------------------------------
int main()
{
    char str[2][21]= {};

    int t=0;
    char input;
    while((input=getchar())!='\n'){
        str[0][t]=input;
        t++;
    }
    t=0;
    while((input=getchar())!='\n'){
        str[1][t]=input;
        t++;
    }
    printf("[%s] and [%s] are %sanagrams.\n", str[0], str[1], isAnagram(str[0], str[1])?"":"not ");
    return 0;
}
