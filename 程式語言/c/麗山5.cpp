#include<stdio.h>
#include<cstdlib>
#include<math.h>
#include <stdlib.h>
#include<string>
#include<iostream>
using namespace std ;
int main(){
	int rate,n,ent,out,rate2;
	cout << "��J�w�g�s�X�ѿ�,��J�{�b�w�g�h�ֿ�,�Q�v" << endl;
	cin >> n >> out>>rate;
	rate2=1+rate/365;
	for(int i=0;i<rate2;i++){
		ent=ent/ent;
	}
	cout << ent;
} 
