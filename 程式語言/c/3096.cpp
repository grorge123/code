#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
    double s[3][2];
    cin >> s[0][0]>>s[0][1]>> s[1][0]>>s[1][1]>> s[2][0]>>s[2][1];
    double a=sqrt((s[0][0]-s[1][0])*(s[0][0]-s[1][0])+(s[0][1]-s[1][1])*(s[0][1]-s[1][1]));
    double b=sqrt((s[1][0]-s[2][0])*(s[1][0]-s[2][0])+(s[1][1]-s[2][1])*(s[1][1]-s[2][1]));
    double c=sqrt((s[0][0]-s[2][0])*(s[0][0]-s[2][0])+(s[0][1]-s[2][1])*(s[0][1]-s[2][1]));
    double d=(a+b+c)/2;
    printf("%.2f",sqrt(d*(d-a)*(d-b)*(d-c)));
    return 0;
}
