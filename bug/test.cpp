//https://zerojudge.tw/ShowProblem?problemid=d365
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
#define F first
#define S second
char s[1000][1000];
struct xy{
    int x,y;
};
bool check(xy *now,int h,int l){
    for(int i=1;i<=h;i++){
        for(int q=1;q<=l;q++){
            if(s[i][q]>='a'&&s[i][q]<='z'){
                now->x=i;
                now->y=q;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,n2;
    cin >> n;
    n2=n;
    while(n--){
        int l,h;
        memset(s,0,sizeof(s));
        queue<xy> qu;
        map<char,int> ans;
        cin >> h>>l;
        for(int i=1;i<=h;i++){
            for(int q=1;q<=l;q++){
                cin >> s[i][q];
            }
        }
        xy now;
        while(check(&now,h,l)){
            int all=0;
            char word=s[now.x][now.y];
            qu.push(now);
            while(!qu.empty()){
                int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
                xy now=qu.front();
                qu.pop();
                cout <<now.x<<" "<<now.y<<" "<<s[now.x][now.y]<<endl;
                if(s[now.x][now.y]<'a'||s[now.x][now.y]>'z')continue;
                system("pause");
                for(int i=0;i<4;i++){
                    if(s[now.x+d[i][0]][now.y+d[i][1]]==s[now.x][now.y]){
                        all++;
                        xy will;
                        will.x=now.x+d[i][0];
                        will.y=now.y+d[i][1];
                        qu.push(will);
                    }
                }
                s[now.x][now.y]='1';
            }
            if()ans.insert(pair<char,int>(word,all));
        }
        cout << "World #"<<n2-n;
        for(map<char,int>::iterator it=ans.begin();it!=ans.end();it++){
            cout <<it->F<<": "<<it->S<<endl;
        }
    }
}
