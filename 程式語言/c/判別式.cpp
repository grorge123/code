#include<math.h>
#include <cstdlib>
#include <iostream>
using namespace std;
float x1(int a,int b,int c){
	return (-c+sqrt(b))/(2*a);
}
float x2(int a,int b,int c){
	return (-c-sqrt(b))/(2*a);
}
int main(){
	float A,B,C,D;
	cout << "��JA:";
	cin >> A; 
	cout << "��JB:";
	cin >> B;
	cout << "��JC:";
	cin >> C;  
	if(B*B-4*A*C<0){
		D=(B*B-4*A*C)*-1;
		goto de;
	}else{
			D=(B*B-4*A*C);	
	}

	cout << x1(A,D,B) << ","<<x2(A,D,B);
	if(3>5){
		de:;
		cout << (-B/2*A)-sqrt(D)<<"i" << ","<<(-B/2*A)+sqrt(D)<<"i";		
	}
	
	
}
 
    
   
