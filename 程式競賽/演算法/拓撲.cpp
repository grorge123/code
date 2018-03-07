#include<bits/stdc++.h>
using namespace std;
struct link{
    int id=0;
    int lon=0;
};
int main(){
    int n,m;
      cin >> n>> m;//n=總共有幾個點,m=總共有幾條優先度
      int s[105][105]={},li[105]={};
      for(int i=1;i<=m;i++){
          int a,b;
          cin >> a>> b;
          s[b][a]=1;
      }
      for(int i=1;i<=n;i++){
          for(int q=1;q<=n;q++){
              if(s[i][q])
                  li[i]++;
          }
      }
      bool first=true;//uva輸出規則
      while(true){
          int con=1,fi=0;
          vector<int> sl;
          while(con<=n){
//                cout << con<<" "<<li[con]<<endl;
              if(!li[con]){
                  sl.push_back(con);
              }
              con++;
          }
          if(!sl.size())break;
          for(int i=0;i<sl.size();i++){
              if (!first)
                  putchar(' ');
              else
                  first = false;
              cout << sl[i];
              li[sl[i]]=-1;
          }
          for(int i=0;i<sl.size();i++){
              for(int q=1;q<=n;q++){
                  if(s[q][sl[i]])
                      li[q]--;
              }
          }
//            for(int q=1;q<=n;q++){
//                cout << li[q]<<" ";
//            }
//            cout <<endl;
      }
      cout << endl;
}
