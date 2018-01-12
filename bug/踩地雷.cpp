#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<queue>
using namespace std;
struct smap{
    int ty;
    int num;
};
smap ma[1000][1000]={};
int end=0;
void randf(int n,int m,int a){
    int i;
    unsigned seed;
    seed = (unsigned)time(NULL); // 取得時間序列
    srand(seed);
    for(i=0; i<a;i++){
        int x=rand()%n;
        int y=rand()%m;
//        cout << "x"<<x<<"y"<<y;
        if(ma[x][y].num!=-1)
            ma[x][y].num=-1;
        else
            i--;
    }
}
void tprint(int n,int m){
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(ma[i][q].num!=-1)
                cout << ma[i][q].num;
            else
                cout << "*";
        }
        cout << endl;
    }
}
void print(int n,int m){
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(ma[i][q].ty==0)
                cout << "-";
            else if(ma[i][q].ty==1)
                cout << "^";
            else
                cout << ma[i][q].num;
        }
        cout << endl;
    }
}
void gprint(int n,int m){
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(ma[i][q].num!=-1){
                if(ma[i][q].ty==0)
                    cout << "-";
                else if(ma[i][q].ty==1)
                    cout << "^";
                else
                    cout << ma[i][q].num;
            }else{
                cout << "*";
            }
        }
        cout << endl;
    }
}
void write(int n,int m){
    int fin[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{-1,0},{1,-1}};
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(ma[i][q].num!=-1){
                ma[i][q].num=0;
                for(int s=0;s<8;s++){
                    if(ma[i+fin[s][0]][q+fin[s][1]].num==-1)
                    ma[i][q].num++;
                }
            }
        }
    }
}
void whilt(int n,int m){
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            ma[i][q].ty=0;
        }
    }
}
void bfs(int x,int y,int n,int m){
    queue<smap> q;
    q.push(ma[x][y]);
//    while(q.empty!=0){
//
//    }
}
void doit(int x,int y,int z,int n,int m){
    if(z==3){
        tprint(n,m);
        return;
    }else if(z==2){
        ma[x][y].ty=1;
    }else if(z==1){
        if(ma[x][y].num==-1){
            cout << "gameover";
            gprint(n,m);
            return;
        }else if(ma[x][y].num==0){
            bfs(x,y,n,m);
        }else{
            ma[x][y].ty=2;
        }
    }else{
    cout << "無此指令";
    return;
    }
}
int main(){
    int n,m,a=1e9;
    cout << "請入長寬:";
    cin >> n>>m;
    while(a>n*m/2){
        cout << "請輸入地雷數量:";
        cin >>a ;
        if(a>n*m/2)
            cout << "地雷數需小於長乘寬除2";
    }
    cout << "遊戲初始化"<<endl;
    randf(n,m,a);
    write(n,m);
//    while(end==0){
//        print(n,m);
//        int x,y,z;
//        cout << "請輸入xy座標和執行動作1是插旗2是踩下去"
//        cin <<x<<y<<z;
//        doit(x,y,z,n,m);
//    }
    tprint(n,m);
}
