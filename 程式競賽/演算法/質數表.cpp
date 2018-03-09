#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define MA 2000000
int s[2000005]={};
int main(){
	for(int i=2;i<=MA;i++){
		for(int q=2;q*i<=2000000;q++){
			s[i*q]=1;
		}
	}
	vector<int> ans;
	int p=1,q=200000
	;
//	cin>> p>>q;
	for(int i=p;i<=q;i++){
		if(i<2)continue;
		if(s[i]==0){
			cout << i<<" ";
			ans.push_back(i);
		}
	}
	cout << endl;
	for(vector<int>::iterator it=ans.begin();it!=ans.end();it++){
		if(*it<p)continue;
		vector<int>::iterator it2=it;
		if(*it>q)break;
		it2++;
		if(it2==ans.end())break;
		if(*it2-*it<3){
			printf("%d %d\n",*it2,*it);
		}
	}
}
