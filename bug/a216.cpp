#include <stdio.h>
 long long int f(long long int n){
 	if(n==0)
 		return 0;
 	return n + f(n-1);
 }
 long long int g(long long int n){
 	if(n==0){
 		return 0;
	 }
	 return f(n) + g(n-1);
 }
 int main(){
	int a;
	while(scanf("%d",&a)==1){
		printf("%lu %lu\n",f(a),g(a));		
	}
}

