#include<cstdlib>
#include<string>
#include<stdio.h>
#include <iostream>
using namespace std;
int main( )
{
int A=0,B=0,i2[1000],con=-1;
char i[1000];
for(int q=0;q<1000;q++){
	i[q]='0';
	i2[q]=0;
}
//cin.getline(i,1000);
do{
	con++;
	scanf("%c",&i[con]);
}while(i[con]!= '\n');
i[con]='\0';
for(int q=0;q<1000;q++){
	i2[q]=i[q]-'0';
//	cout <<i2[q] <<endl;
}
for(int q=0;q<1000;q++){
	if(i2[q]==-48)
	i2[q]=i2[q+48];
	A=A+i2[q];
	q++;
//	cout << A << " ";
	if(i2[q]==-48)
	i2[q]=i2[q+48];
	B=B+i2[q];
//	cout << B << endl;
}
cout << abs(A-B);
}
