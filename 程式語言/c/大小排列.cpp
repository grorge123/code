#include <stdio.h> 
#include <conio.h> 
int main(void) 
{ 
int data[5]; 
int a,b,c; 
printf("�п�J5�ӼƦr\n"); 
printf("�Ƨǫe:"); 
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
printf("�Ƨǫ�:"); 
for(a=0;a<5;a++) 
{ 
printf("%d ",data[a]); 
} 
printf("\n"); 
getch(); 
return 0; 
}
