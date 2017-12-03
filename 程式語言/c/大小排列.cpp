#include <stdio.h> 
#include <conio.h> 
int main(void) 
{ 
int data[5]; 
int a,b,c; 
printf("請輸入5個數字\n"); 
printf("排序前:"); 
for(a=0;a<5;a++) 
{ 
scanf("%d",&data[a]); 
} 
for(a=5;a>=0;a--) { 
	for(b=0;b<=a;b++) { 
		if(data[b]<data[b+1]) { 
			c=data[b]; 
			data[b]=data[b+1]; 
			data[b+1]=c; 
		} 
	} 
} 
printf("排序後:"); 
for(a=0;a<5;a++) 
{ 
printf("%d ",data[a]); 
} 
printf("\n"); 
getch(); 
return 0; 
}
